# CMake generated Testfile for 
# Source directory: C:/Users/Admin/CLionProjects/untitled12/bigInt/src/UnitTests
# Build directory: C:/Users/Admin/CLionProjects/untitled12/bigInt/build/src/UnitTests
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(DynT "C:/Users/Admin/CLionProjects/untitled12/bigInt/build/src/UnitTests/Debug/DynT.exe")
  set_tests_properties(DynT PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Admin/CLionProjects/untitled12/bigInt/src/UnitTests/CMakeLists.txt;17;add_test;C:/Users/Admin/CLionProjects/untitled12/bigInt/src/UnitTests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(DynT "C:/Users/Admin/CLionProjects/untitled12/bigInt/build/src/UnitTests/Release/DynT.exe")
  set_tests_properties(DynT PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Admin/CLionProjects/untitled12/bigInt/src/UnitTests/CMakeLists.txt;17;add_test;C:/Users/Admin/CLionProjects/untitled12/bigInt/src/UnitTests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(DynT "C:/Users/Admin/CLionProjects/untitled12/bigInt/build/src/UnitTests/MinSizeRel/DynT.exe")
  set_tests_properties(DynT PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Admin/CLionProjects/untitled12/bigInt/src/UnitTests/CMakeLists.txt;17;add_test;C:/Users/Admin/CLionProjects/untitled12/bigInt/src/UnitTests/CMakeLists.txt;0;")
elseif("${CTEST_CONFIGURATION_TYPE}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(DynT "C:/Users/Admin/CLionProjects/untitled12/bigInt/build/src/UnitTests/RelWithDebInfo/DynT.exe")
  set_tests_properties(DynT PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Admin/CLionProjects/untitled12/bigInt/src/UnitTests/CMakeLists.txt;17;add_test;C:/Users/Admin/CLionProjects/untitled12/bigInt/src/UnitTests/CMakeLists.txt;0;")
else()
  add_test(DynT NOT_AVAILABLE)
endif()
