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
CMAKE_COMMAND = /home/yassatamer/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7846.88/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/yassatamer/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/201.7846.88/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yassatamer/CLionProjects/taskclndr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yassatamer/CLionProjects/taskclndr/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/taskclndr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/taskclndr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/taskclndr.dir/flags.make

CMakeFiles/taskclndr.dir/main.cpp.o: CMakeFiles/taskclndr.dir/flags.make
CMakeFiles/taskclndr.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yassatamer/CLionProjects/taskclndr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/taskclndr.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/taskclndr.dir/main.cpp.o -c /home/yassatamer/CLionProjects/taskclndr/main.cpp

CMakeFiles/taskclndr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/taskclndr.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yassatamer/CLionProjects/taskclndr/main.cpp > CMakeFiles/taskclndr.dir/main.cpp.i

CMakeFiles/taskclndr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/taskclndr.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yassatamer/CLionProjects/taskclndr/main.cpp -o CMakeFiles/taskclndr.dir/main.cpp.s

# Object files for target taskclndr
taskclndr_OBJECTS = \
"CMakeFiles/taskclndr.dir/main.cpp.o"

# External object files for target taskclndr
taskclndr_EXTERNAL_OBJECTS =

taskclndr: CMakeFiles/taskclndr.dir/main.cpp.o
taskclndr: CMakeFiles/taskclndr.dir/build.make
taskclndr: CMakeFiles/taskclndr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yassatamer/CLionProjects/taskclndr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable taskclndr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/taskclndr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/taskclndr.dir/build: taskclndr

.PHONY : CMakeFiles/taskclndr.dir/build

CMakeFiles/taskclndr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/taskclndr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/taskclndr.dir/clean

CMakeFiles/taskclndr.dir/depend:
	cd /home/yassatamer/CLionProjects/taskclndr/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yassatamer/CLionProjects/taskclndr /home/yassatamer/CLionProjects/taskclndr /home/yassatamer/CLionProjects/taskclndr/cmake-build-debug /home/yassatamer/CLionProjects/taskclndr/cmake-build-debug /home/yassatamer/CLionProjects/taskclndr/cmake-build-debug/CMakeFiles/taskclndr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/taskclndr.dir/depend

