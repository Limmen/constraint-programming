cmake_minimum_required(VERSION 3.6)
project(sudoku)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/sudoku.cpp)
add_executable(sudoku ${SOURCE_FILES})