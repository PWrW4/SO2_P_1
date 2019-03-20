cmake_minimum_required(VERSION 3.13)
project(SO2_P_1)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(SO2_P_1 main.cpp)

target_link_libraries(SO2_P_1 pthread)