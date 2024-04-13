#ifndef __HELPER_H__
#define __HELPER_H__

#include <algorithm>
#include <iostream>
#include <queue>
#include <ranges>
#include <unordered_map>
#include <vector>
#include <span>
#include <stack>

#include "fmt/core.h"
#include "fmt/ranges.h"
#include "fmt/ostream.h"

template <std::size_t N, std::size_t M>
struct print_options {
    constexpr print_options(const char (&_sep)[N], const char (&_end)[M]) {
        std::copy(_sep, _sep + N, sep);
        std::copy(_end, _end + M, end);
    }
    char sep[N];
    char end[M];
};

template <print_options opts = print_options{" ", "\n"}, typename T,
          typename... U>
void print(const T& first, const U&... rest) {
    fmt::print("{}", first);
    (fmt::print("{}{}", opts.sep, rest), ...);
    fmt::print("{}", opts.end);
}

using namespace std;
#endif