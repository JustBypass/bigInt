cmake_minimum_required(VERSION 3.8)

set(HEADERS menu.h)

add_library(menus SHARED ${HEADERS})
set_target_properties(menus PROPERTIES LINKER_LANGUAGE CXX)
