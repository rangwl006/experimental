#include <iostream>
#include <memory>

using namespace std;

/**
 * Create a dummy Widget object
 */
struct Widget
{
    Widget(int a, int b)
    {
        std::cout <<"widget created with " << a << " " << b << std::endl;
    }
    
    ~Widget() = default;
};

/**
 * Type2Type struct is a placeholder struct used to convey type information.
 * The internals of Type2Type can be empty since we are just trying to convey
 * type information via a struct.
 */
template<typename T>
struct Type2Type
{
    typedef T MyType;
};

/**
 * This is the general Create function template.
 * Since function templates are unable to be partially specialised,
 * we are forced to do overloading. Which is below.
 */
template<class T, class U>
std::unique_ptr<T> Create(const U& arg)
{
    std::cout << "making unique ptr" << std::endl;
    return std::make_unique<T>();
}

/**
 * The motivation behind this overload is to give special treatment for certain
 * object classes. For example, the Widget object requires two arguments and
 * maybe other objects require no arguments at all.
 * 
 * Here, we use type-to-type mapping to overcome this.
 * We overload the original Create function with a Type2Type object to convey 
 * the special treatment we want to give.
 */
template<class T, class U>
std::unique_ptr<T> Create(const U& arg, Type2Type<T>)
{
    std::cout << "making unique ptr" << std::endl;
    return std::make_unique<T>();
}

/**
 * We partially specialize the function here.
 * i.e. Widget has its own way of being created.
 */
template<class U>
std::unique_ptr<Widget> Create(const U& arg, Type2Type<Widget> dummy)
{
    return std::make_unique<Widget>(arg, -1);
}

int main()
{
    int x = 100;
    auto f = Create<int, int>(x);
    auto w = Create(x, Type2Type<Widget>());
    cout << *(f.get()) << std::endl;
    return 0;
}
