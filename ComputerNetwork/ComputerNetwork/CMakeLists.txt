cmake_minimum_required(VERSION 3.15)
project(pc_network)

set(CMAKE_CXX_STANDARD 14)

add_executable(pc_network main.cpp MainFunction.cpp MainHeader.h Node.h Node.cpp Stack.h Stack.cpp List.cpp List.h Computer.cpp Computer.h Network.cpp Network.h ColorArray.cpp ColorArray.h StaticList.cpp StaticList.h ItemTypeNode.cpp ItemTypeNode.h)