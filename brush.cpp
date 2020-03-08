#include "brush.h"

/**
 * @brief Brush::Brush constructor.
 * @param dl
 * @param img
 * @param _size
 * @param _opacity
 */
Brush::Brush(DisplayImageLabel * dl, Image * img, cv::Scalar * _color,  int _size, double _opacity) :
    Mouse(dl, img), opacity(_opacity), color(_color)
{
    setSize(_size);
}

void Brush::leftClick(int x, int y)
{
    cv::Mat img = image->getImg();
    cv::Mat overlay;
    img.copyTo(overlay);

    cv::Point p(x, y);
    cv::circle(overlay, p, 5, *color, -1);

    // Blending two layers into one
    cv::addWeighted(overlay, opacity, img, 1-opacity, 0, img);

    image->display();
}

void Brush::leftMove(int x, int y)
{
    leftClick(x, y);
}

