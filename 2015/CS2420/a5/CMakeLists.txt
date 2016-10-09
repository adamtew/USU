cmake_minimum_required(VERSION 3.3)
project(a5)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    example.cpp
    Heap.h
    Heap_int.h
    main.cpp
    PriorityQueue.cpp
    PriorityQueue.h
    SortedWords.txt
    Runner.h
    Term.h)

add_executable(a5 ${SOURCE_FILES})