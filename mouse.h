#ifndef MOUSE_H
#define MOUSE_H


#include <QObject>
#include <QtWidgets>
#include "displayimagelabel.h"
#include "image.h"

enum class Brushes
{
    Circle,
    Square,

};

class Mouse : public QLabel
{
Q_OBJECT

signals:
  //  void mousePressed(QPoint*);
public:
    Mouse(DisplayImageLabel*, Image*);
    ~Mouse();

    virtual void setSize(int);
protected:
    DisplayImageLabel * displayLabel;
    Image* image;
    virtual void leftClick(int, int);
public slots:
    void mousePressed(QMouseEvent*);
    void mouseMoved(QMouseEvent*);

private:
    void rubber(int, int);
};

#endif // MOUSE_H
