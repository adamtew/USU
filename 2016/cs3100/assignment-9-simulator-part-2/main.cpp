/*
  Get FIFO working first...
  overload the minus operator

  Figure out context switching or interruptions
  Create priority queue for tasks
  Create object maintains a reference to the following:
    - cpu time
    - io time
    - processed or not
*/

#include <iostream>
#include <queue> // shortest job first (priority queue)
#include <vector>
#include "Task.hpp"
#include "Global.hpp"
#include <iomanip>


// void event_loop();
void event_loop();
void enqueue_task();
void ready_task();
void migrate_ready_tasks();
void process_cpu_task(Task t);
void process_io_task(Task t);
void interrupt(Task t);
void report();

// std::vector<Task> task_queue;
// std::priority_queue<Task, > FIFO;
std::priority_queue<Task, std::vector<Task>, less_than_by_id> event_queue; // event_queue
// std::queue<Task> cpu_ready_set; // make sure you can change this from FIFO to something else
std::priority_queue<Task, std::vector<Task>, shortest_job_first> cpu_ready_set; // where scheduling happens
std::queue<Task> io_ready_set; // make sure you can change this from FIFO to something else
std::vector<Task> completed_tasks;
std::vector<int> total_cpus;
std::vector<int> total_ios;
// int TIME = 0;
// std::priority_queue<Task> FIFO;

// event_queue - priority queue organized by time
// ready set is a FIFO queue 


void print_vector(std::vector<int> v)
{
  for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << " ";
  std::cout << "\n";
}

bool check_idle(std::vector<int> v)
{
  for (int i = 0; i < v.size(); i++)
    if (v[i] == -1) return true;
  return false;
}

void use_cpu(int time)
{
  for (int i = 0; i < total_cpus.size(); i++)
    if (total_cpus[i] == -1)
    {
      total_cpus[i] = time;
      return;
    }
}

void use_io(int time)
{
  for (int i = 0; i < total_ios.size(); i++)
    if (total_ios[i] == -1)
    {
      total_ios[i] = time;
      return;
    }
}

void check_idles(int time)
{
  for (int i = 0; i < total_cpus.size(); i++)
    if (total_cpus[i] == time)
      total_cpus[i] = -1;
  for (int i = 0; i < total_ios.size(); i++)
    if (total_ios[i] == time)
      total_ios[i] = -1;
}

int main()
{
  initialize();
  for (int i = 0; i < CPUS; i++)
    total_cpus.push_back(-1);
  for (int i = 0; i < IOS; i++)
    total_ios.push_back(-1);

  event_loop();
  report();
  /*
    initialize tasks, cpus, and ios
    create tasks
    Fill event queue with tasks
    while (tasks)
      migrate tasks from event queue to ready queue
      pull single task from ready queue and place on cpu or io 
      remove from cpu or io and put back on the event queue
  */


  // std::cout << "random: " << std::to_string(random_number(10, 5)) << "\n";
  

  

  // pull task off the ready set and put it onto an available cpu

  // for (int i = 0; i < 5; i++)
    // std::cout << "The " << std::to_string(i) << "th element is: " FIFO
  // FIFO.
}


void event_loop()
{
  int n = 0;
  while (n < TOTAL_TIME)
  {
    check_idles(n);
    // print_vector(total_ios);
    enqueue_task();
    ready_task();
    migrate_ready_tasks();
    n++;
    TIME++;
    // std::cout << "The time is now: " << TIME << "\n";
  }
}

void enqueue_task()
{
  if (TIME % TASK_FREQUENCY == 0)
  {
    bool cpu_io_mix = random_number(100) < CPU_IO_MIX;
    event_queue.push(Task(IOS, TIME, static_cast<int>(cpu_io_mix)));
  }
}

void ready_task()
{
  if (!event_queue.empty() && event_queue.top().time <= TIME)
  {
    Task task = event_queue.top();
    event_queue.pop();
    if (task.next_operation == 0)
    { 
      task.current_time = TIME;
      cpu_ready_set.push(task);
      // std::cout << "Task removed from the event queue and being pushed onto cpu ready queue:\n" << task;
    }
    else
    {
      io_ready_set.push(task);
      // std::cout << "Task removed from the event queue and being pushed onto io ready queue:\n" << task;
    }
  }
}

void migrate_ready_tasks()
{
  if (!cpu_ready_set.empty() && check_idle(total_cpus))
  {
    Task task = cpu_ready_set.top();
    process_cpu_task(task);
    // std::cout << "Task removed from the cpu ready queue and being processed:\n" << task;
    cpu_ready_set.pop();
  }
  if (!io_ready_set.empty() && check_idle(total_ios))
  {
    Task task = io_ready_set.front();
    if (total_ios[task.io_operations.front().io_id] == -1)
    {
      process_io_task(task);
      io_ready_set.pop();
    }
    // std::cout << "Task removed from the io ready queue and being processed:\n" << task;
  }

}

void process_cpu_task(Task t)
{
  int cpu_operation;
  if (!t.cpu_operations.empty())
  {
    cpu_operation = t.cpu_operations.front();
    int schedule_time = TIME + cpu_operation + CONTEXT_SWITCH_COST;
    if (t.first_run == 0) t.first_run = TIME;
    use_cpu(schedule_time);
    t.run_time -= cpu_operation;
    PRODUCTIVE_TIME += cpu_operation;
    // std::cout << "Processing cpu task for task " << t.id << " there are idle cpus " << idle_cpus <<"\n"; 
    t.time = schedule_time;
    t.next_operation = 1;
    
    if (cpu_operation > INTERRUPTION_FREQUENCY)
    {
      if (!t.cpu_operations.empty())
      {
        t.cpu_operations[0] -= INTERRUPTION_FREQUENCY;
        cpu_ready_set.push(t);
      }
    }
    else 
    {
      t.cpu_operations.pop_front();
      if (t.cpu_operations.empty())
      {
        t.latency = t.time - t.first_run;
        ((FIRST_COMPLETED) ? LATENCY = schedule_time : false); // update response time
        FIRST_COMPLETED = false;
        std::cout << "\n\n * Task Completed * \n" << t << "\n";
        completed_tasks.push_back(t);
      }
      else
        event_queue.push(t);
      event_queue.push(t);
    }
    idle_cpus++;
  }

  /*
    When you're putting something onto the queue you want to see if it will take
    longer than the smallest amount of time before the interrupt, like 5ms or something
  */

}

void process_io_task(Task t)
{
  int io_operation;
  if (!t.io_operations.empty())
  {
    io_operation = t.io_operations.front().time;


    int schedule_time = TIME + io_operation + CONTEXT_SWITCH_COST;
    use_io(schedule_time);
    PRODUCTIVE_TIME += io_operation;
    t.io_operations.pop_front();
    ((FIRST_IO) ? RESPONSE_TIME = schedule_time : false); // update response time
    FIRST_IO = false;
    t.response_time = schedule_time - t.creation_time;
    t.time = schedule_time;
    t.next_operation = 0;
    event_queue.push(t);
  }
}

void interrupt(Task t){}

struct Report_Data
{
  int tasks, cpu_bound, io_bound;
  double throughput, efficiency, response_time, latency;

  Report_Data(int t = 0, int c_b = 0, int io_b = 0, int through = 0, int lat = 0, double eff = 0)
    : tasks(t), cpu_bound(c_b), io_bound(io_b), throughput(through), latency(lat), efficiency(eff)
  {};
};

Report_Data gather_report_data()
{
  Report_Data data;
  int latency = 0;
  int response_time = 0;
  for (int i = 0; i < completed_tasks.size(); i++)
  {
    data.tasks++;
    latency += completed_tasks[i].latency;
    response_time += completed_tasks[i].response_time;
    ((completed_tasks[i].bound == 0) ? data.cpu_bound++ : data.io_bound++);
  }

  data.latency = static_cast<double>(latency) / static_cast<double>(completed_tasks.size());
  data.response_time = static_cast<double>(response_time) / static_cast<double>(completed_tasks.size());
  data.efficiency = static_cast<double>(PRODUCTIVE_TIME) / static_cast<double>(TOTAL_TIME) * static_cast<double>(CPUS);
  data.throughput = static_cast<double>(data.tasks) / static_cast<double>(TOTAL_TIME);
  return data;
}

void report()
{
  Report_Data data = gather_report_data();

  std::cout << "Report:\n\n" << std::setprecision(2) << std::fixed;
  std::cout << "Total Time:\t" << TOTAL_TIME << "\n";
  std::cout << "Completed:\t" << data.tasks << "\n";
  std::cout << "CPU Bound:\t" << data.cpu_bound << "\n";
  std::cout << "IO Bound:\t" << data.io_bound << "\n";
  std::cout << "Throughput:\t" << data.throughput << "\n";
  std::cout << "Latency:\t" << data.latency << "\n";
  std::cout << "Efficiency:\t" << data.efficiency << "\n";
  std::cout << "Response Time:\t" << data.response_time << "\n";


}
/*
  Processing algorithms:

  Shortest Job First (Priority Queue - based on varying critera)
    - 

  - Round Robin (just FIFO with interruption)
    - Used on personal computers
    - terrible for throughput
    - great for response time
  Approximate Shortes Job First
    > I really want this optimal algorithm, but I don't know what's going to be 
    the shortest, so I'll guess
*/

