#ifndef COLORFILTER_HPP_
#define COLORFILTER_HPP_

#include "ImageContainer.hpp"

class ColorFilter : public ImageContainer
{
public:
    /**
     * enumeration for the different colors
     */
    enum color
    {
        PINK = 0,
        YELLOW = 1,
        ORANGE = 2,
        GREEN = 3,
        WIT = 4
    };
    
    /**
     * @brief Constructor.
     * @param container place of the original images.
     */
    ColorFilter(ImageContainer &container);
    /**
     * @brief destructor
     */
    ~ColorFilter();
    /**
     * @brief to update the RGB picture in the container.
     * @return (void)
     */
    void showRGB();
    /**
     * @brief to update the HSV picture in the container.
     * @return (void)
     */
    void showHSV();
    /**
     * @brief get function for the image.
     * @return cv::Mat img
     */
    const cv::Mat &getImage() const;
    /**
     * @brief function to set image.
     * @param img
     * @return (void)
     */
    void setImage(const cv::Mat &img);
    /**
     * @brief static function for setting the Hue value trough a slider.
     * @param value hue value.
     * @param instance_ptr
     * @return (void)
     */
    static void setHOffset(int value, void* instance_ptr);
    /**
     * @brief static function for setting the Saturationvalue trough a slider.
     * @param value saturation value.
     * @param instance_ptr
     * @return (void)
     */
    static void setSOffset(int value, void* instance_ptr);
    /**
     * @brief static function for setting the value trough a slider.
     * @param value value.
     * @param instance_ptr
     * @return (void)
     */
    static void setVOffset(int value, void* instance_ptr);
    /**
     * @brief function for applying the colorfilter on the img.
     * @param color Enum color.
     * @return (void)
     */
    void apply(ColorFilter::color color);

private:
    cv::Mat displayedImage;
    ImageContainer &container;
    std::map<std::string,cv::Vec3d> colorRanges;
    cv::Vec3d lowYellow{25,240,240,0};
    cv::Vec3d highYellow{35,255,255,0};
    cv::Vec3d lowOrange{0,200,200,0};
    cv::Vec3d highOrange{25,255,255,0};
    cv::Vec3d lowGreen{55,150,100,0};
    cv::Vec3d highGreen{100,255,255,0};
    cv::Vec3d lowPink{100,200,200,0};
    cv::Vec3d highPink{179,255,255,0};
    cv::Vec3d lowWhite{0,0,200,0};
    cv::Vec3d highWhite{0,0,255,0};
    static int hueOffset;
    static int saturationOffset;
    static int valueOffset;
};
#endif