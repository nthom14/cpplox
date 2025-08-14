cmake_minimum_required(VERSION 3.11)

project(cpplox VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall /EHsc")

add_executable(lox main.cpp 
    Lox.hpp
    Lox.cpp
    LoxObject.hpp
    LoxObject.cpp
    LoxTypes.hpp
    LoxTypes.cpp
    TokenType.hpp
    Token.hpp
    Token.cpp
    Scanner.hpp
    Scanner.cpp)