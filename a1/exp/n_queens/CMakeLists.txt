cmake_minimum_required(VERSION 3.6)
project(n_queens)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp)
add_executable(n_queens ${SOURCE_FILES})