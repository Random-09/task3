cmake_minimum_required(VERSION 3.24)
project(task3_github C)

set(CMAKE_C_STANDARD 11)

add_executable(task3 main.c database.c database.h merge_sort.c merge_sort.h)
