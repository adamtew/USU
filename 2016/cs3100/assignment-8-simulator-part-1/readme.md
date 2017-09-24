# Adam Tew
# Assignment 8 - Simulator - Part I

> Write a simulator for exploring different CPU and Memory scheduling algorithms. 
> 
> At a minimum your simulator must be able to vary the following parameters:

> Task mix - The percentage of CPU vs I/O bound processes
> Task frequency - The rate at which new processes are added to the system
> Number of CPUs
> Number of unique I/O Devices
> Cost of a context switch
> At a minimum your simulator must be able to measure the following statistics:

> Response Time - Time from process creation to first I/O completion
> Latency - Time from process creation to final CPU completion
> Throughput - Number of completed processes per unit time
> Efficiency - Percentage of time spent with CPUs occupied with useful work (context switching does not count)


> Use your simulator to explore FIFO process scheduling. Include a report of your findings. Include a readme file that explains how to run your simulator and set parameters for an experiment.  Future assignments will extend the number of scheduling algorithms and the number of parameters so be flexible in your implementation.


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
# Number of cpus: 1
# Number of I/O devices: 1
# Percent cpu-bound processes: 50
# Task Frequency: 10
# Context Switch Cost: 1


```

--

## Report

This was a very interesting program to run. I found that running more I/O bound processes caused a lot more latency and a lot less efficiency. Also, if I made the task frequency lower, then it took much longer for individual taks to get completed due to the fact it takes longer to get a single task done if there are tons of other tasks being generated that need to be looked at.