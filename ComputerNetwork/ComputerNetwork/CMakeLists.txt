cmake_minimum_required(VERSION 3.15)
project(pc_network)

set(CMAKE_CXX_STANDARD 14)

add_executable(Main.cpp MainFunction.cpp MainHeader.h Node.h Node.cpp Queue.cpp Queue.h Stack.h Stack.cpp)