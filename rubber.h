#ifndef RUBBER_H
#define RUBBER_H

#include "mouse.h"


class Rubber : public Mouse
{
private:
    int size;
    Brushes brushType;
public:
    Rubber(DisplayImageLabel*, Image*);

private:
    void leftClick(int, int);
    void squareRubber(int, int);
};

#endif // RUBBER_H
