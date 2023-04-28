#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>

namespace basic
{
  struct Int
  {
    Int(int _i):i(_i)
    {
      std::cout << "Int(" << i << ")" << std::endl;
    }
    ~Int()
    {
      std::cout << "~Int(" << i << ")" << std::endl;
    }
    int i;
  };
  // create a unique pointer
  void createUniquePtr()
  {
    // create by assigning raw pointer
    std::unique_ptr<Int> u1 = std::unique_ptr<Int>(new Int(1));
    
    // create by make unique
    std::unique_ptr<Int> u2 = std::make_unique<Int>(2);
    
    // create by assign make unique
    // make unique returns an r-value unique ptr, which can be used as arg
    std::unique_ptr<Int> u3(std::make_unique<Int>(3));
  }
  
  // reassign a unique pointer to another unique pointer
  void reassignUniquePtr()
  {
    std::unique_ptr<Int> u4(std::make_unique<Int>(4));
    
    // transfer ownership of resource by passing in another unique ptr using move semantics
    std::unique_ptr<Int> u5(std::move(u4));
  }
}

namespace intermediate
{
  struct Int
  {
    Int(int _i):i(_i)
    {
      std::cout << "Int(" << i << ")" << std::endl;
    }
    ~Int()
    {
      std::cout << "~Int(" << i << ")" << std::endl;
    }
    int i;
  };
  
  // create a vector of unique pointers
  void createVectorOfUniquePtr()
  {
    std::vector<std::unique_ptr<Int>> v;
    for(int i = 1; i <= 10; i++)
    {
      v.push_back(std::make_unique<Int>(i));
    }
    for_each(v.begin(), v.end(), [](std::unique_ptr<Int>& ip){ std::cout << ip.get()->i << std::endl;});
  }
}

int main()
{
  basic::createUniquePtr();
  basic::reassignUniquePtr();
  intermediate::createVectorOfUniquePtr();
  return 0;
}