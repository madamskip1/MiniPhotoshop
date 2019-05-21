#include "picker.h"

Picker::Picker(DisplayImageLabel * dl, Image * img, cv::Scalar & _color) :
    Mouse(dl, img), color(_color)
{
}


void Picker::leftClick(int x, int y)
{
    cv::Mat img = image->getImg();
    int z = y * img.cols * img.channels() + x * img.channels();
    int b, g, r;
    b = img.data[z];
    g = img.data[z + 1];
    r = img.data[z + 2];
    emit colorPicked(r, g, b);
}
