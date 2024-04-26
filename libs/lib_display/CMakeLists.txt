cmake_minimum_required(VERSION 3.28)
project(lib_display C)

set(CMAKE_C_STANDARD 11)

add_library(lib_display STATIC library.c)
