cmake_minimum_required(VERSION 3.3)
project(a7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp EdgeNode.cpp EdgeNode.h GraphNode.cpp GraphNode.h Graph.cpp Graph.h)
add_executable(a7 ${SOURCE_FILES})