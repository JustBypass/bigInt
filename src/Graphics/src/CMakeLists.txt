cmake_minimum_required(VERSION 3.9)

set(CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.12.10\\5.12.10\\msvc2017_64\\lib\\cmake")
set(Qt5_DIR "C:\\Qt\\Qt5.12.10\\5.12.10\\msvc2017_64\\lib\\cmake\\Qt5")

#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#et(CMAKE_AUTOUIC ON)


# set up a mapping so that the Release configuration for the Qt imported target is
# used in the COVERAGE CMake configuration.
#et(CMAKE_BUILD_TYPE "Debug")
find_package(Qt5Core REQUIRED)
#find_package(Qt5 COMPONENTS Widgets REQUIRED)


find_package(Qt5Gui REQUIRED)

find_package(Qt5Widgets REQUIRED)

set(SOURCES main.cpp)
add_executable(main ${SOURCES})

target_link_libraries(main Qt5::Core)
target_link_libraries(main Qt5::Gui)
target_link_libraries(main Qt5::Widgets)
#target_link_libraries(main Qt5::QComboBox)


target_link_libraries(main lib)
#target_link_libraries(main bigInt)