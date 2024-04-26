cmake_minimum_required(VERSION 3.28)
project(app C)

set(CMAKE_C_STANDARD 11)

#Add display library
add_library(lib_display SHARED ${CMAKE_CURRENT_SOURCE_DIR}/../libs/lib_display/library.c)

#Add model library
add_library(lib_model SHARED ${CMAKE_CURRENT_SOURCE_DIR}/../libs/lib_model/library.c)

add_executable(app main.c
        ../libs/lib_display/library.c
        ../libs/lib_model/library.c
)

target_link_libraries(app PUBLIC lib_display)

target_link_libraries(app PUBLIC lib_model)