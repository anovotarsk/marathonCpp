cmake_minimum_required(VERSION 3.18)

project(t_01)

include_directories(app app/src)

add_compile_options(-std=c++11)

add_executable(imperialVsStormcloak app/main.cpp)

add_subdirectory(app)

target_link_libraries(imperialVsStormcloak lib)
