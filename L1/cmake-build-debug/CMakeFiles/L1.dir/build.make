# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Clion\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Clion\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "E:\#Programming\C&C++\Grade2B-ALDS-Test\L1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "E:\#Programming\C&C++\Grade2B-ALDS-Test\L1\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/L1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/L1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/L1.dir/flags.make

CMakeFiles/L1.dir/main.c.obj: CMakeFiles/L1.dir/flags.make
CMakeFiles/L1.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="E:\#Programming\C&C++\Grade2B-ALDS-Test\L1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/L1.dir/main.c.obj"
	D:\Clion\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\L1.dir\main.c.obj   -c "E:\#Programming\C&C++\Grade2B-ALDS-Test\L1\main.c"

CMakeFiles/L1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/L1.dir/main.c.i"
	D:\Clion\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "E:\#Programming\C&C++\Grade2B-ALDS-Test\L1\main.c" > CMakeFiles\L1.dir\main.c.i

CMakeFiles/L1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/L1.dir/main.c.s"
	D:\Clion\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "E:\#Programming\C&C++\Grade2B-ALDS-Test\L1\main.c" -o CMakeFiles\L1.dir\main.c.s

# Object files for target L1
L1_OBJECTS = \
"CMakeFiles/L1.dir/main.c.obj"

# External object files for target L1
L1_EXTERNAL_OBJECTS =

L1.exe: CMakeFiles/L1.dir/main.c.obj
L1.exe: CMakeFiles/L1.dir/build.make
L1.exe: CMakeFiles/L1.dir/linklibs.rsp
L1.exe: CMakeFiles/L1.dir/objects1.rsp
L1.exe: CMakeFiles/L1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="E:\#Programming\C&C++\Grade2B-ALDS-Test\L1\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable L1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\L1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/L1.dir/build: L1.exe

.PHONY : CMakeFiles/L1.dir/build

CMakeFiles/L1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\L1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/L1.dir/clean

CMakeFiles/L1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "E:\#Programming\C&C++\Grade2B-ALDS-Test\L1" "E:\#Programming\C&C++\Grade2B-ALDS-Test\L1" "E:\#Programming\C&C++\Grade2B-ALDS-Test\L1\cmake-build-debug" "E:\#Programming\C&C++\Grade2B-ALDS-Test\L1\cmake-build-debug" "E:\#Programming\C&C++\Grade2B-ALDS-Test\L1\cmake-build-debug\CMakeFiles\L1.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/L1.dir/depend

