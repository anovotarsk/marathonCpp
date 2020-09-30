cmake_minimum_required(VERSION 3.18)

project(t_00)

include_directories(app)

add_executable(draugr app/main.cpp)

add_subdirectory(app)

target_link_libraries(draugr lib)