cmake_minimum_required(VERSION 3.8)

project(library)

#file(GLOB_RECURSE SOURCE LIST_DIRECTORIES true *.h *.cpp)
set(lib bigInt.h bigInt.cpp myVector.h)

add_library(bigInt STATIC ${lib})

