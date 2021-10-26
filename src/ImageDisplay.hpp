#ifndef IMAGE_DISPLAY_H_
#define IMAGE_DISPLAY_H_

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "ImageContainer.hpp"

class ImageDisplay : public ImageContainer{
    public:
        /**
         * @brief constructor
         * @param name window name
         * @param img  img for the display
         * @param visible for visualizing the display
         */
        ImageDisplay(const std::string& name, cv::Mat& img, bool visible);
        /**
         * @brief destructor.
         */
        ~ImageDisplay();
        /**
         * @brief function to show the RBG img.
         * @return 
         */
        virtual void showRGB();
        /**
         * @brief function to show the HSV img.
         * @return 
         */
        virtual void showHSV();
        /**
         * @brief fucntion to get the image.
         * @return the image.
         */
        const cv::Mat& getImage() const;
        /**
         * @brief funtion to set the image.
         * @param img
         * @return (void)
         */
        void setImage(const cv::Mat& img);
    private:
        std::string name;
        cv::Mat displayedImage;
        cv::Mat image;
        bool visible;
};

#endif