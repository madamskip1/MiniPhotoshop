#include "image.h"
#include <QImage>
#include <QDebug>
Image::Image()
{
    qtImg = nullptr;
}

Image::Image(QString _path, QLabel* disp) :
    path(_path), transparent(false)
{
    qtImg = nullptr;
    displayLabel = disp;
    loadImg();
}

//Image::Image(const Image &obj)
//{

//}



void Image::loadImg()
{
    img = cv::imread(path.toStdString());
    width = img.cols;
    height = img.rows;
    qDebug() << width << " - " << height;
    cv::cvtColor(img,img, cv::COLOR_BGR2BGRA);
}
void Image::convertToQT()
{
    delete qtImg;
    cv::cvtColor(img, imgRgb, cv::COLOR_BGRA2RGBA);
    qtImg = new QImage((uchar*)imgRgb.data, imgRgb.cols, imgRgb.rows, imgRgb.step, QImage::Format_RGBA8888);
}

void Image::save()
{
    cv::imwrite(path.toStdString(), img);
}

void Image::saveAs(QString _path)
{
    cv::imwrite(_path.toStdString(), img);
}



void Image::display(QLabel * _label)
{
    convertToQT();
    if(_label != nullptr)_label->setPixmap(QPixmap::fromImage(*qtImg));
    else displayLabel->setPixmap(QPixmap::fromImage(*qtImg));
}

void Image::load()
{
    loadImg();
}

// Getters and Setters

void Image::setDisplay(QLabel * disp)
{
    displayLabel = disp;
}

QLabel *Image::getDisplay()
{
    return displayLabel;
}

void Image::setPath(QString _path)
{
    path = _path;
}

QString Image::getPath()
{
    return path;
}

cv::Mat Image::getImg()
{
    return img;
}

void Image::cloneImg(cv::Mat obj)
{
    img = obj.clone();
}


cv::Scalar Image::getBackgroundColor()
{
    return backgroundColor;
}

void Image::setBackgroundColor(cv::Scalar bg)
{
    backgroundColor = bg;
}

bool Image::isTransparent()
{
    return transparent;
}

void Image::setTransparent(bool trans)
{
    transparent = trans;
}

void Image::setTransparent(int trans)
{
    if (trans == 1) transparent = true;
    else transparent = false;
}

int Image::getWidth()
{
    return width;
}

int Image::getHeight()
{
    return height;
}

// Getters and Setters end

bool Image::isImgArea(int x, int y)
{
    if(x >= 0 && y >= 0 && x < width && y < height) return true;
    return false;
}

bool Image::isImgAreaX(int x)
{
    if (x >= 0 && x < width) return true;
    else return false;
}

bool Image::isImgAreaY(int y)
{
    if (y >= 0 && y < height) return true;
    else return false;
}

void Image::displaySlot(QLabel * _label)
{
    display(_label);
}
