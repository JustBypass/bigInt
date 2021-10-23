cmake_minimum_required(VERSION 3.8)

project(library)
set(maia ../main/main.cpp)

add_executable(../main ${maia})
set_target_properties(../main PROPERTIES LINKER_LANGUAGE CXX)
target_link_libraries(../main PUBLIC bigInt menus)


