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
CMAKE_SOURCE_DIR = /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/golomb_rulers.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/golomb_rulers.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/golomb_rulers.dir/flags.make

CMakeFiles/golomb_rulers.dir/main.cpp.o: CMakeFiles/golomb_rulers.dir/flags.make
CMakeFiles/golomb_rulers.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/golomb_rulers.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/golomb_rulers.dir/main.cpp.o -c /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/main.cpp

CMakeFiles/golomb_rulers.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/golomb_rulers.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/main.cpp > CMakeFiles/golomb_rulers.dir/main.cpp.i

CMakeFiles/golomb_rulers.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/golomb_rulers.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/main.cpp -o CMakeFiles/golomb_rulers.dir/main.cpp.s

CMakeFiles/golomb_rulers.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/golomb_rulers.dir/main.cpp.o.requires

CMakeFiles/golomb_rulers.dir/main.cpp.o.provides: CMakeFiles/golomb_rulers.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/golomb_rulers.dir/build.make CMakeFiles/golomb_rulers.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/golomb_rulers.dir/main.cpp.o.provides

CMakeFiles/golomb_rulers.dir/main.cpp.o.provides.build: CMakeFiles/golomb_rulers.dir/main.cpp.o


CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o: CMakeFiles/golomb_rulers.dir/flags.make
CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o: ../src/golomb_rulers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o -c /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/src/golomb_rulers.cpp

CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/src/golomb_rulers.cpp > CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.i

CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/src/golomb_rulers.cpp -o CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.s

CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o.requires:

.PHONY : CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o.requires

CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o.provides: CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o.requires
	$(MAKE) -f CMakeFiles/golomb_rulers.dir/build.make CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o.provides.build
.PHONY : CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o.provides

CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o.provides.build: CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o


# Object files for target golomb_rulers
golomb_rulers_OBJECTS = \
"CMakeFiles/golomb_rulers.dir/main.cpp.o" \
"CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o"

# External object files for target golomb_rulers
golomb_rulers_EXTERNAL_OBJECTS =

golomb_rulers: CMakeFiles/golomb_rulers.dir/main.cpp.o
golomb_rulers: CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o
golomb_rulers: CMakeFiles/golomb_rulers.dir/build.make
golomb_rulers: CMakeFiles/golomb_rulers.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable golomb_rulers"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/golomb_rulers.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/golomb_rulers.dir/build: golomb_rulers

.PHONY : CMakeFiles/golomb_rulers.dir/build

CMakeFiles/golomb_rulers.dir/requires: CMakeFiles/golomb_rulers.dir/main.cpp.o.requires
CMakeFiles/golomb_rulers.dir/requires: CMakeFiles/golomb_rulers.dir/src/golomb_rulers.cpp.o.requires

.PHONY : CMakeFiles/golomb_rulers.dir/requires

CMakeFiles/golomb_rulers.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/golomb_rulers.dir/cmake_clean.cmake
.PHONY : CMakeFiles/golomb_rulers.dir/clean

CMakeFiles/golomb_rulers.dir/depend:
	cd /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/cmake-build-debug /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/cmake-build-debug /home/kim/workspace/gecode/constraint_programming_gecode/a4/exp/golomb_rulers/cmake-build-debug/CMakeFiles/golomb_rulers.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/golomb_rulers.dir/depend

