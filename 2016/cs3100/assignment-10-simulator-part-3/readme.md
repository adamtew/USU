# Adam Tew
# Assignment 9 - Simulator - Part II

> Add Round Robin, Shortest Job First, and Approximate Shortest Job First scheduling to your simulator.  Design an experiment and report on your findings as before.

--

## Sample execution 

Build the executable using `cmake` and `cmake`. Then, run `main` and give it values for the following parameters:

- Total Time - the amount of time the program will run for.
- Number of CPUs - the total number of CPUs to work with.
- Number of I/O devices - the total number of I/O devices to simulate.
- Task Mix - The percentage of cpu-bound processes
- Task Frequency - how often a new task is generated.
- Cost of the context switch - the amount of time a context switch will take.



```
cmake .; make; ./main;

# Example input to give the program
# 
# Total Time: 100
# Number of cpus: 5
# Number of I/O devices: 5
# Percent cpu-bound processes: 50
# Task Frequency: 5
# Context Switch Cost: 5
# Scheduling Algorithm (0 - Round Robin), (1 - Shortest), (2 - Approx Shortest): 0
# Interruption Frequency: 10
# Memory Scheduling (0 - FIFO), (1 - MRU), (2 - LRU), (3 - Second Chance): 0
# Size of Cache: 20
# Cache Miss Penalty: 5
# Page Distribution: 5


```

--

## Report

Adding memory to the scheduler was interesting. I think it made things slower. From before, adding scheduling algorithms to the program made things a little different. The round robin was definitely the worst and the shortest first was the best. Other than that this was a very interesting program to run. I found that running more I/O bound processes caused a lot more latency and a lot less efficiency. Also, if I made the task frequency lower, then it took much longer for individual taks to get completed due to the fact it takes longer to get a single task done if there are tons of other tasks being generated that need to be looked at.