cmake_minimum_required(VERSION 3.6)
project(golomb_rulers)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/golomb_rulers.cpp)
add_executable(golomb_rulers ${SOURCE_FILES})