#include <iostream>
#include "Global.hpp"

int current_id = 0;
int current_time = 0;
int CPUS, IOS, TASKS, idle_cpus, TASK_FREQUENCY, TOTAL_TIME = 50, RESPONSE_TIME, CPU_IO_MIX = 1, LATENCY, PRODUCTIVE_TIME;
bool FIRST_IO = true, FIRST_COMPLETED = true;
int TIME = 0;
int CONTEXT_SWITCH_COST = 5;

int random_number(int size, int range)
{
  static std::random_device rd;
  static std::mt19937 mt(rd());
  std::uniform_int_distribution<> dist(range, size);
  return (dist(mt));
}




void initialize()
{
  // std::string tasks;
  // std::cout << "Number of tasks: ";
  // std::cin >> TASKS;
  std::cout << "Total Time: ";
  std::cin >> TOTAL_TIME;
  std::cout << "Number of cpus: ";
  std::cin >> CPUS;
  std::cout << "Number of I/O devices: ";
  std::cin >> IOS;
  std::cout << "Percent cpu-bound processes: ";
  std::cin >> CPU_IO_MIX;
  std::cout << "Task Frequency: ";
  std::cin >> TASK_FREQUENCY;
  std::cout << "Context Switch Cost: ";
  std::cin >> CONTEXT_SWITCH_COST;
  idle_cpus = CPUS;
}