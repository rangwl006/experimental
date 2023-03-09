//
// Created by Russell Ang on 5/3/23.
//

#include <thread>
#include <iostream>
#include <future>

//int execute_async()
//{
//    return 5;
//}

int main()
{
    auto x = std::async(std::launch::async, [](){ return 5; });
    std::cout << x.get() << std::endl;
    return 0;
};