#ifndef GLOBAL_HPP
#define GLOBAL_HPP
#include <random>

// namespace OS_Global
// {

  /*
    Mersenne Twister
  */

  extern int random_number(int size, int range = 1);

  extern int current_id;
  extern int current_time;
  extern int CPUS,
    IOS,
    TASKS,
    idle_cpus,
    TIME,
    TASK_FREQUENCY,
    TOTAL_TIME,
    RESPONSE_TIME,
    CPU_IO_MIX,
    CONTEXT_SWITCH_COST,
    LATENCY,
    PRODUCTIVE_TIME,
    SCHEDULING_ALGORITHM,
    INTERRUPTION_FREQUENCY;
  extern bool FIRST_IO, FIRST_COMPLETED;
  // extern const int CONTEXT_SWITCH_COST;

  void initialize();



// }

#endif
