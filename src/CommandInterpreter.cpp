#include "CommandInterpreter.hpp"
#include <fstream>
#include <chrono>
#include "ColorMod.hpp"

Color::Modifier red(Color::FG_RED);
Color::Modifier green(Color::FG_GREEN);
Color::Modifier def(Color::FG_DEFAULT);

CommandInterpreter::CommandInterpreter(ImageDisplay &display)
: display(display)
{
}

CommandInterpreter::~CommandInterpreter()
{
}

void CommandInterpreter::interpretCommand(const std::string &command, int camDevice, int maximumRuntime)
{

    Tokenizer tokenizer(command);
    std::vector<Token> tokens;
    Token token = tokenizer.getNextToken();
    int argument = 0;
    std::string color = "";
    std::string shape = "";
    bool done = false;
    while (token.type != END_OF_FILE && !done)
    {
        switch (token.type)
        {
        case MINUS_OPERATOR:
        case WORD:
            if (argument == 0)
            {
                color = token.string;
            }
            else if (argument == 1)
            {
                shape = token.string;
            }
            else
            {
                std::cout << "too many arguments" << std::endl;
                return;
            }
            argument++;
            break;
        case HASHTAG_OPERATOR:
            if (argument == 0)
            {
                return;
            }
            done = true;
            break;
        }
        token = tokenizer.getNextToken();
    }
    if (argument < 2)
    {
        std::cout << red << "error: " << def << " on'" << command << "', not enough arguments, ignoring command.." << std::endl;
        return;
    }
    else if (!isValidColor(color))
    {
        std::cout << red << "error: " << def << " '" << color << "' is not a valid color, ignoring command.." << std::endl;
        return;
    }
    else if (!isValidShape(shape))
    {
        std::cout << red << "error: " << def << " '" << shape << "' is not a valid shape, ignoring command.." << std::endl;
        return;
    }

    ColorFilter::color selected_color;

    if (color == "yellow")
    {
        selected_color = ColorFilter::color::YELLOW;
    }
    else if (color == "pink")
    {
        selected_color = ColorFilter::color::PINK;
    }
    else if (color == "orange")
    {
        selected_color = ColorFilter::color::ORANGE;
    }
    else if (color == "green")
    {
        selected_color = ColorFilter::color::GREEN;
    }

    ShapeRecognizer::shapes selected_shape;

    if (shape == "square")
    {
        selected_shape = ShapeRecognizer::shapes::SQUARE;
    }
    else if (shape == "rectangle")
    {
        selected_shape = ShapeRecognizer::shapes::RECTANGLE;
    }
    else if (shape == "driehoek")
    {
        selected_shape = ShapeRecognizer::shapes::DRIEHOEK;
    }
    else if (shape == "circle")
    {
        selected_shape = ShapeRecognizer::shapes::CIRCLE;
    }
    else if (shape == "half-circle")
    {
        selected_shape = ShapeRecognizer::shapes::HALF_CIRCLE;
    }

    cv::Mat og_img;
    cv::Mat img;
    cv::VideoCapture cap;

    if(camDevice != -1){
        cap = cv::VideoCapture(camDevice);
        cap >> img;
    }else if(camDevice == -1){
        og_img = display.getImage().clone();
        img = og_img.clone();
    }else{
        return;
    }
    ImageDisplay invisible_display("invisible", img, (camDevice != -1));
    ColorFilter colorFilter(invisible_display);
    colorFilter.setImage(img);
    if(camDevice != -1){
        cv::namedWindow("slider");
        cv::createTrackbar("H","slider",NULL,179,ColorFilter::setHOffset,(void*)&colorFilter);
        cv::createTrackbar("S","slider",NULL,255,ColorFilter::setSOffset,(void*)&colorFilter);
        cv::createTrackbar("V","slider",NULL,255,ColorFilter::setVOffset,(void*)&colorFilter);
    }

    auto startTime = std::chrono::steady_clock::now();

    while (cv::waitKey(50) == -1 && startTime + std::chrono::milliseconds(maximumRuntime) > std::chrono::steady_clock::now())
    {
        size_t tikCountStart = cv::getTickCount();
        size_t tikCountEnd;
        size_t totalTicks;

        if(camDevice != -1){
            cap >> img;
        }else{
            img = og_img.clone();
        }

        colorFilter.setImage(img);
        colorFilter.apply(selected_color);
        colorFilter.showRGB();
        ShapeRecognizer shapeRecognizer(colorFilter, selected_shape);
        tikCountEnd = cv::getTickCount();
        totalTicks = tikCountEnd - tikCountStart;
        if (shapeRecognizer.getRecognizedShape().size() == 0)
        {
            std::cout << "no shape found. ticks: " << totalTicks << std::endl;
        }
        cv::drawContours(img, shapeRecognizer.getRecognizedShape(), -1, cv::QT_FONT_BLACK);
        for (auto contour : shapeRecognizer.getRecognizedShape())
        {
            setLabel(img, img, shape, contour, totalTicks);
        }
        display.setImage(img);
        display.showRGB();
    }
    if(camDevice != -1){
        cv::destroyWindow("slider");
    }
}

void CommandInterpreter::interpretFromFile(const std::string &path, int camDevice, int pauseTime)
{
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line))
    {
        
        if(pauseTime == 0){
            interpretCommand(line,camDevice);
        }else{
            interpretCommand(line,camDevice,pauseTime);
        }
    }
}

bool CommandInterpreter::isValidColor(const std::string &color)
{
    for (auto validColor : validColors)
    {
        if (validColor == color)
        {
            return true;
        }
    }
    return false;
}

bool CommandInterpreter::isValidShape(const std::string &shape)
{
    for (auto validShape : validShapes)
    {
        if (validShape == shape)
        {
            return true;
        }
    }
    return false;
}

void CommandInterpreter::setLabel(cv::Mat &im, cv::Mat &src, const std::string label, std::vector<cv::Point> &contour, size_t ticks)
{
    int fontface = cv::FONT_HERSHEY_SIMPLEX;
    double scale = 0.35;
    int thickness = 1;
    int baseline = 0;
    cv::Rect r = boundingRect(contour);
    std::string coordinatesString = "X:" + std::to_string(r.x + (r.width / 2)) + " " + "Y:" + std::to_string(r.y + (r.height) / 2);
    std::string tickString = "ticks:" + std::to_string(ticks);

    cv::Size textFirstRow = cv::getTextSize(coordinatesString, fontface, scale, thickness, &baseline);
    cv::Size textSecondRow = cv::getTextSize(tickString, fontface, scale, thickness, &baseline);

    cv::Point textptFirstRow(r.x + ((r.width - textFirstRow.width) / 2), r.y + ((r.height + textFirstRow.height) / 2));
    cv::Point textptSecondRow(r.x + ((r.width - textSecondRow.width) / 2), r.y + ((r.height + (4 * textFirstRow.height)) / 2));

    putText(im, coordinatesString, textptFirstRow, fontface, scale, CV_RGB(0, 0, 255), thickness, 8);
    putText(im, tickString, textptSecondRow, fontface, scale, CV_RGB(0, 0, 255), thickness, 8);
}