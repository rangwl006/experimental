#include <iostream>

using namespace std;

namespace sp
{
    template<typename T>
    class Wrapper
    {
      public:
        Wrapper() = default;
        ~Wrapper() = default;
        
        T* operator->()
        {
            return &m_resource;
        };
        
      private:
        T m_resource;
    };
    
    struct obj
    {
        void run() 
        {
            cout << "printing obj" << endl;
        };
    };
}

int main()
{
    cout<<"Hello World" << endl;
    sp::Wrapper<sp::obj> o;
    o->run();
    return 0;
}
