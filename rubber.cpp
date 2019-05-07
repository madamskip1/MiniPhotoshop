#include <opencv2/opencv.hpp>
#include "rubber.h"
#include <QDebug>

Rubber::Rubber(DisplayImageLabel * dl, Image * img, Brushes brush, int _size) :
    Mouse(dl, img),  size(_size), brushType(brush)
{

    qDebug() << "Rubber: on";
}

Rubber::~Rubber()
{
    qDebug() << "Rubber: off";
}

void Rubber::setSize(int _size)
{
    size = _size;
}

void Rubber::leftClick(int x, int y)
{
    switch(brushType)
    {
        case Brushes::Square:
            squareRubber(x, y);
            break;
        case Brushes::Circle:
        break;
    }
}

void Rubber::squareRubber(int x, int y)
{
    cv::Mat img = image->getImg();
    cv::Scalar backgroundColor = image->getBackgroundColor();

    int minX = x - size;
    int minY = y - size;

    if (!image->isImgAreaX(minX))
    {
        if (minX < 0) minX = 0;
        else return;
    }
    if(!image->isImgAreaY(minY))
    {
        if (minY < 0) minY = 0;
        else return;
    }

    int maxX = x + size;
    int maxY = y + size;

    if (!image->isImgAreaX(maxX))
    {
        if (maxX < 0) return;
        else maxX = image->getWidth();
    }
    if(!image->isImgAreaY(maxY))
    {
        if (maxY < 0) return;
        else maxY = image->getHeight();
    }

    qDebug() << "Rubber(Square): x: (" << minX<< ", " << maxX<<"); y: ("<<minY<<", "<< maxY<<")";

    for(int i = minX; i < maxX; i++)
    {
        for (int j = minY; j < maxY; j++)
        {
            int z = j * img.cols * img.channels() + i * img.channels();
            img.data[z] = backgroundColor[0];
            z++;
            img.data[z] = backgroundColor[1];
            z++;
            img.data[z] = backgroundColor[2];
            z++;
            img.data[z] = 0;
        }
    }
    image->display();
}
