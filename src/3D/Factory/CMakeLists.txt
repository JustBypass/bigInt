cmake_minimum_required(VERSION 3.8)

project(Fact)

#file(GLOB_RECURSE SOURCE LIST_DIRECTORIES true *.h *.cpp)
set(lib Factory.cpp Factory.h)

add_library(Factory STATIC ${lib})