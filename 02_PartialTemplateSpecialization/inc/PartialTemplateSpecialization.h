#pragma once

#include <iostream>

namespace techniques
{

    template<typename T>
    bool compare(const T&& p1, const T&& p2)
    {
        std::cout << "using template" << std::endl;
        return p1 > p2 ? true : false;
    };
    // explicit template specialization
    template<> // indicate specialization with empty angle brackets
    bool compare(const int&& p1, const int&& p2)
    {
        std::cout << "using specialized template for integers" << std::endl;
        return p1 > p2 ? true : false;
    };

    // explicit template specialization
    template<> // indicate specialization with empty angle brackets
    bool compare(const double&& p1, const double&& p2)
    {
        std::cout << "using specialized template for doubles" << std::endl;
        return p1 > p2 ? true : false;
    };
}