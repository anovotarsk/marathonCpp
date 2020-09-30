cmake_minimum_required(VERSION 3.18)

project(t_00)

include_directories(app/src)

add_compile_options(-std=c++14)

add_executable(simpleWorkerV1 app/main.cpp)