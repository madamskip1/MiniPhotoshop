    #ifndef MOUSE_H
#define MOUSE_H


#include <QObject>
#include <QtWidgets>
#include <opencv2/opencv.hpp>
#include "displayimagelabel.h"
#include "image.h"

enum class Shapes
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
    cv::Scalar calcMinMax(cv::Scalar);

    bool isMinMax(cv::Scalar);
    virtual void leftClick(int, int);
    virtual void leftMove(int, int);
    virtual void leftRelease(int, int);
public slots:
    void mousePressed(QMouseEvent*);
    void mouseMoved(QMouseEvent*);
    void mouseRelease(QMouseEvent*);
private:
    void rubber(int, int);
};

#endif // MOUSE_H
