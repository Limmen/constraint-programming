cmake_minimum_required(VERSION 3.6)
project(game_of_life)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp src/life2.cpp src/life4.cpp src/life6.cpp src/life2.cpp)
add_executable(game_of_life ${SOURCE_FILES})