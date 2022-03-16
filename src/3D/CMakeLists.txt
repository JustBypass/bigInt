cmake_minimum_required(VERSION 3.8)

project(3D LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
#project(proj LANGUAGES C#XX)

#qt5_add_resources(qrc resource.qrc) Ресурсы не обязательно добавлять
add_subdirectory(Class)
add_subdirectory(Factory)
add_executable(projec
         main.cpp
        )
target_link_libraries(projec  Circuit Factory ) 

