# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/code/Code/algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/code/Code/algorithm/build

# Include any dependencies generated for this target.
include src/CMakeFiles/test1.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/test1.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/test1.dir/flags.make

src/CMakeFiles/test1.dir/Fibonacci.cpp.o: src/CMakeFiles/test1.dir/flags.make
src/CMakeFiles/test1.dir/Fibonacci.cpp.o: ../src/Fibonacci.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/Code/algorithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/test1.dir/Fibonacci.cpp.o"
	cd /home/ubuntu/code/Code/algorithm/build/src && /usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test1.dir/Fibonacci.cpp.o -c /home/ubuntu/code/Code/algorithm/src/Fibonacci.cpp

src/CMakeFiles/test1.dir/Fibonacci.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test1.dir/Fibonacci.cpp.i"
	cd /home/ubuntu/code/Code/algorithm/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/Code/algorithm/src/Fibonacci.cpp > CMakeFiles/test1.dir/Fibonacci.cpp.i

src/CMakeFiles/test1.dir/Fibonacci.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test1.dir/Fibonacci.cpp.s"
	cd /home/ubuntu/code/Code/algorithm/build/src && /usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/Code/algorithm/src/Fibonacci.cpp -o CMakeFiles/test1.dir/Fibonacci.cpp.s

src/CMakeFiles/test1.dir/Fibonacci.cpp.o.requires:

.PHONY : src/CMakeFiles/test1.dir/Fibonacci.cpp.o.requires

src/CMakeFiles/test1.dir/Fibonacci.cpp.o.provides: src/CMakeFiles/test1.dir/Fibonacci.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/test1.dir/build.make src/CMakeFiles/test1.dir/Fibonacci.cpp.o.provides.build
.PHONY : src/CMakeFiles/test1.dir/Fibonacci.cpp.o.provides

src/CMakeFiles/test1.dir/Fibonacci.cpp.o.provides.build: src/CMakeFiles/test1.dir/Fibonacci.cpp.o


# Object files for target test1
test1_OBJECTS = \
"CMakeFiles/test1.dir/Fibonacci.cpp.o"

# External object files for target test1
test1_EXTERNAL_OBJECTS =

../bin/test1: src/CMakeFiles/test1.dir/Fibonacci.cpp.o
../bin/test1: src/CMakeFiles/test1.dir/build.make
../bin/test1: src/CMakeFiles/test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/code/Code/algorithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../bin/test1"
	cd /home/ubuntu/code/Code/algorithm/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/test1.dir/build: ../bin/test1

.PHONY : src/CMakeFiles/test1.dir/build

src/CMakeFiles/test1.dir/requires: src/CMakeFiles/test1.dir/Fibonacci.cpp.o.requires

.PHONY : src/CMakeFiles/test1.dir/requires

src/CMakeFiles/test1.dir/clean:
	cd /home/ubuntu/code/Code/algorithm/build/src && $(CMAKE_COMMAND) -P CMakeFiles/test1.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/test1.dir/clean

src/CMakeFiles/test1.dir/depend:
	cd /home/ubuntu/code/Code/algorithm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/code/Code/algorithm /home/ubuntu/code/Code/algorithm/src /home/ubuntu/code/Code/algorithm/build /home/ubuntu/code/Code/algorithm/build/src /home/ubuntu/code/Code/algorithm/build/src/CMakeFiles/test1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/test1.dir/depend
