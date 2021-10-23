cmake_minimum_required(VERSION 3.9 )


set(CMAKE_CXX_STANDARD 20)

set(VAR 1)

if(${VAR} EQUAL 1)
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
else()
    set(SOURCES test_dynamic.cpp)
    add_executable(testy ${SOURCES})
    target_link_libraries(
            testy
            PUBLIC
            gtest_main
            bigInt2
    )
    add_test(
            NAME testy
            COMMAND testy
    )
endif()