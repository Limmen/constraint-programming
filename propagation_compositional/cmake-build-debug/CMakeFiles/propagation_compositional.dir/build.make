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
CMAKE_SOURCE_DIR = /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/propagation_compositional.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/propagation_compositional.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/propagation_compositional.dir/flags.make

CMakeFiles/propagation_compositional.dir/src/main.cpp.o: CMakeFiles/propagation_compositional.dir/flags.make
CMakeFiles/propagation_compositional.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/propagation_compositional.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/propagation_compositional.dir/src/main.cpp.o -c /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional/src/main.cpp

CMakeFiles/propagation_compositional.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/propagation_compositional.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional/src/main.cpp > CMakeFiles/propagation_compositional.dir/src/main.cpp.i

CMakeFiles/propagation_compositional.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/propagation_compositional.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional/src/main.cpp -o CMakeFiles/propagation_compositional.dir/src/main.cpp.s

CMakeFiles/propagation_compositional.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/propagation_compositional.dir/src/main.cpp.o.requires

CMakeFiles/propagation_compositional.dir/src/main.cpp.o.provides: CMakeFiles/propagation_compositional.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/propagation_compositional.dir/build.make CMakeFiles/propagation_compositional.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/propagation_compositional.dir/src/main.cpp.o.provides

CMakeFiles/propagation_compositional.dir/src/main.cpp.o.provides.build: CMakeFiles/propagation_compositional.dir/src/main.cpp.o


# Object files for target propagation_compositional
propagation_compositional_OBJECTS = \
"CMakeFiles/propagation_compositional.dir/src/main.cpp.o"

# External object files for target propagation_compositional
propagation_compositional_EXTERNAL_OBJECTS =

propagation_compositional: CMakeFiles/propagation_compositional.dir/src/main.cpp.o
propagation_compositional: CMakeFiles/propagation_compositional.dir/build.make
propagation_compositional: CMakeFiles/propagation_compositional.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable propagation_compositional"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/propagation_compositional.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/propagation_compositional.dir/build: propagation_compositional

.PHONY : CMakeFiles/propagation_compositional.dir/build

CMakeFiles/propagation_compositional.dir/requires: CMakeFiles/propagation_compositional.dir/src/main.cpp.o.requires

.PHONY : CMakeFiles/propagation_compositional.dir/requires

CMakeFiles/propagation_compositional.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/propagation_compositional.dir/cmake_clean.cmake
.PHONY : CMakeFiles/propagation_compositional.dir/clean

CMakeFiles/propagation_compositional.dir/depend:
	cd /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional/cmake-build-debug /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional/cmake-build-debug /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/propagation_compositional/cmake-build-debug/CMakeFiles/propagation_compositional.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/propagation_compositional.dir/depend

