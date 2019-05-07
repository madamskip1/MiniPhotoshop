#include <opencv2/opencv.hpp>
#include "rubber.h"

Rubber::Rubber(DisplayImageLabel * dl, Image * img) :
    Mouse(dl, img)
{

}

void Rubber::leftClick(int x, int y)
{

}

void Rubber::squareRubber(int x, int y)
{
    cv::Mat img = image->getImg();
    cv::Scalar backgroundColor = image->getBackgroundColor();
    int maxX, maxY;

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
