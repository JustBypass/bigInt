cmake_minimum_required(VERSION 3.9)

set(SOURCES main.cpp)

add_executable(static ${SOURCES})

target_link_libraries(static bigInt2)


