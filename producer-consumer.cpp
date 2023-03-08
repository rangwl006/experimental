#include <iostream>
#include <string>
#include <queue>
#include <mutex>
#include <future>
#include <condition_variable>
#include <vector>
#include <chrono>

using namespace std::chrono_literals;

std::mutex mu;
std::condition_variable cv;
bool ready = false;
bool processed = false;
std::vector<int> data;
int maxBuffer = 250000;

void consumer()
{
  while (true)
  {
    std::unique_lock<std::mutex> lk(mu);
    cv.wait(lk, []{ return data.size() > 0; });
    int val = data.back();
    data.pop_back();
    std::cout << "Consumed val: " << val << std::endl;
    lk.unlock();
    cv.notify_one();
    std::this_thread::sleep_for(5ms);
  }
};

void producer(int val)
{
  while (val > 0)
  {
    std::unique_lock<std::mutex> lk(mu);
    cv.wait(lk, []{ return data.size() < maxBuffer; });
    data.push_back(val);
    std::cout << "produced val: " << val << std::endl;
    val--;
    lk.unlock();
    cv.notify_one();
    std::this_thread::sleep_for(10ms);
  }
}

int main()
{
  std::cout << "starting producer" << std::endl;
  std::thread producerThread(producer, 100);
  std::cout << "starting consumer" << std::endl;
  std::thread consumerThread(consumer);
  std::cout << "finish" << std::endl;
  producerThread.join();
  consumerThread.join();
  return 0;
}
