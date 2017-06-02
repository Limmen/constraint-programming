cmake_minimum_required(VERSION 3.6)
project(square_packing)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/no-overlap.h src/no-overlap.h src/interval.cpp)
add_executable(square_packing ${SOURCE_FILES})