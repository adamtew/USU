#include <queue>
#include <mutex>
// class Thread_Pool
// {

// };

template <typename T>
class Thread_Queue
{
public:
  Thread_Queue()
  {

  }

  auto pop()
  {
    std::lock_guard<std::mutex> guard(the_mutex);
    T item = q.front();
    q.pop();
    return item;
  }

  auto push(T t)
  {
    std::lock_guard<std::mutex> guard(the_mutex);
    q.push(t);
  }

  auto empty()
  {
    std::lock_guard<std::mutex> guard(the_mutex);
    return q.empty();
  }

  // Thread_Queue(){};
private:
  std::queue<T> q;
  std::mutex the_mutex;


};


// std::queue(std::function())
// std::queue(std::function(void))

// using an atomic as a mutex
// --- Spin Lock --- <-- Good for not a lot of threads
// std::lock_guard = v
// int m = 0 <-- m for my_lock
// while(m == 0) swap(m, lock);
// 
// 
// swap(m, lock);

// --- All you should need ---
// {
//  std::lock_guard
// }

// template<typename T>
// class mutexes
// {
//   T data;
//   std::mutex m;
// }

// std::atomic<T>

// In class coding of the queue
// #include <mutex>
// #include <thread>
// #include <functional>
// #include <queue>
// #include <atomic>

// class class ThreadPool
// {
// public:
//   ThreadPool(int n);
//   ~ThreadPool();
//   void post(std::function<void(void)>);
//   void stop();

// private:
//   std::vector<std::thread> m_pool;
//   std::queue<std::function<void(void)>> m_tasks;
//   std::atomic<bool> m_continue;
//   std::mutex m_mutex;
//   std::condition_variable m_taskAdded;


// };

// // thread_pool
// #include "ThreadPool.hpp"

// ThreadPool::ThreadPool(int n):m_pool(), m_tasks()
// {
//   for(int i = 0; i < n; i++) m_pool.emplace_back(
//     [&]()
//     {
//       while(m_continue)
//       {
//         std::function<void(void)> f;
//         {
//           // std::lock_guard l(m_mutex);
//           std::unique_lock<std::mutex> l(m_mutex);
//           while(m_tasks.empty(1))
//           {
//             m_taskAdded.wait();
//           }
//           m_tasks.front();
//           m_tasks.pop();
//         }
//         f();
//       }
//   });
// }

// ThreadPool::~ThreadPool()
// {
//   for(auto&& t:m_pool)
//     t.join();
// }

// void ThreadPool::stop()
// {
//   m_continue = false;
// }

// void ThreadPool::post(std::function<void(void)> f)
// {
//   std::lock_guard l(m_mutex);
//   m_tasks.push(f);
//   m_taskAdded.notifyOne();
// }


