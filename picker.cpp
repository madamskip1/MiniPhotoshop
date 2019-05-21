#include "picker.h"

/**
 * @brief Picker::Picker a constructor
 * @param dl
 * @param img
 * @param _color
 */
Picker::Picker(DisplayImageLabel * dl, Image * img, cv::Scalar & _color) :
    Mouse(dl, img), color(_color)
{
}

/**
 * @brief Picker::leftClick color picker
 *
 * Click on img to pick color from pixel and set brush/draw color
 * @param x mouse's coord
 * @param y mouses' coord
 */
void Picker::leftClick(int x, int y)
{
    cv::Mat img = image->getImg();
    int z = y * img.cols * img.channels() + x * img.channels();
    int b, g, r;

    b = img.data[z];
    g = img.data[z + 1];
    r = img.data[z + 2];

    emit colorPicked(r, g, b);
}
