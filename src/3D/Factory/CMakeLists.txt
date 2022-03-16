cmake_minimum_required(VERSION 3.8)

project(Fact)

#file(GLOB_RECURSE SOURCE LIST_DIRECTORIES true *.h *.cpp)
set(lib Factory.h Factory.cpp )

add_library(Factory STATIC ${lib})