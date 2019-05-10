#ifndef DRAW_H
#define DRAW_H

#include <opencv2/opencv.hpp>
#include "mouse.h"

class Draw : public Mouse
{
private:
    cv::Point startPoint;
    Shapes shape;
    cv::Scalar color;
public:
    Draw(DisplayImageLabel*, Image*, Shapes = Shapes::Square);

private:
    void leftClick(int, int);
    void leftMove(int, int);
    void leftRelease(int, int);

    void drawRectangle(cv::Mat, cv::Point);
    void drawCircle(cv::Mat, cv::Point);
    void drawEllipse(cv::Mat, cv::Point);
};

#endif // DRAW_H
