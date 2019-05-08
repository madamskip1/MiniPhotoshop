#ifndef RUBBER_H
#define RUBBER_H

#include "mouse.h"


class Rubber : public Mouse
{
private:
    int size;
public:
    Rubber(DisplayImageLabel*, Image*, Brushes = Brushes::Circle, int = 0);
    ~Rubber();

    void setSize(int);
private:
    void leftClick(int, int);
    void leftMove(int, int);
    void squareRubber(int, int);
    void circleRubber(int, int);
};

#endif // RUBBER_H
