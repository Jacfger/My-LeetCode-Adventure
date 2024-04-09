#ifndef __HELPER_H__
#define __HELPER_H__

#include <iostream>
#include <vector>
#include <ranges>


template<std::ranges::range T>
void _print(T const& iteratable) {
    for (auto const& i : iteratable) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void _print(T const& variable) {
    std::cout << variable << std::endl;
}

#endif