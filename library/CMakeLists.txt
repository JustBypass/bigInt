cmake_minimum_required(VERSION 3.8)

project(library)
set(lib "bigInt.h" "bigInt.cpp")

add_library(bigInt SHARED ${lib})

