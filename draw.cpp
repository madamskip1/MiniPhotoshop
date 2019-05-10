#include "draw.h"

Draw::Draw(DisplayImageLabel* dl, Image* img, Shapes _shape) :
    Mouse(dl, img)
{
    qDebug() << "Draw: on";
    color = cv::Scalar(18, 35, 200, 255);
    shape = _shape;
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

    switch (shape)
    {
    case Shapes::Square:
        drawRectangle(tempMat, p);
        break;
    case Shapes::Circle:
        drawCircle(tempMat, p);
        break;
    }
    temp.display();

}

void Draw::leftRelease(int x, int y)
{
    cv::Point p(x, y);
    cv::Mat img = image->getImg();
    switch (shape)
    {
    case Shapes::Square:
        drawRectangle(img, p);
        break;
    case Shapes::Circle:
        drawCircle(img, p);
        break;
    }
    image->display();
}

void Draw::drawRectangle(cv::Mat img, cv::Point p)
{
    cv::rectangle(img, startPoint, p, color, -1);
}

void Draw::drawCircle(cv::Mat img, cv::Point p)
{
    int deltaX = p.x - startPoint.x;
    int deltaY = p.y - startPoint.y;
    int radius = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    cv::circle(img, startPoint, radius, color, -1);
}

void Draw::drawEllipse(cv::Mat img, cv::Point p)
{

}
