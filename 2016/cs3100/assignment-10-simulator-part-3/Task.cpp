#include "Task.hpp"
#include "Global.hpp"

/* ************************ *\
            TASK
\* ************************ */

Task::Task(int ios, int t,int cpu_io_bound)
  : time(TIME + 5), ios(ios)
{
  creation_time = TIME;
  response_time = 0;
  first_run = 0;
  next_operation = 0; // 0 for cpu, 1 for io
  id = current_id;
  current_id++;
  ((cpu_io_bound) ? generate_cpu_bound() : generate_io_bound());
  run_time = 0;
  for (int i : cpu_operations)
    run_time += i;

  approx_run_time = run_time / cpu_operations.size();
};

void Task::initialize_operation_queues(int cpu_up, int cpu_down, int io_up, int io_down)
{
  int n = random_number(5, 2);
  int cpu_time = 0;
  int io_time = 0;
  for (int i = 0; i < n; i++)
  {
    cpu_operations.push_back(random_number(cpu_up,cpu_down));
    cpu_time += cpu_operations[i];
  }
  for (int i = 0; i < n - 1; i++)
  {
    io_operations.push_back(IOItem(random_number(io_up, io_down), random_number(ios - 1, 0)));
    io_time += io_operations[i].time;
  } 
  ((cpu_time > io_time) ? bound = 0 : bound = 1);
}

void Task::generate_cpu_bound()
{
  initialize_operation_queues(15, 10, 10, 5);
}

void Task::generate_io_bound()
{
  initialize_operation_queues(5, 2, 10, 5);
}


std::ostream& operator<<(std::ostream& os, const Task& t)
{
  std::cout << "Task " << t.id << "\n";
  std::cout << "\tCreation Time: " << t.creation_time << "\n";
  std::cout << "\tTime: " << t.time << "\n";
  std::cout << "\tLatency: " << t.latency << "\n";
  std::cout << "\tResponse Time: " << t.response_time << "\n";
  std::cout << "\tRun Time: " << t.run_time << "\n";
  std::cout << "\tApprox Run Time: " << t.approx_run_time << "\n";
  std::cout << "\tNext Operation: " << ((t.next_operation) ? "IO" : "CPU") << "\n";
  std::cout << "\tCPU operations: ";
  for (int i = 0; i < t.cpu_operations.size(); i++)
    std::cout << " " << t.cpu_operations[i];

  std::cout << "\n\tIO Operations: ";
  for (int i = 0; i < t.io_operations.size(); i++)
    std::cout << " " << t.io_operations[i];
  std::cout << "\n";
  std::cout << "\tPage distribution: " << random_number(10, 1) << "\n";
  return os;
}


/* ************************ *\
            IOITEM
\* ************************ */

std::ostream& operator<<(std::ostream& os, const IOItem& io)
{
  std::cout << "(" << io.time << ", " << io.io_id << ")";
  return os;
}

/* ************************ *\
      LESS THAN OPERATOR
\* ************************ */

bool less_than_by_id::operator()(const Task& lhs, const Task& rhs) const
{
  return lhs.time > rhs.time;
}

bool shortest_job_first::operator()(const Task& lhs, const Task& rhs) const
{
  switch (SCHEDULING_ALGORITHM)
  {
    case 0: return lhs.current_time > rhs.current_time; break;
    case 1: return lhs.run_time > rhs.run_time; break;
    case 2: return lhs.approx_run_time > rhs.approx_run_time; break;
    default: break;
  }
  
}
