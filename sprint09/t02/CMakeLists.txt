cmake_minimum_required(VERSION 3.18)

project(t_01)

include_directories(app/src)

add_compile_options(-std=c++14)

add_executable(simpleWorkerV2 app/main.cpp)