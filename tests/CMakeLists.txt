cmake_minimum_required(VERSION 3.9 )


set(CMAKE_CXX_STANDARD 20)



set(SOURCES test.cpp)
add_executable(testy ${SOURCES})

target_link_libraries(
        testy
        PUBLIC
        gtest_main
        bigInt
)
add_test(
        NAME testy
        COMMAND testy
)
