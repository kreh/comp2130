cmake_minimum_required(VERSION 3.13)
project(Rainfall C)

set(CMAKE_C_STANDARD 11)

include_directories(include)
set(SOURCE_FILES main.c)
add_executable(Rainfall ${SOURCE_FILES})