#include "brush.h"

/**
 * @brief Brush::Brush constructor.
 * @param dl
 * @param img
 * @param _size
 * @param _opacity
 */
Brush::Brush(DisplayImageLabel * dl, Image * img, int _size, double _opacity) :
    Mouse(dl, img), opacity(_opacity)
{
    qDebug() << "Brush: on";
    setSize(_size);
}

void Brush::leftClick(int x, int y)
{

    cv::Mat img = image->getImg();
    cv::Mat overlay;
    img.copyTo(overlay);

    cv::Point p(x, y);
    cv::Scalar s(0, 0, 0, 255   );
    cv::circle(overlay, p, 20, s, -1);

    // Blending two layers into one
    cv::addWeighted(overlay, opacity, img, 1-opacity, 0, img);

    image->display();
}

void Brush::leftMove(int x, int y)
{
    leftClick(x, y);
}

