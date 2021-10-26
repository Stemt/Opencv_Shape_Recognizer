#ifndef IMAGECONTAINER_H_
#define IMAGECONTAINER_H_

#include <opencv2/opencv.hpp>

class ImageContainer{
    public:

    /**
     * @brief virtual function for the classes what are implementing container.
     * @param 
     * @return 
     */
    virtual void showRGB() = 0;
    /**
     * @brief virtual function for the classes what are implementing container.
     * @param 
     * @return 
     */
    virtual void showHSV() = 0;
    /**
     * @brief virtual function for the classes what are implementing container.
     * @param 
     * @return returns the image of the container.
     */
    virtual const cv::Mat& getImage() const = 0;
    /**
     * @brief virtual function for the classes what are implementing container.
     * @param img sets the image in the container.
     * @return 
     */
    virtual void setImage(const cv::Mat& img) = 0;
};

#endif