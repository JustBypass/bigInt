cmake_minimum_required(VERSION 3.9 )


set(CMAKE_CXX_STANDARD 20)
#project(projectx LANGUAGES CXX)
#add_subdirectory(TestLib)

    set(SOURCES test.cpp)
    add_executable(DynT ${SOURCES})
    target_link_libraries(
        DynT
        PUBLIC
        gtest_main
        bigInt2
       # testLib
    )
    add_test(
        NAME DynT
        COMMAND DynT
    )
