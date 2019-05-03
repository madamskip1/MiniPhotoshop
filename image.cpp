#include "image.h"
#include <QImage>

void Image::loadImg()
{
    img = cv::imread(path.toStdString());
}
void Image::convertToQT()
{
    delete qtImg;
    cv::cvtColor(img, imgRgb, cv::COLOR_BGR2RGB);
    qtImg = new QImage((uchar*)imgRgb.data, imgRgb.cols, imgRgb.rows, imgRgb.step, QImage::Format_RGB888);
}

void Image::save()
{
    cv::imwrite(path.toStdString(), img);
}

void Image::saveAs(QString _path)
{
    cv::imwrite(_path.toStdString(), img);
}

Image::Image()
{
    qtImg = nullptr;
}

Image::Image(QString _path, QLabel* disp) : path(_path)
{
    qtImg = nullptr;
    displayLabel = disp;
    loadImg();
}

void Image::display(QLabel * _label)
{
    convertToQT();
    if(_label != nullptr)_label->setPixmap(QPixmap::fromImage(*qtImg));
    else displayLabel->setPixmap(QPixmap::fromImage(*qtImg));
}

void Image::blur()
{
    cv::Size s = cv::Size(50,50);
    cv::blur(img, img, s);
    convertToQT();
}

void Image::setDisplay(QLabel * disp)
{
    displayLabel = disp;
}

cv::Mat* Image::getImg()
{
    return &img;
}
