#include "image.h"
#include <QImage>
#include <QDebug>

/**
 * @brief Image::Image a default constructor.
 */
Image::Image()
{
    qtImg = nullptr;
}

/**
 * @brief Image::Image a constructor
 *
 * Initalize path and displayLabel. Load image from path.
 * @param path to an image
 * @param disp reference to display label
 * @sa Image::loadImg()
 */
Image::Image(QString _path, QLabel* disp) :
    path(_path), displayLabel(disp), transparent(false)
{    qtImg = nullptr;
    loadImg();
}


/**
 * @brief Image::loadImg
 *
 * Load image from path. Convert from BGR to BGRA (add alpha channel).
 * Set width and height variables.
 */
void Image::loadImg()
{
    img = cv::imread(path.toStdString());
    width = img.cols;
    height = img.rows;
    if(displayLabel != nullptr)
    {
        displayLabel->setFixedSize(width, height);
        displayLabel->setAlignment(Qt::AlignCenter);
    }
    cv::cvtColor(img,img, cv::COLOR_BGR2BGRA);
}

/**
 * @brief Image::convertToQT
 *
 * Convert loaded image to QT-friendly format.
 */
void Image::convertToQT()
{
    delete qtImg;
    cv::cvtColor(img, imgRgb, cv::COLOR_BGRA2RGBA);
    qtImg = new QImage((uchar*)imgRgb.data, imgRgb.cols, imgRgb.rows, imgRgb.step, QImage::Format_RGBA8888);
}

/**
 * @brief Image::save
 *
 * Save the image to path.
 */
void Image::save()
{
    cv::imwrite(path.toStdString(), img);
}


/**
 * @brief Image::saveAs
 *
 * Save the image to specific path.
 * @param _path where image has to be saved.
 */
void Image::saveAs(QString _path)
{
    cv::imwrite(_path.toStdString(), img);
}


/**
 * @brief Image::display
 *
 * Display image on an label. If not specific (default param) display on displayLabel.
 * @param _label where image has to be displayed. Default nullptr.
 */
void Image::display(QLabel * _label)
{
    convertToQT();
    if(_label != nullptr)_label->setPixmap(QPixmap::fromImage(*qtImg));
    else displayLabel->setPixmap(QPixmap::fromImage(*qtImg));

}

/**
 * @brief Image::load
 *
 * Call private function loadImg();
 * @sa loadImg()
 */
void Image::load()
{
    loadImg();
}

// Getters and Setters

/**
 * @brief Image::setDisplay
 *
 * Set displayLabel.
 * @param disp reference to QLabel.
 */
void Image::setDisplay(QLabel * disp)
{
    displayLabel = disp;
}

/**
 * @brief Image::getDisplay
 *
 * Get displayLabel.
 * @return displayLabel
 */
QLabel *Image::getDisplay()
{
    return displayLabel;
}

/**
 * @brief Image::setPath
 *
 * Set path.
 * @param _path string
 */
void Image::setPath(QString _path)
{
    path = _path;
}

/**
 * @brief Image::getPath
 *
 * Get path.
 * @return path
 */
QString Image::getPath()
{
    return path;
}


/**
 * @brief Image::getImg
 *
 * Get a smart pointer to cv::Mat Image
 * @return image
 */
cv::Mat Image::getImg()
{
    return img;
}

/**
 * @brief Image::cloneImg
 *
 * Clone cv::Mat image
 * @param obj clonned image
 */
void Image::cloneImg(cv::Mat obj)
{
    qtImg = nullptr;
    img = obj.clone();
}

/**
 * @brief Image::getBackgroundColor
 *
 * Get backgroundColor.
 * @return backgroundColor
 */
cv::Scalar Image::getBackgroundColor()
{
    return backgroundColor;
}

/**
 * @brief Image::setBackgroundColor
 *
 * Set backgroundColor
 * @param bg background color
 */
void Image::setBackgroundColor(cv::Scalar bg)
{
    backgroundColor = bg;
}

/**
 * @brief Image::isTransparent
 *
 * Check if image support transparency.
 * @return true if support, else false
 */
bool Image::isTransparent()
{
    return transparent;
}

/**
 * @brief Image::setTransparent
 *
 * Set transparent.
 * @param trans true if transparency, else false
 */
void Image::setTransparent(bool trans)
{
    transparent = trans;
}

/**
 * @brief Image::setTransparent
 *
 * Set transparent.
 * @param trans 1 if transparency, else != 1
 */
void Image::setTransparent(int trans)
{
    if (trans == 1) transparent = true;
    else transparent = false;
}

/**
 * @brief Image::getWidth
 *
 * Get width.
 * @return width
 */
int Image::getWidth()
{
    return width;
}

/**
 * @brief Image::getHeight
 *
 * Get height.
 * @return height
 */
int Image::getHeight()
{
    return height;
}

// Getters and Setters end

/**
 * @brief Image::isImgArea
 *
 * Check if Point(x, y) is in image area.
 * @param x coord
 * @param y coord
 * @return True if is in area, else false
 */
bool Image::isImgArea(int x, int y)
{
    if(x >= 0 && y >= 0 && x < width && y < height) return true;
    return false;
}

/**
 * @brief Image::isImgAreaX
 *
 * Check if x coord is in image area.
 * @param x coord
 * @return True if is in area, else false
 */
bool Image::isImgAreaX(int x)
{
    if (x >= 0 && x < width) return true;
    else return false;
}

/**
 * @brief Image::isImgAreaY
 *
 * Check if y coord is in image area.
 * @param y coord
 * @return True if is in area, else false
 */
bool Image::isImgAreaY(int y)
{
    if (y >= 0 && y < height) return true;
    else return false;
}


/**
 * @brief Image::displaySlot
 *
 * Display image to specific label.
 * @param _label where image has to be displayed.
 * @sa display()
 */
void Image::displaySlot(QLabel * _label)
{
    display(_label);
}
