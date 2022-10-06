cmake_minimum_required(VERSION 3.15)

project(mystring)

set(CMAKE_CXX_STANDARD 17)

add_executable(mystring src/main.cpp src/mystring.hpp src/mystring.cpp)
