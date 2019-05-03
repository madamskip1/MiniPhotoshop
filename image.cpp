#include "image.h"
#include <QImage>

void Image::loadImg()
{
    img = cv::imread(path.toStdString());
    cv::cvtColor(img, imgRgb, cv::COLOR_BGR2RGB);
}

void Image::convertToQT()
{
    delete qtImg;
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

Image::Image(QString _path) : path(_path)
{
    qtImg = nullptr;
    loadImg();
    convertToQT();
}

void Image::display(QLabel * _label)
{
    _label->setPixmap(QPixmap::fromImage(*qtImg));
}
