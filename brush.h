#ifndef BRUSH_H
#define BRUSH_H

#include "mouse.h"

class Brush : public Mouse
{
private:
    double opacity; /**< Brush opacity (alpha channel) */
public:
    Brush(DisplayImageLabel*, Image*, int = 0, double = 1.0);
private:
    void leftClick(int, int);
    void leftMove(int, int);
};

#endif // BRUSH_H
