cmake_minimum_required(VERSION 3.30)
project(hw09)

set(CMAKE_CXX_STANDARD 20)

add_definitions(-D ACM_LOCAL)

add_executable(hw09 Candy.cpp)
