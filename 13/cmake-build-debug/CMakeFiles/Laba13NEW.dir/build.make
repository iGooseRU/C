# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\IDE\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\IDE\CLion 2020.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Egor\ITMO\Labs\Proga\Laba13NEW

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Egor\ITMO\Labs\Proga\Laba13NEW\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Laba13NEW.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Laba13NEW.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Laba13NEW.dir/flags.make

CMakeFiles/Laba13NEW.dir/main.c.obj: CMakeFiles/Laba13NEW.dir/flags.make
CMakeFiles/Laba13NEW.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Egor\ITMO\Labs\Proga\Laba13NEW\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Laba13NEW.dir/main.c.obj"
	C:\IDE\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Laba13NEW.dir\main.c.obj   -c C:\Egor\ITMO\Labs\Proga\Laba13NEW\main.c

CMakeFiles/Laba13NEW.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Laba13NEW.dir/main.c.i"
	C:\IDE\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Egor\ITMO\Labs\Proga\Laba13NEW\main.c > CMakeFiles\Laba13NEW.dir\main.c.i

CMakeFiles/Laba13NEW.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Laba13NEW.dir/main.c.s"
	C:\IDE\MinGW\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Egor\ITMO\Labs\Proga\Laba13NEW\main.c -o CMakeFiles\Laba13NEW.dir\main.c.s

# Object files for target Laba13NEW
Laba13NEW_OBJECTS = \
"CMakeFiles/Laba13NEW.dir/main.c.obj"

# External object files for target Laba13NEW
Laba13NEW_EXTERNAL_OBJECTS =

Laba13NEW.exe: CMakeFiles/Laba13NEW.dir/main.c.obj
Laba13NEW.exe: CMakeFiles/Laba13NEW.dir/build.make
Laba13NEW.exe: CMakeFiles/Laba13NEW.dir/linklibs.rsp
Laba13NEW.exe: CMakeFiles/Laba13NEW.dir/objects1.rsp
Laba13NEW.exe: CMakeFiles/Laba13NEW.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Egor\ITMO\Labs\Proga\Laba13NEW\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Laba13NEW.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Laba13NEW.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Laba13NEW.dir/build: Laba13NEW.exe

.PHONY : CMakeFiles/Laba13NEW.dir/build

CMakeFiles/Laba13NEW.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Laba13NEW.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Laba13NEW.dir/clean

CMakeFiles/Laba13NEW.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Egor\ITMO\Labs\Proga\Laba13NEW C:\Egor\ITMO\Labs\Proga\Laba13NEW C:\Egor\ITMO\Labs\Proga\Laba13NEW\cmake-build-debug C:\Egor\ITMO\Labs\Proga\Laba13NEW\cmake-build-debug C:\Egor\ITMO\Labs\Proga\Laba13NEW\cmake-build-debug\CMakeFiles\Laba13NEW.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Laba13NEW.dir/depend
