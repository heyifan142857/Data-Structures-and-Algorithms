cmake_minimum_required(VERSION 3.30)
project(hw11)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-D LOCAL)

add_executable(hw11 main.cpp)

add_executable(coins coins.cpp)

add_executable(tree tree.cpp)

add_executable(partition partition.cpp)
