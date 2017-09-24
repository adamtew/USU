#include <iostream>

const int SIZE = 50000;

void make_array()
{
	int large_array[SIZE];
}

void make_heap_array()
{
	int* large_heap_array = new int[SIZE];	
}

template<typename F>
auto timeF(F f)
{
    auto start = std::chrono::steady_clock::now();
    f();
    auto end = std::chrono::steady_clock::now();
    auto duration = std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count());
    return duration;
}


int main()
{
	std::cout << "The time are: " << timeF(make_array) << "\n";
	std::cout << "The time are: " << timeF(make_heap_array) << "\n";
	
	
	return 0;
}
