#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <deque>

struct IOItem
{
  IOItem(int t, int io)
    : time(t), io_id(io)
  {

  }

  int time;
  int io_id;

  friend std::ostream& operator<<(std::ostream& os, const IOItem& obj);

};

class Task
{
public:
  Task(int ios, int t, int cpu_io_bound = 0);
  int id,
    time,
    next_operation,
    bound, // 0 for cpu bound, 1 for io bound
    ios, // number of I/O devices
    latency,
    response_time,
    first_run,
    creation_time,
    run_time,
    approx_run_time,
    current_time;
  std::deque<int> cpu_operations; // start with a cpu, go every other, end with a cpu
  std::deque<IOItem> io_operations;

  void set_bound();
  void initialize_operation_queues(int cpu_up, int cpu_down, int io_up, int io_down);
  void generate_cpu_bound();
  void generate_io_bound();

  friend std::ostream& operator<<(std::ostream& os, const Task& obj);

// whenever you generate a cpu task you need to draw CPU(IO)* from a given
private:
};


struct less_than_by_id
{
  bool operator()(const Task& lhs, const Task& rhs) const;
};

struct shortest_job_first
{
  bool operator()(const Task& lhs, const Task& rhs) const;
};

#endif
