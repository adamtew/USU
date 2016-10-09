cmake_minimum_required(VERSION 3.3)
project(a3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    avlTree.h
    Board.cpp
    Board.h
    BoardNode.cpp
    BoardNode.h
    BoardQueue.cpp
    BoardQueue.h
    Game.cpp
    Game.h
    main.cpp)

add_executable(a3 ${SOURCE_FILES})