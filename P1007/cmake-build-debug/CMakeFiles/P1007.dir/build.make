# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /workspace/github/Poj/P1007

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspace/github/Poj/P1007/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/P1007.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/P1007.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/P1007.dir/flags.make

CMakeFiles/P1007.dir/main.cpp.o: CMakeFiles/P1007.dir/flags.make
CMakeFiles/P1007.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspace/github/Poj/P1007/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/P1007.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/P1007.dir/main.cpp.o -c /workspace/github/Poj/P1007/main.cpp

CMakeFiles/P1007.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/P1007.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspace/github/Poj/P1007/main.cpp > CMakeFiles/P1007.dir/main.cpp.i

CMakeFiles/P1007.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/P1007.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspace/github/Poj/P1007/main.cpp -o CMakeFiles/P1007.dir/main.cpp.s

CMakeFiles/P1007.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/P1007.dir/main.cpp.o.requires

CMakeFiles/P1007.dir/main.cpp.o.provides: CMakeFiles/P1007.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/P1007.dir/build.make CMakeFiles/P1007.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/P1007.dir/main.cpp.o.provides

CMakeFiles/P1007.dir/main.cpp.o.provides.build: CMakeFiles/P1007.dir/main.cpp.o


# Object files for target P1007
P1007_OBJECTS = \
"CMakeFiles/P1007.dir/main.cpp.o"

# External object files for target P1007
P1007_EXTERNAL_OBJECTS =

P1007: CMakeFiles/P1007.dir/main.cpp.o
P1007: CMakeFiles/P1007.dir/build.make
P1007: CMakeFiles/P1007.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspace/github/Poj/P1007/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable P1007"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/P1007.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/P1007.dir/build: P1007

.PHONY : CMakeFiles/P1007.dir/build

CMakeFiles/P1007.dir/requires: CMakeFiles/P1007.dir/main.cpp.o.requires

.PHONY : CMakeFiles/P1007.dir/requires

CMakeFiles/P1007.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/P1007.dir/cmake_clean.cmake
.PHONY : CMakeFiles/P1007.dir/clean

CMakeFiles/P1007.dir/depend:
	cd /workspace/github/Poj/P1007/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspace/github/Poj/P1007 /workspace/github/Poj/P1007 /workspace/github/Poj/P1007/cmake-build-debug /workspace/github/Poj/P1007/cmake-build-debug /workspace/github/Poj/P1007/cmake-build-debug/CMakeFiles/P1007.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/P1007.dir/depend

