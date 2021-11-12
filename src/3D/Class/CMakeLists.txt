cmake_minimum_required(VERSION 3.8)

project(library)

#file(GLOB_RECURSE SOURCE LIST_DIRECTORIES true *.h *.cpp)
set(lib Printed_Circuit_Board.h Printed_Circuit_Board.cpp )

add_library(Circuit STATIC ${lib})