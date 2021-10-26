#ifndef COMMANDINTERPRETER_H_
#define COMMANDINTERPRETER_H_

#include <iostream>
#include <vector>
#include "Tokenizer.hpp"
#include "ColorFilter.hpp"
#include "ShapeRecognizer.hpp"
#include "ImageDisplay.hpp"


class CommandInterpreter
{
public:
    /**
     * @brief Constructor
     * @param display 
     */
    CommandInterpreter(ImageDisplay& display);
    /**
     * @brief destructor.
     */
    ~CommandInterpreter();
    /**
     * @brief function for executing commands.
     * @param command
     * @param camDevice camera device index
     * @param maximumRuntime 
     * @return (void)
     */
    void interpretCommand(const std::string& command, int camDevice, int maximumRuntime = 9999999);
    /**
     * @brief function for reading commands from a file.
     * @param path
     * @param pauseTime time to wait between commands.
     * @param camDevice camera device index
     * @return (void)
     */
    void interpretFromFile(const std::string& path, int camDevice, int pauseTime = 0);
    /**
     * @brief function to check if the color is valid.
     * @param color
     * @return 
     */
    bool isValidColor(const std::string& color);
    /**
     * @brief function to check if the shape is valid.
     * @param shape
     * @return 
     */
    bool isValidShape(const std::string& shape);
    /**
     * @brief sets label on the screen to mark the shapes what are found.
     * @param im img to draw on
     * @param src 
     * @param label the shape.
     * @param contour the contour of the shape.
     * @param ticks amount of ticks to recognize.
     * @return (void)
     */
    void setLabel(cv::Mat &im, cv::Mat &src, const std::string label, std::vector<cv::Point> &contour,size_t ticks);
private:
    ImageDisplay& display;
    std::vector<std::string> validColors = {"pink","yellow","green","orange"};
    std::vector<std::string> validShapes = {"square","rectangle","circle","half-circle","driehoek"};
};


#endif