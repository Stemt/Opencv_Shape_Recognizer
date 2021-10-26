#include <stdio.h>
#include "ShapeRecognizer.hpp"
ShapeRecognizer::ShapeRecognizer(ImageContainer &container, shapes shape)
    : displayedImage(container.getImage().clone()), container(container), shape(shape), recognizedShape({})
{
    container.showRGB();
    cv::cvtColor(displayedImage, displayedImage, cv::COLOR_BayerBG2GRAY);
    cv::threshold(displayedImage, displayedImage, 128, 255, cv::THRESH_BINARY);
    std::vector<std::vector<cv::Point>> contours;
    cv::Mat contourOutput = displayedImage.clone();
    cv::findContours(contourOutput, contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);
    std::vector<cv::Point> approx;

    switch (shape)
    {
    case shapes::DRIEHOEK:
        for (auto contour : contours)
        {
            cv::approxPolyDP(cv::Mat(contour), approx, cv::arcLength(cv::Mat(contour), true) * 0.02, true);
            if (std::fabs(contourArea(contour)) < 80 || !isContourConvex(approx))
                continue;
            if (approx.size() == 3)
            {
                recognizedShape.push_back(contour);
            }
        }
        break;
    case shapes::SQUARE:
        for (auto contour : contours)
        {
            cv::approxPolyDP(cv::Mat(contour), approx, cv::arcLength(cv::Mat(contour), true) * 0.02, true);
            if (std::fabs(contourArea(contour)) < 80 || !isContourConvex(approx))
                continue;
            if (approx.size() == 4)
            {
                if(isVierkant(approx)){
                    recognizedShape.push_back(approx);
                }
            }
        }
        break;
    case shapes::RECTANGLE:
        for (auto contour : contours)
        {
            cv::approxPolyDP(cv::Mat(contour), approx, cv::arcLength(cv::Mat(contour), true) * 0.02, true);
            if (std::fabs(contourArea(contour)) < 80 || !isContourConvex(approx))
                continue;
            if (approx.size() == 4)
            {
                if(!isVierkant(approx)){
                    recognizedShape.push_back(approx);
                }
            }
        }
        break;
    case shapes::CIRCLE:
    {
        std::vector<std::vector<cv::Point>> circleLikes;
        getCircleLikes(contours, circleLikes);
        for (const auto &circleLike : circleLikes)
        {
            if (isCircle(circleLike))
            {
                recognizedShape.push_back(circleLike);
            }
        }
    }
    break;
    case shapes::HALF_CIRCLE:
    {
        std::vector<std::vector<cv::Point>> circleLikes;
        getCircleLikes(contours, circleLikes);
        for (const auto &circleLike : circleLikes)
        {
            if (!isCircle(circleLike))
            {
                recognizedShape.push_back(circleLike);
            }
        }
    }
    break;
    }
}

ShapeRecognizer::~ShapeRecognizer() {}

void ShapeRecognizer::showRGB()
{
    container.showRGB();
}

void ShapeRecognizer::showHSV()
{
    container.showHSV();
}

const cv::Mat &ShapeRecognizer::getImage() const
{
    return displayedImage;
}

void ShapeRecognizer::setImage(const cv::Mat &img)
{
    container.setImage(img);
}

void ShapeRecognizer::getCircleLikes(std::vector<std::vector<cv::Point>> &src_contours, std::vector<std::vector<cv::Point>> &dst_contours)
{
    std::vector<cv::Point> approx;
    dst_contours.clear();
    for (const auto &contour : src_contours)
    {
        cv::approxPolyDP(contour, approx, 0.01 * cv::arcLength(contour, true), true);
        if (std::fabs(contourArea(contour)) < 80 || !isContourConvex(approx))
                continue;
        if (approx.size() > 6)
        {
            dst_contours.push_back(approx);
        }
    }
}

bool ShapeRecognizer::isCircle(const std::vector<cv::Point> &circleLike)
{
    double longest_length = 0;
    double total_length = 0;
    double delta_factor = 0;
    for (size_t i = 0; i < circleLike.size() - 1; i++)
    {
        double delta = cv::norm(circleLike[i] - circleLike[i + 1]);
        total_length += delta;
        if (delta > longest_length)
        {
            longest_length = delta;
        }
    }
    double avg_length = total_length / circleLike.size();
    delta_factor = longest_length / avg_length;
    return delta_factor < 2.5;
}

bool ShapeRecognizer::isVierkant(const std::vector<cv::Point> &rechtHoek)
{
    double longest_length = 0;
    double shortest_length = 9999999;
    double total_length = 0;
    double delta_factor = 0;
    for (size_t i = 0; i < rechtHoek.size(); i++)
    {
        double delta = 0;
        if(i+1 < rechtHoek.size()){
            delta = cv::norm(rechtHoek[i] - rechtHoek[i + 1]);
        }else{
            delta = cv::norm(rechtHoek[i] - rechtHoek[0]);
        }
        total_length += delta;
        if (delta > longest_length)
        {
            longest_length = delta;
        }
        if(delta < shortest_length && delta > 5){
            shortest_length = delta;
        }
    }
    double avg_length = total_length / rechtHoek.size();
    double deviation_factor = shortest_length /longest_length;
    return deviation_factor > 0.80;
}

const std::vector<std::vector<cv::Point>> &ShapeRecognizer::getRecognizedShape()
{
    return recognizedShape;
}
