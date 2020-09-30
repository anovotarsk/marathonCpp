cmake_minimum_required(VERSION 3.18)

project(t_00)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_EXE main.cpp)

include_directories(src)

add_executable(vampireRabbits ${SOURCE_EXE})

add_subdirectory(src)

target_link_libraries(vampireRabbits vampires)

add_compile_options(
    -pipe
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)