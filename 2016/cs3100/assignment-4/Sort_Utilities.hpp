#include <mutex>
extern Thread_Pool THREAD_POOL;
std::mutex mtx_a, mtx_b;
// extern int THREADS;
// #include "Thread_Pool.hpp"

    // int jobs = 50;

  // print_vector(v2, "v2");
    // for (int i = 0;i < jobs; i++)
      // thread_pool.post(print_stuff);


    // std::vector<MandelParts> parts_vector;

    // thread_pool.stop();


template<typename T>
auto vector_search(std::vector<T>& v, T x)
{

  for (int i = 0; i < v.size(); i++)
    if (v[i] == x) 
      return i;
  return -1;
}


template<typename T>
auto find_in_vector(std::vector<T>& v, T x)
{
  std::cout << "trying to find: " << x << "\n";
  int position = vector_search(v, x);

  // THREAD_POOL.post([&]() {
  // });
    vector_search<T>(v, 5);
  if (position >= 0)
    std::cout << "found " << x << " in position " << position << "\n";
  else 
    std::cout << x << " doesn't exist in the vector\n";
}


template<typename T>
auto random_vector(std::vector<T>& v, int size)
{
  for (int i = 0; i < size; i++)
    v.push_back(rand() % size);
}


template<typename T>
auto swap(T* a, T* b)
{
  T temp = *a;
  *a = *b;
  *b = temp;
}


template<typename T>
auto partition (std::vector<T>& v, T start, T end)
{
    int pivot = v[end];    // pivot
    int i = (start - 1);  // Index of smaller element
 
    for (int j = start; j <= end -1; j++)
        // If current element is smaller than or
        // equal to pivot
        if (v[j] <= pivot)
        {
            i++;    // increment index of smaller element
            {
              std::lock_guard<std::mutex> l(mtx_a);
              swap(&v[i], &v[j]);
              
            }
        }
      {
        std::lock_guard<std::mutex> l(mtx_b);
        swap(&v[i + 1], &v[end]);
      }
    return (i + 1);
}


template<typename T>
void quick_sort(std::vector<T>& v, T start, T end)
{
  if (start < end)
  { 
    T partition_index = partition(v, start, end);
    // THREAD_POOL.post([&]() {
    //   // std::cerr << "in thread " << partition_index << "\n";
    // });
      quick_sort(v, start, partition_index - 1);
    // std::cout << "partitions: " << partition_index - 1 << " " << partition_index + 1 << "\n";
    // std::cout << "partitions: " << partition_index << "\n";
    quick_sort(v, partition_index + 1, end);
  }
}


// void print_vector(std::vector<int> v, std::string name)
// {
//   std::cout << "\n" << name << ": ";
//   for (int i = 0; i < v.size(); i++)
//     std::cout << v[i] << " ";
//   std::cout << "\n";
// }


void print_vector(std::vector<int> v, std::string name)
{
  std::cout << "\n" << name << ": ";
  for (std::vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
