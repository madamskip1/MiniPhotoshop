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
    //qDebug() << ev->buttons();
   // if(!(ev->buttons() & Qt::LeftButton)) return;
}
