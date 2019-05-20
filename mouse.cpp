#include "mouse.h"
#include <QDebug>

/**
 * @brief Mouse::Mouse constructor
 *
 * Initalize displayLabel and image. Subscribe signals from mouse.
 * @param dl DisplayImageLabel where image will be displayed.
 * @param img reference to image
 */
Mouse::Mouse(DisplayImageLabel* dl, Image* img) :
    displayLabel(dl), image(img)
{

    connect(displayLabel, &DisplayImageLabel::mouseLeftClick, this, &Mouse::mousePressed);
    connect(displayLabel, &DisplayImageLabel::mouseMove, this, &Mouse::mouseMoved);
    connect(displayLabel, &DisplayImageLabel::mouseLeftRelease, this, &Mouse::mouseRelease);
}

/**
 * @brief Mouse::~Mouse destructor.
 */
Mouse::~Mouse()
{

}

/**
 * @brief Mouse::setSize set cursor's size.
 *
 * Set size for cursor.
 * For square size is distance between border and cursor point.
 * For circle size is circle's radius (from cursor point).
 * @param _size
 */

void Mouse::setSize(int _size)
{
    size = _size;
}


/**
 * @brief Mouse::calcMinMax - calculate minMax Scalar
 *
 * Calculate minimum and maximum position for cursor.
 * From 0 to image width or height.
 * @param minMax precalculated values.
 * @return cv::Scalar new minMax values
 */
cv::Scalar Mouse::calcMinMax(cv::Scalar minMax)
{
    if (!image->isImgAreaX(minMax[0]))
    {
        if (minMax[0] < 0) minMax[0] = 0;
        else
        {
            minMax[0] = -1;
            return minMax;
        }
    }

    if (!image->isImgAreaX(minMax[1]))
    {
        if (minMax[1] < 0)
        {
            minMax[1] = -1;
            return minMax;
        } else minMax[1] = image->getWidth();
    }

    if (!image->isImgAreaY(minMax[2]))
    {
        if (minMax[2] < 0) minMax[2] = 0;
        else
        {
            minMax[2] = -1;
            return minMax;
        }
    }

    if (!image->isImgAreaY(minMax[3]))
    {
        if (minMax[3] < 0)
        {
            minMax[3] = -1;
            return minMax;
        } else minMax[3] = image->getHeight() - 1;
    }

    return minMax;
}

/**
 * @brief Mouse::isMinMax - minMax validator.
 *
 * Check if  minMax calculated in calcMinMax() is valid.
 * @param minMax cv::Scalar calculated in calcMinMax()
 * @return True if minMax is valid, else false
 * @sa calcMinMax()
 */
bool Mouse::isMinMax(cv::Scalar minMax)
{
    for (int i = 0; i < 4; i++)
    {
        if (minMax[i] == -1) return false;
    }
    return true;
}

/**
 * @brief Mouse::leftClick - mouse's left button click event.
 *
 * Virtual member function. Triggered when left click mouse on the image.
 * @param x mouse's coord
 * @param y mouse's coord
 */
void Mouse::leftClick(int, int)
{

}

/**
 * @brief Mouse::leftMove - mouse's move with left button clicked.
 *
 * Virtual member function. Triggered when moving mouse with left button pressed.
 * @param x mouse's coord
 * @param y mouse's coord
 */
void Mouse::leftMove(int, int)
{

}

/**
 * @brief Mouse::leftRelease - mouse's left button release event.
 *
 * Virutal member function. Triggered after left button released.
 * @param x mouse's coord (int)
 * @param y mouse's coord (int)
 */
void Mouse::leftRelease(int, int)
{

}


/**
 * @brief Mouse::mousePressed - mouse pressed slot.
 *
 * Slot  that receives the signal after clicking
 * the mouse. Then it calls functions leftClick().
 * @param ev QMouseEvent mouse's event
 *
 * @sa leftClick()
 */
void Mouse::mousePressed(QMouseEvent * ev)
{
    int x = ev->x();
    int y = ev->y();

    leftClick(x, y);
    return;
}

/**
 * @brief Mouse::mouseMoved - mouse moved slot.
 *
 * Slot that receives the signal after moving
 * the mouse. Then it calls functions leftMove().
 * @param ev QMouseEvent mouse's event
 *
 * @sa leftMove()
 */
void Mouse::mouseMoved(QMouseEvent * ev)
{
    int x = ev->x();
    int y = ev->y();

    if(ev->buttons() & Qt::LeftButton) leftMove(x, y);

    return;
}

/**
 * @brief Mouse::mouseRelease - mouse released slot.
 *
 * Slot that receives the signal after release
 * mouse button. Then it calls functions leftRelease().
 * @param ev QMouseEvent mouse's event
 *
 * @sa leftRelease()
 */
void Mouse::mouseRelease(QMouseEvent * ev)
{
    int x = ev->x();
    int y = ev->y();

    leftRelease(x, y);
}
