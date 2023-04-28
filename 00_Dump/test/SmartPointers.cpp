#include <memory>
#include <iostream>

namespace unique
{
    struct Foo
    {
        Foo() { std::cout  << "created Foo(" << this << ")" << std::endl; };
        ~Foo() { std::cout << "deleted Foo(" << this << ")" << std::endl; };

        Foo(int x):var(x) { std::cout  << "created Foo(" << this << ")" << "with var=" << var << std::endl; };

        int var;
    };

    template<typename T>
    struct FooDeleter
    {
        void operator()() { std::cout << "FooDeleter()" << std::endl; };
    };

    void make_unique_test()
    {
//        auto f1 = std::unique_ptr<Foo, decltype(FooDeleter<Foo>)>(10, FooDeleter<Foo>());
        std::unique_ptr<Foo> f2 = std::make_unique<Foo>(10);
        return;
    }
}

int main()
{
    unique::make_unique_test();

    return 0;
}