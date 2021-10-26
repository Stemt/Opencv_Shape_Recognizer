
cmake_minimum_required(VERSION 3.13.4)

project(les3_opencv)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(
    recognize 
    src/main.cpp 
    src/ImageDisplay.cpp 
    src/CommandInterpreter.cpp
    src/Tokenizer.cpp
    src/ColorFilter.cpp
    src/ShapeRecognizer.cpp
)

target_link_libraries(recognize ${OpenCV_LIBS})
