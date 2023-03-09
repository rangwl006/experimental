//
// Created by Russell Ang on 4/3/23.
//

#include <iostream>
#include <cmath>
#include <array>

/*
 * wrap the std::pow function in a constexpr wrapper to get it to return the appropriate value at compile time
 */
constexpr int pow(int a, int b) noexcept
{
    return (b == 0 ? 1 : std::pow(a,b));
}

struct Point
{
    constexpr Point(int init_x = 0, int init_y = 0) noexcept: x(init_x), y(init_y) {};
    constexpr int getX() const noexcept { return x; };
    constexpr int getY() const noexcept { return y; };

    int x;
    int y;
};

int main()
{
    // constexpr indicates that a value is constant AND known at compile time
    const int size = 2; // non-constexpr variable

    constexpr auto arraySize1 = size;
    std::cout << arraySize1 << std::endl;

    std::array<int, pow(3, size)> arr; // needs to know value at compile time, hence constexpr
    int arr_raw[pow(3,size)] {}; // needs to know value at compile time, hence constexpr
    return 0;
}