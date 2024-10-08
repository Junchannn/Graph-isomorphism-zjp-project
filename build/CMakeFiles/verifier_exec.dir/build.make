# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Cryptography1/Cryptography/zkp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Cryptography1/Cryptography/zkp/build

# Include any dependencies generated for this target.
include CMakeFiles/verifier_exec.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/verifier_exec.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/verifier_exec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/verifier_exec.dir/flags.make

CMakeFiles/verifier_exec.dir/verifier.cpp.o: CMakeFiles/verifier_exec.dir/flags.make
CMakeFiles/verifier_exec.dir/verifier.cpp.o: ../verifier.cpp
CMakeFiles/verifier_exec.dir/verifier.cpp.o: CMakeFiles/verifier_exec.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Cryptography1/Cryptography/zkp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/verifier_exec.dir/verifier.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/verifier_exec.dir/verifier.cpp.o -MF CMakeFiles/verifier_exec.dir/verifier.cpp.o.d -o CMakeFiles/verifier_exec.dir/verifier.cpp.o -c /mnt/c/Cryptography1/Cryptography/zkp/verifier.cpp

CMakeFiles/verifier_exec.dir/verifier.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/verifier_exec.dir/verifier.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Cryptography1/Cryptography/zkp/verifier.cpp > CMakeFiles/verifier_exec.dir/verifier.cpp.i

CMakeFiles/verifier_exec.dir/verifier.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/verifier_exec.dir/verifier.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Cryptography1/Cryptography/zkp/verifier.cpp -o CMakeFiles/verifier_exec.dir/verifier.cpp.s

# Object files for target verifier_exec
verifier_exec_OBJECTS = \
"CMakeFiles/verifier_exec.dir/verifier.cpp.o"

# External object files for target verifier_exec
verifier_exec_EXTERNAL_OBJECTS =

verifier/verifier_exec: CMakeFiles/verifier_exec.dir/verifier.cpp.o
verifier/verifier_exec: CMakeFiles/verifier_exec.dir/build.make
verifier/verifier_exec: libGraph_zkp.a
verifier/verifier_exec: CMakeFiles/verifier_exec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Cryptography1/Cryptography/zkp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable verifier/verifier_exec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/verifier_exec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/verifier_exec.dir/build: verifier/verifier_exec
.PHONY : CMakeFiles/verifier_exec.dir/build

CMakeFiles/verifier_exec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/verifier_exec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/verifier_exec.dir/clean

CMakeFiles/verifier_exec.dir/depend:
	cd /mnt/c/Cryptography1/Cryptography/zkp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Cryptography1/Cryptography/zkp /mnt/c/Cryptography1/Cryptography/zkp /mnt/c/Cryptography1/Cryptography/zkp/build /mnt/c/Cryptography1/Cryptography/zkp/build /mnt/c/Cryptography1/Cryptography/zkp/build/CMakeFiles/verifier_exec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/verifier_exec.dir/depend

