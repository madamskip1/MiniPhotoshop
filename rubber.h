#ifndef RUBBER_H
#define RUBBER_H

#include "mouse.h"


class Rubber : public Mouse
{
private:
    int size;
    Brushes brushType;
public:
    Rubber(DisplayImageLabel*, Image*, Brushes = Brushes::Square, int = 0);
    ~Rubber();

    void setSize(int);
private:
    void leftClick(int, int);
    void squareRubber(int, int);
    void circleRubber();
};

#endif // RUBBER_H
