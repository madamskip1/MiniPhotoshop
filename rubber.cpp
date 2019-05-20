#include <opencv2/opencv.hpp>
#include "rubber.h"
#include <QDebug>

Rubber::Rubber(DisplayImageLabel * dl, Image * img, Shapes brush, int _size) :
    Mouse(dl, img), brushType(brush)
{
    setSize(_size);
    qDebug() << "Rubber: on";
}

Rubber::~Rubber()
{
    qDebug() << "Rubber: off";
}

void Rubber::leftClick(int x, int y)
{
    switch(brushType)
    {
        case Shapes::Square:
            squareRubber(x, y);
            break;
        case Shapes::Circle:
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

    // Calculate minimum and maximum x/y coords
    cv::Scalar minMax((x-size), (x + size), (y-size), (y + size));
    minMax = calcMinMax(minMax);
    if (!isMinMax(minMax)) return;


    // Loop through pixels matching criteriums (square)

    for(int i = /*minX*/minMax[0]; i <= /*maxX*/minMax[1]; i++)
    {
        for (int j = /*minY*/minMax[2]; j <= /*maxY*/minMax[3]; j++)
        {
            int z = j * img.cols * img.channels() + i * img.channels();
            img.data[z] = backgroundColor[0]; // R red channel
            z++;
            img.data[z] = backgroundColor[1]; // G green channel
            z++;
            img.data[z] = backgroundColor[2]; // B blue channel
            z++;

            img.data[z] = 0; // Alpha channel - 0 = full transparent
        }
    }
    image->display();
}

void Rubber::circleRubber(int x, int y)
{
    cv::Mat img = image->getImg();
    cv::Scalar backgroundColor = image->getBackgroundColor();

    // Calculate minimum and maximum x/y coords
    cv::Scalar minMax((x - size), (x + size), (y - size), (y + size));
    minMax = calcMinMax(minMax);
    if (!isMinMax(minMax)) return;

    // Loop through pixels matching criteriums (circle)

    for(int i = /*minX*/minMax[0]; i <= /*maxX*/minMax[1]; i++)
    {
        for (int j = /*minY*/minMax[2]; j <= /*maxY*/minMax[3]; j++)
        {

            // Check if pixel is in radius from cursor (mathematical circle definiton)
            if (!(((i - x) * (i - x) + (j - y) * (j - y)) <= (size * size))) continue;

            int z = j * img.cols * img.channels() + i * img.channels();
            img.data[z] = backgroundColor[0]; // R red channel
            z++;
            img.data[z] = backgroundColor[1]; // G green channel
            z++;
            img.data[z] = backgroundColor[2]; // B blue channel
            z++;
            img.data[z] = 0; // Alpha channel - 0 = full transparent
        }
    }
    image->display();
}
