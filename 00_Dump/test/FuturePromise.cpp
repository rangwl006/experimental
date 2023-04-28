#include <iostream>
#include <asio.hpp>
#include <chrono>
#include <future>

class Worker
{
  public:
    Worker() = default;
    void VeryLongOperation(std::future<int> f)
    {
      int x = f.get();
      std::cout << "Promised value received: " << x << std::endl;
    }
    void operator()()
    {
      std::cout << "Worker()" << std::endl;
    };
};


int main()
{
  Worker w;
  w();
  std::promise<int> prom;
  std::future<int> fut = prom.se
  w.VeryLongOperation(prom)
  // asio::io_context io;
  return 0;
}