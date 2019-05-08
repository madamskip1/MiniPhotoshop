#include "displayimagelabel.h"
#include <QDebug>


DisplayImageLabel::DisplayImageLabel(QWidget *parent) : QLabel(parent)
{
    this->setText("qweqweqw");
}

void DisplayImageLabel::mousePressEvent(QMouseEvent * ev)
{
    if(ev->button() == Qt::LeftButton)
        emit mouseLeftClick(ev);
    else if(ev->button() == Qt::RightButton)
        emit mouseRightClick(ev);
    else if(ev->button() == Qt::MiddleButton)
        emit mouseMiddleClick(ev);
}

void DisplayImageLabel::mouseMoveEvent(QMouseEvent * ev)
{
    emit mouseMove(ev);
}

void DisplayImageLabel::mouseReleaseEvent(QMouseEvent * ev)
{
    switch(ev->button())
    {
    case Qt::LeftButton:
        emit mouseLeftRelease(ev);
        break;
    case Qt::RightButton:
        emit mouseRightRelease(ev);
        break;
    default:
        break;
    }
}
