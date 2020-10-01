cmake_minimum_required(VERSION 3.17)
project(input C)

set(CMAKE_C_STANDARD 99)
set ( SOURCE_FILES main.c)
add_library(input ${SOURCE_FILES})