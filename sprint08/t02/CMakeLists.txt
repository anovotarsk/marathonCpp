cmake_minimum_required(VERSION 3.18)

project(t_00)


include_directories(app)

add_compile_options(-std=c++17)

add_executable(universalReferenceDeterminant app/main.cpp)

#add_subdirectory(app)

#target_link_libraries(classWithInitializerList lib)
