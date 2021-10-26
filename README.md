# Opencv_Shape_Recognizer
An opencv application for detecting and recognizing different shapes of various colors

## Building

This program uses the cmake to compile and requires a C++ compiler and the OpenCV library to be installed to be able to compile correctly.

**Note**: This program was developed for the linux operating system and thus has not been tested for differing operating systems

To compile do the following:

Create a new directory for the build files and enter it.
`mkdir build && cd build`

Call cmake to configure the project.
If this command returns errors, recheck that you installed the C++ compiler and the OpenCV library correctly.
`cmake ..`

If cmake has succesfully configured the project you will be able to build the project by doing the following
`make -j4`

## Usage

To run the program execute the following command in a terminal:
`./recognize -i [path to image file]`
To recognize shapes in an image.
Or
`./recognize -c`
to use the default webcam feed for recognizing shapes.

### Command interpreter

After you have done this without any other option you will be greeted by a command prompt that looks like this:
`input> `

Here you can enter a combination of a color and a shape. 
The following colors are available:
- yellow
- orange
- green
- pink

Which should be followed up by one of the following shapes:
- square
- rectangle
- circle
- half-circle

#### Scripts

You can use the `-f` option to load a text file containing a series of commands.
These scripts may also contains line with a `#`, all charachter after this will be ignored (for comments and such).
You must press a button while focused on the window to advance through the script but you can also use the `-d` option to set a delay in milliseconds after which the command interpreter will continue with the next line in the file.
