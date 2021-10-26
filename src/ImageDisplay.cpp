#include "ImageDisplay.hpp"

ImageDisplay::ImageDisplay(const std::string &name, cv::Mat &img, bool visible)
    : name(name), image(img), displayedImage(img), visible(visible)
{
    if (visible)
    {
        cv::namedWindow(name);
        cv::imshow(name, displayedImage);
    }
}

ImageDisplay::~ImageDisplay()
{
    if (visible)
    {
        cv::destroyWindow(name);
    }
}

void ImageDisplay::showRGB()
{
    if (visible)
    {
        cv::imshow(name, displayedImage);
    }
}

void ImageDisplay::showHSV()
{
    if (visible)
    {
        cv::Mat hsv;
        cv::cvtColor(displayedImage, hsv, cv::COLOR_HSV2BGR);
        cv::imshow(name, hsv);
    }
}

const cv::Mat &ImageDisplay::getImage() const
{
    return image;
}

void ImageDisplay::setImage(const cv::Mat &img)
{
    displayedImage = img.clone();
}
