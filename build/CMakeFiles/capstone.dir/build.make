# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/sammaus/ubuntu_projects/udacity_capstone_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sammaus/ubuntu_projects/udacity_capstone_project/build

# Include any dependencies generated for this target.
include CMakeFiles/capstone.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/capstone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/capstone.dir/flags.make

CMakeFiles/capstone.dir/src/app_gui.cpp.o: CMakeFiles/capstone.dir/flags.make
CMakeFiles/capstone.dir/src/app_gui.cpp.o: ../src/app_gui.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sammaus/ubuntu_projects/udacity_capstone_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/capstone.dir/src/app_gui.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/capstone.dir/src/app_gui.cpp.o -c /home/sammaus/ubuntu_projects/udacity_capstone_project/src/app_gui.cpp

CMakeFiles/capstone.dir/src/app_gui.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/capstone.dir/src/app_gui.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sammaus/ubuntu_projects/udacity_capstone_project/src/app_gui.cpp > CMakeFiles/capstone.dir/src/app_gui.cpp.i

CMakeFiles/capstone.dir/src/app_gui.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/capstone.dir/src/app_gui.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sammaus/ubuntu_projects/udacity_capstone_project/src/app_gui.cpp -o CMakeFiles/capstone.dir/src/app_gui.cpp.s

CMakeFiles/capstone.dir/src/stack.cpp.o: CMakeFiles/capstone.dir/flags.make
CMakeFiles/capstone.dir/src/stack.cpp.o: ../src/stack.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sammaus/ubuntu_projects/udacity_capstone_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/capstone.dir/src/stack.cpp.o"
	/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/capstone.dir/src/stack.cpp.o -c /home/sammaus/ubuntu_projects/udacity_capstone_project/src/stack.cpp

CMakeFiles/capstone.dir/src/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/capstone.dir/src/stack.cpp.i"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sammaus/ubuntu_projects/udacity_capstone_project/src/stack.cpp > CMakeFiles/capstone.dir/src/stack.cpp.i

CMakeFiles/capstone.dir/src/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/capstone.dir/src/stack.cpp.s"
	/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sammaus/ubuntu_projects/udacity_capstone_project/src/stack.cpp -o CMakeFiles/capstone.dir/src/stack.cpp.s

# Object files for target capstone
capstone_OBJECTS = \
"CMakeFiles/capstone.dir/src/app_gui.cpp.o" \
"CMakeFiles/capstone.dir/src/stack.cpp.o"

# External object files for target capstone
capstone_EXTERNAL_OBJECTS =

capstone: CMakeFiles/capstone.dir/src/app_gui.cpp.o
capstone: CMakeFiles/capstone.dir/src/stack.cpp.o
capstone: CMakeFiles/capstone.dir/build.make
capstone: CMakeFiles/capstone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sammaus/ubuntu_projects/udacity_capstone_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable capstone"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/capstone.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/capstone.dir/build: capstone

.PHONY : CMakeFiles/capstone.dir/build

CMakeFiles/capstone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/capstone.dir/cmake_clean.cmake
.PHONY : CMakeFiles/capstone.dir/clean

CMakeFiles/capstone.dir/depend:
	cd /home/sammaus/ubuntu_projects/udacity_capstone_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sammaus/ubuntu_projects/udacity_capstone_project /home/sammaus/ubuntu_projects/udacity_capstone_project /home/sammaus/ubuntu_projects/udacity_capstone_project/build /home/sammaus/ubuntu_projects/udacity_capstone_project/build /home/sammaus/ubuntu_projects/udacity_capstone_project/build/CMakeFiles/capstone.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/capstone.dir/depend

