cmake_minimum_required(VERSION 3.9)

set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.12.10\\5.12.10\\msvc2017_64\\lib\\cmake")
set(Qt5_DIR "C:\\Qt\\Qt5.12.10\\5.12.10\\msvc2017_64\\lib\\cmake\\Qt5")

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
##et(CMAKE_AUTOUIC ON)


# set up a mapping so that the Release configuration for the Qt imported target is
# used in the COVERAGE CMake configuration.
#et(CMAKE_BUILD_TYPE "Debug")


add_library(libcma STATIC but.cpp but.h )