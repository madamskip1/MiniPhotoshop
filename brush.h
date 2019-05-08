#ifndef BRUSH_H
#define BRUSH_H

#include "mouse.h"

class Brush : public Mouse
{
private:
    double opacity;
    int size;
public:
    Brush(DisplayImageLabel*, Image*);
    void setSize(int);

private:
    void leftClick(int, int);
    void leftMove(int, int);
};

#endif // BRUSH_H
