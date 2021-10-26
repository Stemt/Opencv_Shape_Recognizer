#ifndef SHAPERECOGNIZER_HPP_
#define SHAPERECOGNIZER_HPP_
#include "ImageContainer.hpp"
class ShapeRecognizer : public ImageContainer
{
    public:
    enum shapes{
        DRIEHOEK = 0,
        SQUARE = 1,
        RECTANGLE = 2,
        CIRCLE = 3,
        HALF_CIRCLE = 4
    };
    /**
     * @brief Constructor.
     * @param container imagecontainer.
     * @param shape to recognize shape.
     */
    ShapeRecognizer(ImageContainer &container, shapes shape);
    /**
     * @brief destructor.
     */
    ~ShapeRecognizer();
    /**
     * @brief function to show the RBG image.
     * @return (void)
     */
    void showRGB();
    /**
     * @brief function to show HSV image.
     * @return (void)
     */
    void showHSV();
    /**
     * @brief image getter.
     * @return the displayedImage.
     */
    const cv::Mat &getImage() const;
    /**
     * @brief sets the image in the container.
     * @param img the image to set.
     * @return (void)
     */
    void setImage(const cv::Mat &img);
    /**
     * @brief searches for all circle-like contours.
     * @param src_contours incomming contours.
     * @param dst_contours outcomming contours of circle-like contours.
     * @return (void)
     */
    void getCircleLikes(std::vector<std::vector<cv::Point>>& src_contours, std::vector<std::vector<cv::Point>>& dst_contours);
    /**
     * @brief function to check if the contour is a cirle or a half-circle.
     * @param circleLike the circle contour to check.
     * @return true if circle.
     */
    bool isCircle(const std::vector<cv::Point>& circleLike);
    /**
     * @brief function to check if the rectangle shape is a square.
     * @param rechtHoek the contour to check.
     * @return true if its a square.
     */
    bool isVierkant(const std::vector<cv::Point> &rechtHoek);
    /**
     * @brief getter for the recognized shape.
     * @return the recognized shape.
     */
    const std::vector<std::vector<cv::Point>>& getRecognizedShape();
    private:
    cv::Mat displayedImage;
    ImageContainer &container;
    int shape;
    std::vector<std::vector<cv::Point>> recognizedShape;
};

#endif