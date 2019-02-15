cmake_minimum_required(VERSION 3.12)
project(ISL)

set(CMAKE_CXX_STANDARD 17)

add_executable(ISL main.cpp Interval_skip_list_interval.h Interval_skip_list.h random.h)