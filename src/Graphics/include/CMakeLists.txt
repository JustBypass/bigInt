cmake_minimum_required(VERSION 3.9)


#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
##et(CMAKE_AUTOUIC ON)


# set up a mapping so that the Release configuration for the Qt imported target is
# used in the COVERAGE CMake configuration.
#et(CMAKE_BUILD_TYPE "Debug")


add_library(lib STATIC  but.h but.cpp)