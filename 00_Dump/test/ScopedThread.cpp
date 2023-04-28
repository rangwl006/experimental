#include <thread>
#include <iostream>
#include <queue>
#include <mutex>

class ScopedThread
{
  public:
    explicit ScopedThread(std::thread t);
    ~ScopedThread();
  private:
    
    std::thread m_thread;
};

template<typename DataType>
class ThreadSafeQueue
{
  public:
    ThreadSafeQueue()
    {
      std::cout << "ThreadSafeQueue::ThreadSafeQueue()" << std::endl;
    }
    
    ~ThreadSafeQueue()
    {
      std::cout << "ThreadSafeQueue::~ThreadSafeQueue()" << std::endl;
    }
    
    void push(DataType data)
    {
      std::lock_guard<std::mutex> lk(m_mu);
      m_queue.push(data);
    }
    
    void pop()
    {
      std::lock_guard<std::mutex> lk(m_mu);
      if (! m_queue.empty())
      {
        std::cout << "Popping: " << m_queue.front() << std::endl;
        m_queue.pop();
      }
      else
      {
        std::cout << "empty, cannot pop" << std::endl;
      }
    }
    
    DataType front()
    {
      std::lock_guard<std::mutex> lk(m_mu);
      return m_queue.front();
    }
    
    
  private:
    std::queue<DataType> m_queue;
    std::mutex m_mu;
};

// global scope
ThreadSafeQueue<int> queue;

int main()
{
  std::thread t1([](){ for (int i = 0; i < 50; i++) queue.push(i); });
  ScopedThread tx(std::move(t1));
  std::thread t2([](){ for (int i = 0; i < 100; i++) queue.pop(); });
  ScopedThread ty(std::move(t2));
  std::thread t3([](){ for (int i = 10; i < 50; i++) queue.push(i); });
  ScopedThread tz(std::move(t3));
  
  return 0;
}

ScopedThread::ScopedThread(std::thread t):
m_thread(std::move(t))
{
  std::cout << "ScopedThread()" << std::endl;
}

ScopedThread::~ScopedThread()
{
  if(m_thread.joinable())
    m_thread.join();
  std::cout << "ScopedThread::~ScopedThread()" << std::endl;
}