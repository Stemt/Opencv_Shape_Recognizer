

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "ImageDisplay.hpp"
#include "CommandInterpreter.hpp"

void print_help(){
    std::cout << "Usage: ./recognize [options]" << std::endl;
    std::cout << "Options:" << std::endl;
    std::cout << "-i [image file]    : use this option to load an image file" << std::endl;
    std::cout << "-f [batch file]    : use this option to execute commands from a batch file" << std::endl;
    std::cout << "-d [delay time]    : use this option when executing a batch file to set a delay between executed commands" << std::endl;
    std::cout << "-c [camera device] : use this option to use a webcam (leave [camera device] blank to use default device)" << std::endl;
}

using namespace cv;
int main(int argc, char** argv)
{
    std::string imagePath = "";
    std::string batchFile = "";
    int cameraDevice = -1;
    int waitTime = 0;
    cv::Mat img = cv::Mat::zeros(cv::Size(100,100),CV_8UC3);
    
    if(argc == 1){
        std::cout << "no image source specified." << std::endl <<"use the -i or -c options to do so" << std::endl;
        print_help();
        return 0;
    }
    for(int i = 1; i < argc; i++){
        std::string arg(argv[i]);
        if(arg == "-f"){
            if(i+1 < argc){
                batchFile = std::string(argv[i+1]);
            }
        }else if(arg == "-d"){
            if(i+1 < argc){
                waitTime = std::stoi(argv[i+1]);
            }
        }else if(arg == "-i"){
            if(i+1 <= argc){
                std::cout << " set imag" << std::endl;
                imagePath = std::string(argv[i+1]);
                std::cout << imagePath << std::endl;
            }
        }else if(arg == "-c"){
            if(i+1 <= argc){
                cameraDevice = std::stoi(argv[i+1]);
            }
        }
    }
    if(imagePath == "" && cameraDevice == -1){
        std::cout << "no image source specified." << std::endl <<"use the -i or -c options to do so" << std::endl;
        print_help();
        return 0;
    }else if(imagePath != ""){
        img = imread(imagePath);
    }    
    ImageDisplay display("window",img,true);

    CommandInterpreter interpreter(display);
    if(batchFile != ""){
        interpreter.interpretFromFile(batchFile,cameraDevice,waitTime);
    }else{
        std::string input;
        std::cout << "input> ";
        std::getline(std::cin,input);

        while(input != "quit"){
            interpreter.interpretCommand(input,cameraDevice);
            waitKey(100);
            std::cout << "input> ";
            std::getline(std::cin,input);
        }
    }


    return 0;
}