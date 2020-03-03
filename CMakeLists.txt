cmake_minimum_required(VERSION 3.15)
project(MiniProj C)

set(CMAKE_C_STANDARD 11)

add_executable(MiniProj driver.c task.h cpu.h list.h schedulers.h list.c cpu.c schedule_priority.c mergeSortHelper.h)