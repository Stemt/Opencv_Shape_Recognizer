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
CMAKE_SOURCE_DIR = /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/build

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/src/main.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/app.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/src/main.cpp.o -c /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/main.cpp

CMakeFiles/app.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/main.cpp > CMakeFiles/app.dir/src/main.cpp.i

CMakeFiles/app.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/main.cpp -o CMakeFiles/app.dir/src/main.cpp.s

CMakeFiles/app.dir/src/ImageDisplay.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/ImageDisplay.cpp.o: ../src/ImageDisplay.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/app.dir/src/ImageDisplay.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/src/ImageDisplay.cpp.o -c /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/ImageDisplay.cpp

CMakeFiles/app.dir/src/ImageDisplay.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/ImageDisplay.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/ImageDisplay.cpp > CMakeFiles/app.dir/src/ImageDisplay.cpp.i

CMakeFiles/app.dir/src/ImageDisplay.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/ImageDisplay.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/ImageDisplay.cpp -o CMakeFiles/app.dir/src/ImageDisplay.cpp.s

CMakeFiles/app.dir/src/CommandInterpreter.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/CommandInterpreter.cpp.o: ../src/CommandInterpreter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/app.dir/src/CommandInterpreter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/src/CommandInterpreter.cpp.o -c /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/CommandInterpreter.cpp

CMakeFiles/app.dir/src/CommandInterpreter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/CommandInterpreter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/CommandInterpreter.cpp > CMakeFiles/app.dir/src/CommandInterpreter.cpp.i

CMakeFiles/app.dir/src/CommandInterpreter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/CommandInterpreter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/CommandInterpreter.cpp -o CMakeFiles/app.dir/src/CommandInterpreter.cpp.s

CMakeFiles/app.dir/src/Tokenizer.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/Tokenizer.cpp.o: ../src/Tokenizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/app.dir/src/Tokenizer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/src/Tokenizer.cpp.o -c /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/Tokenizer.cpp

CMakeFiles/app.dir/src/Tokenizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/Tokenizer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/Tokenizer.cpp > CMakeFiles/app.dir/src/Tokenizer.cpp.i

CMakeFiles/app.dir/src/Tokenizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/Tokenizer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/Tokenizer.cpp -o CMakeFiles/app.dir/src/Tokenizer.cpp.s

CMakeFiles/app.dir/src/ColorFilter.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/ColorFilter.cpp.o: ../src/ColorFilter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/app.dir/src/ColorFilter.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/src/ColorFilter.cpp.o -c /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/ColorFilter.cpp

CMakeFiles/app.dir/src/ColorFilter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/ColorFilter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/ColorFilter.cpp > CMakeFiles/app.dir/src/ColorFilter.cpp.i

CMakeFiles/app.dir/src/ColorFilter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/ColorFilter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/ColorFilter.cpp -o CMakeFiles/app.dir/src/ColorFilter.cpp.s

CMakeFiles/app.dir/src/ShapeRecognizer.cpp.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/src/ShapeRecognizer.cpp.o: ../src/ShapeRecognizer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/app.dir/src/ShapeRecognizer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/app.dir/src/ShapeRecognizer.cpp.o -c /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/ShapeRecognizer.cpp

CMakeFiles/app.dir/src/ShapeRecognizer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/app.dir/src/ShapeRecognizer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/ShapeRecognizer.cpp > CMakeFiles/app.dir/src/ShapeRecognizer.cpp.i

CMakeFiles/app.dir/src/ShapeRecognizer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/app.dir/src/ShapeRecognizer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/src/ShapeRecognizer.cpp -o CMakeFiles/app.dir/src/ShapeRecognizer.cpp.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/src/main.cpp.o" \
"CMakeFiles/app.dir/src/ImageDisplay.cpp.o" \
"CMakeFiles/app.dir/src/CommandInterpreter.cpp.o" \
"CMakeFiles/app.dir/src/Tokenizer.cpp.o" \
"CMakeFiles/app.dir/src/ColorFilter.cpp.o" \
"CMakeFiles/app.dir/src/ShapeRecognizer.cpp.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: CMakeFiles/app.dir/src/main.cpp.o
app: CMakeFiles/app.dir/src/ImageDisplay.cpp.o
app: CMakeFiles/app.dir/src/CommandInterpreter.cpp.o
app: CMakeFiles/app.dir/src/Tokenizer.cpp.o
app: CMakeFiles/app.dir/src/ColorFilter.cpp.o
app: CMakeFiles/app.dir/src/ShapeRecognizer.cpp.o
app: CMakeFiles/app.dir/build.make
app: /usr/local/lib/libopencv_gapi.so.4.5.3
app: /usr/local/lib/libopencv_highgui.so.4.5.3
app: /usr/local/lib/libopencv_ml.so.4.5.3
app: /usr/local/lib/libopencv_objdetect.so.4.5.3
app: /usr/local/lib/libopencv_photo.so.4.5.3
app: /usr/local/lib/libopencv_stitching.so.4.5.3
app: /usr/local/lib/libopencv_video.so.4.5.3
app: /usr/local/lib/libopencv_videoio.so.4.5.3
app: /usr/local/lib/libopencv_dnn.so.4.5.3
app: /usr/local/lib/libopencv_imgcodecs.so.4.5.3
app: /usr/local/lib/libopencv_calib3d.so.4.5.3
app: /usr/local/lib/libopencv_features2d.so.4.5.3
app: /usr/local/lib/libopencv_flann.so.4.5.3
app: /usr/local/lib/libopencv_imgproc.so.4.5.3
app: /usr/local/lib/libopencv_core.so.4.5.3
app: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app

.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	cd /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/build /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/build /home/ar/Documents/WoR21/Robots/BP-1/BP_Beeldherkenning/build/CMakeFiles/app.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/app.dir/depend
