#include "draw.h"

Draw::Draw(DisplayImageLabel* dl, Image* img) :
    Mouse(dl, img)
{
    qDebug() << "Draw: on";
    color = cv::Scalar(18, 35, 200, 255);
}

void Draw::leftClick(int x, int y)
{
    startPoint = cv::Point(x, y);
}

void Draw::leftMove(int x, int y)
{
    cv::Point p(x, y);
    Image temp = *image;
    temp.cloneImg(image->getImg());
    cv::Mat tempMat = temp.getImg();
    cv::rectangle(tempMat, startPoint, p, color, -1);
    temp.display();
}

void Draw::leftRelease(int x, int y)
{
    cv::Point p(x, y);
    cv::Mat img = image->getImg();
    cv::rectangle(img, startPoint, p, color, -1);
    image->display();
}
