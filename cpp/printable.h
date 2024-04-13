#ifndef PRINTABLE_H
#define PRINTABLE_H
#include <iostream>
#include <tuple>
#include <type_traits>

struct print_options {
    char sep = ',';
    char end = '\n';
    bool flush = false;
};

// Can't print a print_options directly, must use a wrapper
std::ostream& operator<<(std::ostream&, print_options const&) = delete;

// a wrapper class that allows a print_options type to be printed
struct treat_as_printable {
    explicit treat_as_printable(print_options const& po) : po(po) {}

    print_options const& po;
};

std::ostream& operator<<(std::ostream& os, treat_as_printable const& p) {
    os << "{ .sep: chr(" << static_cast<int>(p.po.sep) << "), .end: chr("
       << static_cast<int>(p.po.end) << "), flush: " << std::boolalpha
       << p.po.flush << " }";
    return os;
}

namespace detail {
// detects if a type T is a print_options type
template <typename T>
struct is_print_options
    : std::bool_constant<std::is_same_v<print_options, std::remove_cv_t<T>>> {};

template <typename T>
inline constexpr bool is_print_options_v = is_print_options<T>::value;

// C++ kludge(ry?)
// calls a function F with N arguments, where each argument is a compile-time
// constant in increasing order i.e. if N were 3, f(integral_constant<size_t,
// 0>(), integral_constant<size_t, 1>(), integral_constant<size_t, 2>()) would
// be invoked. The constant values are used to call std::get on a tuple, which
// requires a compile time constant (i.e. std::get<0>(tuple),
// std::get<2>(tuple), etc.) Reference:
// https://stackoverflow.com/questions/51993926/remove-last-item-from-function-parameter-pack
template <typename F, size_t... Is>
auto indices_impl(F f, std::index_sequence<Is...>) {
    return f(std::integral_constant<size_t, Is>()...);
}

template <size_t N, typename F>
auto indices(F f) {
    return indices_impl(f, std::make_index_sequence<N>());
}

// the guts of the operation; note the options type is the first arg here
template <typename First, typename... Rest>
void print_impl(print_options const& options, First const& f,
                Rest const&... r) {
    // print first arg, sans separator
    std::cout << f;

    // print the rest of the args with a separator
    ((std::cout << options.sep << r), ...);

    // print the end of line char
    std::cout << options.end;

    // don't forget to rinse
    if (options.flush) {
        std::flush(std::cout);
    }
}
}  // namespace detail

// prints a list of args. if the last argument is a print_options type
// it uses that for the options; otherwise it uses the default options
template <typename... Args>
// requires (sizeof...(Args) > 0)
void print(Args const&... args) {
    // using a tuple, we can gather info about the args
    using args_type = std::tuple<Args...>;
    constexpr auto args_count = std::tuple_size_v<args_type>;

    if constexpr (args_count > 0) {
        using last_arg_type = std::tuple_element_t<args_count - 1, args_type>;
        constexpr auto last_arg_index = args_count - 1;
        constexpr auto last_arg_is_options =
            detail::is_print_options_v<last_arg_type>;

        // if the last isn't an options type, use the default options
        if constexpr (!last_arg_is_options) {
            detail::print_impl(print_options{}, args...);
        }
        // if the last is an options type, we need at least one other arg before
        // it
        else if constexpr (last_arg_is_options && args_count > 1) {
            auto tuple = std::make_tuple(args...);

            // need to generate compile-time constants for each index of the
            // tuple, minus the last one, which we know is options. These
            // constants are passed to the lambda, which can then be used by
            // std::get
            detail::indices<args_count - 1>([&](auto... Is) {
                // the last arg becomes the first arg passed to print_impl
                // the other args (first through second last) are passed after
                // it
                //
                // i.e. if you called print(a, b, c, d), where d is a
                // print_options, the args are passed as print_impl(d, a, b, c);
                detail::print_impl(std::get<last_arg_index>(tuple),
                                   std::get<Is>(tuple)...);
            });
        }
    }
}

int main() {
    // NOTE: requires c++20 for designated initializers, which are great
    // for 'options' types

    // prints nothing (you could prevent this if need be)
    print();

    // prints a single value using default options
    print(24);

    // prints nothing (you could prevent this if need be)
    print(print_options{.sep = '|'});

    // prints multiple values using default options
    print(9, "hi there", 2.4f);

    // prints multiple values using custom options
    print(9, "hi there", 2.4f, print_options{.sep = '|'});

    // fails to print because print_options must be the last arg
    // print(print_options{ .sep = '|' }, 9, "hi there", 2.4f);

    // if you need to print a print_options object, wrap it
    // with treat_as_printable
    print_options o{.sep = '|', .end = '#', .flush = true};

    // prints multiple values using default options
    print(3, 6, treat_as_printable{o});

    // prints multiple values using custom options
    print(3, 6, treat_as_printable{o}, o);
}

#endif