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
CMAKE_SOURCE_DIR = /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/send_more_money_2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/send_more_money_2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/send_more_money_2.dir/flags.make

CMakeFiles/send_more_money_2.dir/main.cpp.o: CMakeFiles/send_more_money_2.dir/flags.make
CMakeFiles/send_more_money_2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/send_more_money_2.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/send_more_money_2.dir/main.cpp.o -c /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2/main.cpp

CMakeFiles/send_more_money_2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/send_more_money_2.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2/main.cpp > CMakeFiles/send_more_money_2.dir/main.cpp.i

CMakeFiles/send_more_money_2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/send_more_money_2.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2/main.cpp -o CMakeFiles/send_more_money_2.dir/main.cpp.s

CMakeFiles/send_more_money_2.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/send_more_money_2.dir/main.cpp.o.requires

CMakeFiles/send_more_money_2.dir/main.cpp.o.provides: CMakeFiles/send_more_money_2.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/send_more_money_2.dir/build.make CMakeFiles/send_more_money_2.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/send_more_money_2.dir/main.cpp.o.provides

CMakeFiles/send_more_money_2.dir/main.cpp.o.provides.build: CMakeFiles/send_more_money_2.dir/main.cpp.o


# Object files for target send_more_money_2
send_more_money_2_OBJECTS = \
"CMakeFiles/send_more_money_2.dir/main.cpp.o"

# External object files for target send_more_money_2
send_more_money_2_EXTERNAL_OBJECTS =

send_more_money_2: CMakeFiles/send_more_money_2.dir/main.cpp.o
send_more_money_2: CMakeFiles/send_more_money_2.dir/build.make
send_more_money_2: CMakeFiles/send_more_money_2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable send_more_money_2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/send_more_money_2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/send_more_money_2.dir/build: send_more_money_2

.PHONY : CMakeFiles/send_more_money_2.dir/build

CMakeFiles/send_more_money_2.dir/requires: CMakeFiles/send_more_money_2.dir/main.cpp.o.requires

.PHONY : CMakeFiles/send_more_money_2.dir/requires

CMakeFiles/send_more_money_2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/send_more_money_2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/send_more_money_2.dir/clean

CMakeFiles/send_more_money_2.dir/depend:
	cd /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2 /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2 /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2/cmake-build-debug /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2/cmake-build-debug /home/kim/workspace/gecode/constraint_programming_gecode/a1/exp/send_more_money_2/cmake-build-debug/CMakeFiles/send_more_money_2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/send_more_money_2.dir/depend

