#ifndef __HELPER_H__
#define __HELPER_H__

#include <algorithm>
#include <iostream>
#include <vector>
#include <ranges>
using namespace std;

template <std::ranges::range T>
void _print(T const &, char='\n');

template <typename T>
void _print(T const &, char='\n');

template <std::ranges::range T>
void _print(T const &iteratable, char end)
{
    std::cout << '{';
    for (auto it = iteratable.begin(); it != iteratable.end(); ++it)
    {
        if (it != iteratable.begin())
        {
            std::cout << ", ";
        }
        _print(*it, 0);
    }
    std::cout << '}';
    if (end == '\n')
    {
        std::cout << std::endl;
    }
    else
    {
        std::cout << end;
    }
}

template <typename T>
void _print(T const &variable, char end)
{
    std::cout << variable;
    if (end == '\n')
    {
        std::cout << std::endl;
    }
    else
    {
        std::cout << end;
    }
}

#endif