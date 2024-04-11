#ifndef __HELPER_H__
#define __HELPER_H__

#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <vector>

template <typename T>
void _print(T const &variable) {
    std::cout << variable;
}

template <std::size_t N>
void _print(char const (&variable)[N]) {
    std::cout << variable;
}

template <std::ranges::range T>
void _print(T const &iteratable) {
    std::cout << '{';
    for (auto it = iteratable.begin(); it != iteratable.end(); ++it) {
        if (it != iteratable.begin()) {
            std::cout << ", ";
        }
        _print(*it);
    }
    std::cout << '}';
}

// template <std::ranges::range T>
// auto operator<<(std::ostream &stream, T const &c) {
//     return stream << "int container\n";
// }
template <std::size_t N = 2, std::size_t M = 2>
struct print_options {
    constexpr print_options(const char (&_sep)[N], const char (&_end)[M]) {
        std::copy(_sep, _sep + N, sep);
        std::copy(_end, _end + M, end);
    }
    char sep[N];
    char end[M];
};

// template <typename... Args>
// auto print(const Args &...args) {
//     // lambda used as decorator to add a space
//     // expands to ( ( ( std::cout << v1 ) << v2 ) << ... )
//     (std::cout << ... << [&](const auto &ref) -> char {
//         std::cout << ref;
//         return ' ';
//     }(args))
//         << '\n';
// }
// template <size_t N, typename... U>
// void print_with_sep(const char (&sep), U &&...args) {
//     (std::cout << ... << (o.sep, _print(args)));
// }

template <print_options o = print_options{"a", "\n"}, typename T, typename... U>
void print(const T &first, const U &...rest) {
    _print(first);
    // (std::cout << o.sep << rest, ...);
    (std::cout << ... << (o.sep, _print(rest)));
    // (std::cout << ... << [&](const auto &s) {
    //     _print(s);
    //     return o.sep;
    // }(rest));
    std::cout << o.end;
}

using namespace std;
#endif