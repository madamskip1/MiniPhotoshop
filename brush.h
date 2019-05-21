#ifndef BRUSH_H
#define BRUSH_H

#include <opencv2/opencv.hpp>
#include "mouse.h"

class Brush : public Mouse
{
private:
    double opacity; /**< Brush opacity (alwpha channel) */
    cv::Scalar* color;

public:
    Brush(DisplayImageLabel*, Image*, cv::Scalar*,  int = 0, double = 1.0);
private:
    void leftClick(int, int);
    void leftMove(int, int);
};

#endif // BRUSH_H
