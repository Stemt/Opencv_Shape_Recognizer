#include "ColorFilter.hpp"
#include <fstream>

int ColorFilter::hueOffset = 0;
int ColorFilter::saturationOffset = 0;
int ColorFilter::valueOffset = 0;

ColorFilter::ColorFilter(ImageContainer &container)
    :displayedImage(container.getImage().clone()), container(container)
{}

ColorFilter::~ColorFilter()
{
}

void ColorFilter::showRGB()
{
    container.showRGB();
}

void ColorFilter::showHSV()
{}

const cv::Mat &ColorFilter::getImage() const
{
    return displayedImage;
}

void ColorFilter::setImage(const cv::Mat &img)
{
    displayedImage = img.clone();
}

void ColorFilter::setHOffset(int value, void* instance_ptr)
{
    ColorFilter* filter_ptr = (ColorFilter*) instance_ptr;
    filter_ptr->hueOffset = value-90;
}

void ColorFilter::setSOffset(int value, void* instance_ptr)
{
    ColorFilter* filter_ptr = (ColorFilter*) instance_ptr;
    filter_ptr->saturationOffset = value-128;
}

void ColorFilter::setVOffset(int value, void* instance_ptr)
{
    ColorFilter* filter_ptr = (ColorFilter*) instance_ptr;
    filter_ptr->valueOffset = value-128;
}

void ColorFilter::apply(ColorFilter::color color)
{
    cv::Mat img = displayedImage.clone();
    cv::cvtColor(img, img, cv::COLOR_BGR2HSV);
    
    cv::Vec3d lowColor({0,0,0,0}), highColor({0,0,0,0});
    switch (color)
    {
    case color::WIT:
        lowColor = lowWhite;
        highColor = highWhite;
        break;
    case color::PINK:
        lowColor = lowPink;
        highColor = highPink;
        break;
    case color::YELLOW:
        lowColor = lowYellow;
        highColor = highYellow;
        break;
    case color::ORANGE:
        lowColor = lowOrange;
        highColor = highOrange;
        break;
    case color::GREEN:
        lowColor = lowGreen;
        highColor = highGreen;
        break;
    }
    lowColor[0] += hueOffset;
    lowColor[1] += saturationOffset;
    lowColor[2] += valueOffset;
    highColor[0] += hueOffset;
    highColor[1] += saturationOffset;
    highColor[2] += valueOffset;
    inRange(img, lowColor, highColor, displayedImage);
    container.setImage(displayedImage);
}