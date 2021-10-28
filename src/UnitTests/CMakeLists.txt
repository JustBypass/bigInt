cmake_minimum_required(VERSION 3.9 )


set(CMAKE_CXX_STANDARD 20)

set(VAR 1)

if(${VAR} EQUAL 1)
    set(SOURCES test.cpp)
    add_executable(DynT ${SOURCES})
    target_link_libraries(
        DynT
        PUBLIC
        gtest_main
        bigInt2
    )
    add_test(
        NAME DynT
        COMMAND DynT
    )
else()
    set(SOURCES test.cpp)
    add_executable(StatT ${SOURCES})
    target_link_libraries(
            StatT
            PUBLIC
            gtest_main
            bigInt
    )
    add_test(
            NAME StatT
            COMMAND StatT
    )
endif()