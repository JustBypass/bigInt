# CMake generated Testfile for 
# Source directory: C:/Qt/Qt5.12.10/cmake_tur/tests
# Build directory: C:/Qt/Qt5.12.10/cmake_tur/build/tests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(testy "C:/Qt/Qt5.12.10/cmake_tur/build/tests/Debug/testy.exe")
  set_tests_properties(testy PROPERTIES  _BACKTRACE_TRIPLES "C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;18;add_test;C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(testy "C:/Qt/Qt5.12.10/cmake_tur/build/tests/Release/testy.exe")
  set_tests_properties(testy PROPERTIES  _BACKTRACE_TRIPLES "C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;18;add_test;C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(testy "C:/Qt/Qt5.12.10/cmake_tur/build/tests/MinSizeRel/testy.exe")
  set_tests_properties(testy PROPERTIES  _BACKTRACE_TRIPLES "C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;18;add_test;C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(testy "C:/Qt/Qt5.12.10/cmake_tur/build/tests/RelWithDebInfo/testy.exe")
  set_tests_properties(testy PROPERTIES  _BACKTRACE_TRIPLES "C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;18;add_test;C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;0;")
else()
  add_test(testy NOT_AVAILABLE)
endif()
