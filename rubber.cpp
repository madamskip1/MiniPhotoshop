#include <opencv2/opencv.hpp>
#include "rubber.h"
#include <QDebug>

Rubber::Rubber(DisplayImageLabel * dl, Image * img, Brushes brush, int _size) :
    Mouse(dl, img, brush),  size(_size)
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
    qDebug() << "rubber rubber rubber!!!!";
    switch(brushType)
    {
        case Brushes::Square:
            squareRubber(x, y);
            break;
        case Brushes::Circle:
            circleRubber(x, y);
            break;
    }
}

void Rubber::leftMove(int x, int y)
{
    leftClick(x, y);
}

void Rubber::squareRubber(int x, int y)
{
    cv::Mat img = image->getImg();
    cv::Scalar backgroundColor = image->getBackgroundColor();

    cv::Scalar minMax((x-size), (x + size), (y-size), (y + size));
    minMax = calcMinMax(minMax);
    if (!isMinMax(minMax)) return;

    for(int i = /*minX*/minMax[0]; i <= /*maxX*/minMax[1]; i++)
    {
        for (int j = /*minY*/minMax[2]; j <= /*maxY*/minMax[3]; j++)
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

void Rubber::circleRubber(int x, int y)
{
    cv::Mat img = image->getImg();
    cv::Scalar backgroundColor = image->getBackgroundColor();

    cv::Scalar minMax((x - size), (x + size), (y - size), (y + size));
    minMax = calcMinMax(minMax);
    if (!isMinMax(minMax)) return;

    for(int i = /*minX*/minMax[0]; i <= /*maxX*/minMax[1]; i++)
    {
        for (int j = /*minY*/minMax[2]; j <= /*maxY*/minMax[3]; j++)
        {
            if (!(((i - x) * (i - x) + (j - y) * (j - y)) <= (size * size))) continue;

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
