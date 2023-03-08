#include <iostream>
#include <future>
#include <mutex>
#include <functional>
#include <atomic>
#include <condition_variable>
#include <queue>

/**
 * Trivial Thread Pool
 * What is a thread pool?
 * A thread pool is a group of threads that execute tasks from a work queue.
 *
 * Requirements of a basic thread pool:
 * 1. Thread pool maintains several threads
 * 2. Thread pool maintains a queue of jobs
 */

namespace Threading
{
  template<typename T>
  class thread_safe_queue
  {
    private:
      std::queue<T> m_queue;
      std::mutex m_mu;
      std::condition_variable m_cond;
    
    public:
      thread_safe_queue();

      void push(T obj)
      {
        std::unique_lock<std::mutex> lk(m_mu);
        m_queue.push(obj);
        m_cond.notify_one();
      };

      void pop()
      {
        std::unique_lock<std::mutex> lk(m_mu);
        m_cond.wait(lk, [this](){ return !m_queue.empty(); }); // stop waiting when queue is not empty

        m_queue.pop();
      };

  };

  class basic_thread_pool
  {
    public:

    private:
      std::atomic_bool done;
  };
}

int main()
{
  Threading::thread_safe_queue<int> q;
  std::vector<std::thread> vec;
  for (int i = 0; i < 10; i++)
  {
    std::thread th(&Threading::thread_safe_queue<int>::push, &q, i);
  }

  return 0;
}
