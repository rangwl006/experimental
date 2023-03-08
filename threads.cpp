#include <iostream>
#include <future>
#include <string>
#include <vector>
#include <chrono>
#include <mutex>

using namespace std::chrono_literals;

int a = 0;
std::mutex mu;

void SayHello(int thread_id, std::string str)
{
  std::lock_guard<std::mutex> lk(mu);
  for (int i = 0; i < 10000000; i++)
    a++;
  std::cout << str << "(" << thread_id << ")" << ", a:" << a << std::endl;
  return;
};

int main()
{
  std::vector<std::thread> threads;
  for (int i = 1; i <= 5; i++)
  {
    threads.push_back(std::thread{SayHello, i, "Hello from thread: "});
  }
  // std::this_thread::sleep_for(1000ms); 
  for (auto& th : threads)
  {
    th.join();
  }
  
  return 0;
}
