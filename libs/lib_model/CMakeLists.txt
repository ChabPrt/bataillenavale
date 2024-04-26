cmake_minimum_required(VERSION 3.28)
project(lib_model C)

set(CMAKE_C_STANDARD 11)

add_library(lib_model STATIC library.c)
