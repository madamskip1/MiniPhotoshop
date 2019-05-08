#include "mouse.h"
#include <QDebug>

Mouse::Mouse(DisplayImageLabel* dl, Image* img) :
    displayLabel(dl), image(img)
{

    connect(displayLabel, &DisplayImageLabel::mouseLeftClick, this, &Mouse::mousePressed);
    connect(displayLabel, &DisplayImageLabel::mouseMove, this, &Mouse::mouseMoved);
    connect(displayLabel, &DisplayImageLabel::mouseLeftRelease, this, &Mouse::mouseRelease);
}

Mouse::~Mouse()
{

}

void Mouse::setSize(int)
{

}

cv::Scalar Mouse::calcMinMax(cv::Scalar minMax)
{
    if (!image->isImgAreaX(minMax[0]))
    {
        if (minMax[0] < 0) minMax[0] = 0;
        else
        {
            minMax[0] = -1;
            return minMax;
        }
    }

    if (!image->isImgAreaX(minMax[1]))
    {
        if (minMax[1] < 0)
        {
            minMax[1] = -1;
            return minMax;
        } else minMax[1] = image->getWidth();
    }

    if (!image->isImgAreaY(minMax[2]))
    {
        if (minMax[2] < 0) minMax[2] = 0;
        else
        {
            minMax[2] = -1;
            return minMax;
        }
    }

    if (!image->isImgAreaY(minMax[3]))
    {
        if (minMax[3] < 0)
        {
            minMax[3] = -1;
            return minMax;
        } else minMax[3] = image->getHeight() - 1;
    }

    return minMax;
}

bool Mouse::isMinMax(cv::Scalar minMax)
{
    for (int i = 0; i < 4; i++)
    {
        if (minMax[i] == -1) return false;
    }
    return true;
}

void Mouse::leftClick(int, int)
{

}

void Mouse::leftMove(int, int)
{

}

void Mouse::leftRelease(int, int)
{

}

void Mouse::mousePressed(QMouseEvent * ev)
{
    //cv::Mat img = image->getImg();
    int x = ev->x();
    int y = ev->y();

    leftClick(x, y);
    return;
//    rubber(x, y);

//    image->display();
//    return;
    cv::Mat img = image->getImg();
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
    int x = ev->x();
    int y = ev->y();

    if(ev->buttons() & Qt::LeftButton) leftMove(x, y);

    return;
    if(!(ev->buttons() & Qt::LeftButton)) return;
    cv::Mat img = image->getImg();


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

void Mouse::mouseRelease(QMouseEvent * ev)
{
    int x = ev->x();
    int y = ev->y();

    leftRelease(x, y);
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
