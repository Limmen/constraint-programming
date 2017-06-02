cmake_minimum_required(VERSION 3.6)
project(n_queens_0_1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/queens.cpp)
add_executable(n_queens_0_1 ${SOURCE_FILES})