#pragma once

#include <iostream>

namespace design::policy
{
    template<class T>
    struct NoChecking
    {
        static void Check(T*) {};
    };

    template<typename T>
    struct EnforceNotNull
    {
        class NullPointerException : public std::exception
        {
            public:
            
                NullPointerException() { std::cout << "Null pointer found" << std::endl; };
                ~NullPointerException() = default;
        };

        static void Check(T* ptr)
        {
            if (!ptr) throw NullPointerException();
        }
    };
}