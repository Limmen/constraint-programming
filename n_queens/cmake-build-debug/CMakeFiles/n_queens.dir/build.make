# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/local/clion-2016.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/clion-2016.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/n_queens.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/n_queens.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/n_queens.dir/flags.make

CMakeFiles/n_queens.dir/src/main.cpp.o: CMakeFiles/n_queens.dir/flags.make
CMakeFiles/n_queens.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/n_queens.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/n_queens.dir/src/main.cpp.o -c /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens/src/main.cpp

CMakeFiles/n_queens.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/n_queens.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens/src/main.cpp > CMakeFiles/n_queens.dir/src/main.cpp.i

CMakeFiles/n_queens.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/n_queens.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens/src/main.cpp -o CMakeFiles/n_queens.dir/src/main.cpp.s

CMakeFiles/n_queens.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/n_queens.dir/src/main.cpp.o.requires

CMakeFiles/n_queens.dir/src/main.cpp.o.provides: CMakeFiles/n_queens.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/n_queens.dir/build.make CMakeFiles/n_queens.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/n_queens.dir/src/main.cpp.o.provides

CMakeFiles/n_queens.dir/src/main.cpp.o.provides.build: CMakeFiles/n_queens.dir/src/main.cpp.o


# Object files for target n_queens
n_queens_OBJECTS = \
"CMakeFiles/n_queens.dir/src/main.cpp.o"

# External object files for target n_queens
n_queens_EXTERNAL_OBJECTS =

n_queens: CMakeFiles/n_queens.dir/src/main.cpp.o
n_queens: CMakeFiles/n_queens.dir/build.make
n_queens: CMakeFiles/n_queens.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable n_queens"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/n_queens.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/n_queens.dir/build: n_queens

.PHONY : CMakeFiles/n_queens.dir/build

CMakeFiles/n_queens.dir/requires: CMakeFiles/n_queens.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/n_queens.dir/requires

CMakeFiles/n_queens.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/n_queens.dir/cmake_clean.cmake
.PHONY : CMakeFiles/n_queens.dir/clean

CMakeFiles/n_queens.dir/depend:
	cd /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens/cmake-build-debug /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens/cmake-build-debug /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/n_queens/cmake-build-debug/CMakeFiles/n_queens.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/n_queens.dir/depend
