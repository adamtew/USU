#include <mutex>
#include <thread>
#include <functional>
#include <queue>
#include <atomic>

#include "Thread_Queue.hpp"

class Thread_Pool
{
public:
  Thread_Pool(int n);
  ~Thread_Pool();
  void post(std::function<void(void)>);
  void start();
  void stop();
  void join();
  void start_pool();

private:
  std::vector<std::thread> m_pool;
  std::queue<std::function<void(void)>> m_tasks;
  // Thread_Queue<std::function<void(void)>> m_tasks;
  std::atomic<bool> m_continue;
  std::mutex m_mutex;
  std::condition_variable m_taskAdded;

};

Thread_Pool::Thread_Pool(int n):m_pool(), m_tasks(), m_continue(true)
{
  for(int i = 0; i < n; i++) {m_pool.emplace_back(
    [&]()
    {
      while(m_continue)
      {
        std::function<void(void)> f;
        {
          // std::lock_guard l(m_mutex);
          std::unique_lock<std::mutex> l(m_mutex);
          while(m_tasks.empty())
          {
            if(!m_continue) return;
            m_taskAdded.wait(l);
          }
          f = m_tasks.front();
          m_tasks.pop();
        }
        f();
      }
  });
    // std::cerr << "Start Thread" << std::endl;
}
}

Thread_Pool::~Thread_Pool()
{
  for(auto& t:m_pool)
  {
    t.join();
    // std::cerr << "Joined Thread" << std::endl;
  }
}

void Thread_Pool::start()
{
  m_continue = true;
}

void Thread_Pool::stop()
{
  m_continue = false;
  m_taskAdded.notify_all();
}

void Thread_Pool::post(std::function<void(void)> f)
{
  std::lock_guard<std::mutex> l(m_mutex);
  m_tasks.push(f);
  m_taskAdded.notify_one();
}

void Thread_Pool::join()
{
  for(auto& t : m_pool)
    t.join();
}

// Quick Sort

