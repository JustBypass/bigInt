# CMake generated Testfile for 
# Source directory: C:/Qt/Qt5.12.10/cmake_tur/tests
# Build directory: C:/Qt/Qt5.12.10/cmake_tur/tests/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(runTest "C:/Qt/Qt5.12.10/cmake_tur/tests/build/Debug/runTest.exe")
  set_tests_properties(runTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;12;add_test;C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(runTest "C:/Qt/Qt5.12.10/cmake_tur/tests/build/Release/runTest.exe")
  set_tests_properties(runTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;12;add_test;C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(runTest "C:/Qt/Qt5.12.10/cmake_tur/tests/build/MinSizeRel/runTest.exe")
  set_tests_properties(runTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;12;add_test;C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(runTest "C:/Qt/Qt5.12.10/cmake_tur/tests/build/RelWithDebInfo/runTest.exe")
  set_tests_properties(runTest PROPERTIES  _BACKTRACE_TRIPLES "C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;12;add_test;C:/Qt/Qt5.12.10/cmake_tur/tests/CMakeLists.txt;0;")
else()
  add_test(runTest NOT_AVAILABLE)
endif()
subdirs("googletest")
