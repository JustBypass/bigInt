cmake_minimum_required(VERSION 3.9)
set(CMAKE_BUILD_TYPE "RDebug")
set(SOURCES main.cpp)

add_executable(static ${SOURCES})

target_link_libraries(static PUBLIC bigInt)


