cmake_minimum_required(VERSION 3.20)

project(mystring)

set(CMAKE_CXX_STANDARD 17)

add_executable(mystring example/main.cpp library/mystring.hpp library/mystring.cpp)
