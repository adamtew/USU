#include <mutex>
#include <thread>
#include <functional>
#include <queue>
#include <atomic>

#include "Thread_Queue.hpp"

class Thread_Pool
{
public:
  Thread_Pool(int n, int jobs);
  ~Thread_Pool();
  void post(std::function<void(void)>);
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
  int size;
  int crementor;

};

Thread_Pool::Thread_Pool(int n, int jobs):m_pool(), m_tasks(), m_continue(true), crementor(jobs)
{
  for(int i = 0; i < n; i++) m_pool.emplace_back(
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
            m_taskAdded.wait(l);
          }
          m_tasks.front();
          m_tasks.pop();
        }
          f();
      }
  });
}

Thread_Pool::~Thread_Pool()
{
  for(auto& t:m_pool)
    t.join();
}

void Thread_Pool::stop()
{
  m_continue = false;
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
