# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Qt\Qt5.12.10\cmake_tur

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Qt\Qt5.12.10\cmake_tur\cmake-build-debug

# Include any dependencies generated for this target.
include include\menu\CMakeFiles\menus.dir\depend.make
# Include the progress variables for this target.
include include\menu\CMakeFiles\menus.dir\progress.make

# Include the compile flags for this target's objects.
include include\menu\CMakeFiles\menus.dir\flags.make

# Object files for target menus
menus_OBJECTS =

# External object files for target menus
menus_EXTERNAL_OBJECTS =

include\menu\menus.lib: include\menu\CMakeFiles\menus.dir\build.make
include\menu\menus.lib: include\menu\CMakeFiles\menus.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Qt\Qt5.12.10\cmake_tur\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library menus.lib"
	cd C:\Qt\Qt5.12.10\cmake_tur\cmake-build-debug\include\menu
	$(CMAKE_COMMAND) -P CMakeFiles\menus.dir\cmake_clean_target.cmake
	cd C:\Qt\Qt5.12.10\cmake_tur\cmake-build-debug
	cd C:\Qt\Qt5.12.10\cmake_tur\cmake-build-debug\include\menu
	C:\PROGRA~2\MIB055~1\2019\COMMUN~1\VC\Tools\MSVC\1429~1.301\bin\Hostx86\x86\lib.exe /nologo /machine:X86 /out:menus.lib @CMakeFiles\menus.dir\objects1.rsp 
	cd C:\Qt\Qt5.12.10\cmake_tur\cmake-build-debug

# Rule to build all files generated by this target.
include\menu\CMakeFiles\menus.dir\build: include\menu\menus.lib
.PHONY : include\menu\CMakeFiles\menus.dir\build

include\menu\CMakeFiles\menus.dir\clean:
	cd C:\Qt\Qt5.12.10\cmake_tur\cmake-build-debug\include\menu
	$(CMAKE_COMMAND) -P CMakeFiles\menus.dir\cmake_clean.cmake
	cd C:\Qt\Qt5.12.10\cmake_tur\cmake-build-debug
.PHONY : include\menu\CMakeFiles\menus.dir\clean

include\menu\CMakeFiles\menus.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Qt\Qt5.12.10\cmake_tur C:\Qt\Qt5.12.10\cmake_tur\include\menu C:\Qt\Qt5.12.10\cmake_tur\cmake-build-debug C:\Qt\Qt5.12.10\cmake_tur\cmake-build-debug\include\menu C:\Qt\Qt5.12.10\cmake_tur\cmake-build-debug\include\menu\CMakeFiles\menus.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : include\menu\CMakeFiles\menus.dir\depend
