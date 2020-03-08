#ifndef RUBBER_H
#define RUBBER_H

#include "mouse.h"


class Rubber : public Mouse
{
private:
    Shapes brushType;
public:
    Rubber(DisplayImageLabel*, Image*, Shapes = Shapes::Circle, int = 0);
    ~Rubber();

private:
    void leftClick(int, int);
    void leftMove(int, int);
    void squareRubber(int, int);
    void circleRubber(int, int);
};

#endif // RUBBER_H
