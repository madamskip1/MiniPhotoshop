#include "draw.h"

Draw::Draw(DisplayImageLabel* dl, Image* img, cv::Scalar* _color, Shapes _shape = Shapes::Square) :
    Mouse(dl, img),  shape(_shape), color(_color)
{
}

/**
 * @brief Draw::leftClick
 *
 * set startPoint with x, y coords.
 * @param x mouse's coord
 * @param y mouse's coord
 */
void Draw::leftClick(int x, int y)
{
    startPoint = cv::Point(x, y);
}


/**
 * @brief Draw::leftMove
 *
 * Draw temp shape from startPoint to x, y (params).
 * @param x mouse's coord
 * @param y mouse's coord
 */
void Draw::leftMove(int x, int y)
{
    cv::Point p(x, y);

    // Clone image to display temp shape
    Image temp = *image;
    temp.cloneImg(image->getImg());
    cv::Mat tempMat = temp.getImg();

    switch (shape)
    {
    case Shapes::Square:
        drawRectangle(tempMat, p);
        break;
    case Shapes::Circle:
    default:
        drawCircle(tempMat, p);
        break;
    }
    temp.display();

}

/**
 * @brief Draw::leftRelease
 *
 * Draw final shape to displayed image.
 * @param x mouse's coord
 * @param y mouse's coord
 */
void Draw::leftRelease(int x, int y)
{
    cv::Point p(x, y);
    cv::Mat img = image->getImg();
    switch (shape)
    {
    case Shapes::Square:
        drawRectangle(img, p);
        break;
    case Shapes::Circle:
    default:
        drawCircle(img, p);
        break;
    }
    image->display();
}

/**
 * @brief Draw::drawRectangle
 *
 * Draw rectangle with specific color and size.
 * @param img
 * @param p Point(x, y)
 */
void Draw::drawRectangle(cv::Mat img, cv::Point p)
{
    cv::rectangle(img, startPoint, p, *color, -1);
}

/**
 * @brief Draw::drawCircle
 *
 * Draw circle with specific color and radius.
 * @param img
 * @param p Point(x, y)
 */
void Draw::drawCircle(cv::Mat img, cv::Point p)
{
    int deltaX = p.x - startPoint.x;
    int deltaY = p.y - startPoint.y;
    int radius = sqrt((deltaX * deltaX) + (deltaY * deltaY));

    cv::circle(img, startPoint, radius, *color, -1);
}

//void Draw::drawEllipse(cv::Mat img, cv::Point p)
//{

//}
