cmake_minimum_required(VERSION 3.8)

project(library)

#file(GLOB_RECURSE SOURCE LIST_DIRECTORIES true *.h *.cpp)
set(lib bigInt2.h bigInt2.cpp myVector.h)

add_library(bigInt2 STATIC ${lib})

