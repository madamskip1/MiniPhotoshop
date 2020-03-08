#include "displayimagelabel.h"
#include <QDebug>


/**
 * @brief DisplayImageLabel::DisplayImageLabel a constructor.
 * @param parent
 */
DisplayImageLabel::DisplayImageLabel(QWidget *parent) : QLabel(parent)
{
}

/**
 * @brief DisplayImageLabel::mousePressEvent
 *
 * Triggered when mouse's button pressed on image.
 * Emit signals with specific event.
 * Signals: mouseLeftClick(), mouseRightClick(), mouseMiddleClick().
 * @param ev QMouseEvent*
 */
void DisplayImageLabel::mousePressEvent(QMouseEvent * ev)
{
    qDebug() << ev->x()<<ev->y();
    if(ev->button() == Qt::LeftButton)
        emit mouseLeftClick(ev);
    else if(ev->button() == Qt::RightButton)
        emit mouseRightClick(ev);
    else if(ev->button() == Qt::MiddleButton)
        emit mouseMiddleClick(ev);
}

/**
 * @brief DisplayImageLabel::mouseMoveEvent
 *
 * Triggered when moving mouse over image.
 * Emit mouseMove() signal.
 * @param ev QMouseEvent*
 */
void DisplayImageLabel::mouseMoveEvent(QMouseEvent * ev)
{
    emit mouseMove(ev);
}

/**
 * @brief DisplayImageLabel::mouseReleaseEvent
 * Triggered when release move from image.
 * Emit signal with specific event.
 * Signals: mouseLeftRelease(), mouseRightRelease().
 * @param ev QMouseEvent*
 */
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
