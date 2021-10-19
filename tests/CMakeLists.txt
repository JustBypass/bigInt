cmake_minimum_required(VERSION 3.9 )

project(tests)
set(CMAKE_CXX_STANDARD 20)
add_subdirectory(googletest)
enable_testing()
include_directories(${GTEST_SOURCE_DIR}\\include ${GTEST_SOURCE_DIR} )
add_executable(runTest  test.cpp)

target_link_libraries(runTest bigInt gtest gtest_main )

add_test(
        NAME runTest
        COMMAND runTest
)