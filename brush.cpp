#include "brush.h"


Brush::Brush(DisplayImageLabel * dl, Image * img) :
    Mouse(dl, img)
{
    qDebug() << "Brush: on";
    opacity = 0.4;
}

void Brush::setSize(int _size)
{
    size = _size;
}

void Brush::leftClick(int x, int y)
{

    cv::Mat img = image->getImg();
    cv::Mat overlay;
    img.copyTo(overlay);

    cv::Point p(x, y);
    cv::Scalar s(0, 0, 0, 255   );
    cv::circle(overlay, p, 20, s, -1);

    cv::addWeighted(overlay, opacity, img, 1-opacity, 0, img);

    image->display();
}

void Brush::leftMove(int x, int y)
{
    leftClick(x, y);
}

