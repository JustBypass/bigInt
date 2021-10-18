cmake_minimum_required(VERSION 3.8)

project(library)
set(maia "main.cpp")

add_executable(main ${maia})

target_link_libraries(main bigInt)


