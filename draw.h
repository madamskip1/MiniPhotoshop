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
    Draw(DisplayImageLabel*, Image*);

private:
    void leftClick(int, int);
    void leftMove(int, int);
    void leftRelease(int, int);
};

#endif // DRAW_H
