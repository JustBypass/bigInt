cmake_minimum_required(VERSION 3.8)

project(library)

set(lib bigInt.h bigInt.cpp myVector.h functions.h Constructors.h)

add_library(bigInt SHARED ${lib})

