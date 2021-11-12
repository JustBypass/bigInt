cmake_minimum_required(VERSION 3.8)

project(3D)
add_subdirectory(Class)
add_subdirectory(Factory)
add_executable(main main.cpp)

target_link_libraries(main STATIC Circuit Factory )
