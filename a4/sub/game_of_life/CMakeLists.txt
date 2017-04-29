cmake_minimum_required(VERSION 3.6)
project(game_of_life)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)
add_executable(game_of_life ${SOURCE_FILES})