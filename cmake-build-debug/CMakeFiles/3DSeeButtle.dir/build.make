# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/107/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/107/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/3DSeeButtle.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/3DSeeButtle.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/3DSeeButtle.dir/flags.make

CMakeFiles/3DSeeButtle.dir/main.cpp.o: CMakeFiles/3DSeeButtle.dir/flags.make
CMakeFiles/3DSeeButtle.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/3DSeeButtle.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/3DSeeButtle.dir/main.cpp.o -c /home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle/main.cpp

CMakeFiles/3DSeeButtle.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/3DSeeButtle.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle/main.cpp > CMakeFiles/3DSeeButtle.dir/main.cpp.i

CMakeFiles/3DSeeButtle.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/3DSeeButtle.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle/main.cpp -o CMakeFiles/3DSeeButtle.dir/main.cpp.s

# Object files for target 3DSeeButtle
3DSeeButtle_OBJECTS = \
"CMakeFiles/3DSeeButtle.dir/main.cpp.o"

# External object files for target 3DSeeButtle
3DSeeButtle_EXTERNAL_OBJECTS =

3DSeeButtle: CMakeFiles/3DSeeButtle.dir/main.cpp.o
3DSeeButtle: CMakeFiles/3DSeeButtle.dir/build.make
3DSeeButtle: /usr/lib/x86_64-linux-gnu/libOpenGL.so
3DSeeButtle: /usr/lib/x86_64-linux-gnu/libGLX.so
3DSeeButtle: /usr/lib/x86_64-linux-gnu/libGLU.so
3DSeeButtle: /usr/lib/x86_64-linux-gnu/libglut.so
3DSeeButtle: /usr/lib/x86_64-linux-gnu/libXi.so
3DSeeButtle: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
3DSeeButtle: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.1
3DSeeButtle: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
3DSeeButtle: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
3DSeeButtle: CMakeFiles/3DSeeButtle.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 3DSeeButtle"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/3DSeeButtle.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/3DSeeButtle.dir/build: 3DSeeButtle

.PHONY : CMakeFiles/3DSeeButtle.dir/build

CMakeFiles/3DSeeButtle.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/3DSeeButtle.dir/cmake_clean.cmake
.PHONY : CMakeFiles/3DSeeButtle.dir/clean

CMakeFiles/3DSeeButtle.dir/depend:
	cd /home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle /home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle /home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle/cmake-build-debug /home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle/cmake-build-debug /home/alik/Documents/Programming/Repository/Roma3DButtle/3DSeeButtle/cmake-build-debug/CMakeFiles/3DSeeButtle.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/3DSeeButtle.dir/depend
