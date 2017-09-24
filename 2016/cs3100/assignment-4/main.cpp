#include <tuple>
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <functional>
#include <time.h>
#include <algorithm>

#include "Thread_Pool.hpp"
#include "Sort_Utilities.hpp"
#include "Utils.hpp"

const int THREADS = 5;
Thread_Pool THREAD_POOL(THREADS);

void print_stuff()
{
  std::cout << "echo\n";
}

int main(){    
  srand (time(NULL));

  std::vector<int> v1, v2, v3;
  std::vector<int> times;

  random_vector<int>(v1, 100);
  print_vector(v1, "v1");
  auto sort_time = timeF([&](){
    quick_sort<int>(v1, 0, v1.size());
    random_vector<int>(v3, 1000);

  });
  print_vector(v1, "v1");
  auto find_time = timeF([&](){
    find_in_vector(v1, 5);  
  });

  std::cout << "Sort Time: " << sort_time << " seconds\n";
  std::cout << "Find Time: " << find_time << " seconds\n";


  random_vector<int>(v2, 100);
  print_vector(v2, "v2");
  sort_time = timeF([&](){
    std::sort(v2.begin(), v2.end());
  });
  print_vector(v2, "v2");
  int find = 30;
  auto item = std::find (v2.begin(), v2.end(), find);

  if (*item == find)
    std::cout << "found " << 30 << std::endl;
  else
    std::cout << "didn't find it\n";
  std::cout << "Sort Time: " << sort_time << " seconds\n";





    // Thread_Pool thread_pool(5);
    // int jobs = 50;
    // for (int i = 0;i < jobs; i++)
      // THREAD_POOL.post(print_stuff);
    // std::vector<MandelParts> parts_vector;

  THREAD_POOL.stop();
  return 0;
}



// std::function<void(void)> f;

// int a, b, c;
// f = [=](){foo(a, b, c);};


// [=] = capture by value
// [&] = capture by reference
// f = [=]()->void{foo(a,b,c);};
// struct Lambda
// {
//     lambda(a, b, c):a(a), b(b), c(c){}
//     void operator()(void)
//     {
//         foo(a,b,c);
//     }
//     int a, b, c;
// };

// // 
// std::condition_variable c;
// bool p();
// std::mutex m;

// {
//     std::unique_lock<std::mutex> l(m);
//     while(!p()) // use a while loop because of spurious wakeups
//     {
//         c.wait(l);
//     }
//         //dostuff
// }

// c.notify_one();

// In class
// std::sort(b,e,c)
// std::sort(b,e,std::greater<>())
// 
// Perils of mutexes
// 
// deadlock - 
