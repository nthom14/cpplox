cmake_minimum_required(VERSION 3.11)

project(cpplox VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall /EHsc")

add_executable(lox lox.cpp)