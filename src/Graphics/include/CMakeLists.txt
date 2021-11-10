
cmake_minimum_required(VERSION 3.9)

set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.12.10\\5.12.10\\msvc2017_64\\lib\\cmake")
set(Qt5_DIR "C:\\Qt\\Qt5.12.10\\5.12.10\\msvc2017_64\\lib\\cmake\\Qt5")


project(projr LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
find_package(Qt5Core)
find_package(Qt5Widgets)
find_package(Qt5Multimedia)

add_library(libach ../src/menu.h
        ../src/menu.cpp
        ../src/errors.h
        ../src/second.h
        Qt5::Core Qt5::Widgets Qt5::Multimedia bigInt2
        )
