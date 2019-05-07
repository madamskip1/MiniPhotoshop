#include "mouse.h"
#include <QDebug>
#include "opencv2/opencv.hpp"

Mouse::Mouse(DisplayImageLabel* dl, Image* img) :
    displayLabel(dl)//, image(img)
{
    image = img;
    connect(displayLabel, &DisplayImageLabel::mouseLeftClick, this, &Mouse::mousePressed);
//    connect(displayLabel, &DisplayImageLabel::mouseMove, this, &Mouse::mouseMoved);
}

Mouse::~Mouse()
{

}

void Mouse::setSize(int)
{

}

void Mouse::leftClick(int, int)
{

}

void Mouse::mousePressed(QMouseEvent * ev)
{
    cv::Mat img = image->getImg();
    int x = ev->x();
    int y = ev->y();
    leftClick(x, y);
    return;
//    rubber(x, y);

//    image->display();
//    return;

    cv::Mat overlay;
    double alpha = 0.4;
    img.copyTo(overlay);

    cv::Point* p = new cv::Point(x, y);
    cv::Scalar* s = new cv::Scalar(210,0,50,1);

    cv::circle(overlay, *p, 30, *s, -1);
    cv::addWeighted(overlay, alpha, img, 1-alpha, 0, img);

    image->display();
}

void Mouse::mouseMoved(QMouseEvent * ev)
{
    if(!(ev->buttons() & Qt::LeftButton)) return;
    cv::Mat img = image->getImg();
    int x = ev->x();
    int y = ev->y();

    //rubber(x, y);

    //image->display();
  //  return;

    cv::Mat overlay;
    double alpha = 0.4;
    img.copyTo(overlay);

    cv::Point* p = new cv::Point(x, y);
    cv::Scalar* s = new cv::Scalar(0,0,0,1);

    cv::circle(overlay, *p, 30, *s, -1);
    cv::addWeighted(overlay, alpha, img, 1-alpha, 0, img);

    image->display();
}

void Mouse::rubber(int x, int y)
{
    qDebug() << "Rubber: (" << x << ", " << y<<")";

    int size = 20;
    cv::Mat img = image->getImg();
    for(int i = (x - size); i < (x + size); i++)
    {
        for (int j = (y - size); j < (y + size); j++)
        {
            int z = j * img.cols * img.channels() + i * img.channels();
            img.data[z] = 50;
            z++;
            img.data[z] = 50;
            z++;
            img.data[z] = 50;
            z++;
            img.data[z] = 0;
        }
    }

}
