#ifndef PICKER_H
#define PICKER_H

#include <opencv2/opencv.hpp>
#include "mouse.h"

class Picker : public Mouse
{
    Q_OBJECT
private:
    cv::Scalar& color;
public:
    Picker(DisplayImageLabel*, Image*, cv::Scalar&);

private:
    void leftClick(int, int);

signals:
    void colorPicked(int, int, int);
};

#endif // PICKER_H
