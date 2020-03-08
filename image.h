#ifndef IMAGE_H
#define IMAGE_H
#include <QString>
#include <QImage>
#include <QLabel>
#include <opencv2/opencv.hpp>

class Image
{
private:
    QString path;
    cv::Mat img;
    cv::Mat imgRgb;
    QImage * qtImg;
    QLabel* displayLabel;
    cv::Scalar backgroundColor;
    bool transparent = false;   /**< is background transparent? */
    int width, height;

    void loadImg();
    void convertToQT();
public:
    Image();
    Image(QString, QLabel* = nullptr);
   // Image(cv::Mat, QLabel* = nullptr);
    //Image(const Image &obj);

    void save();
    void saveAs(QString);

    void display(QLabel* = nullptr);
    void load();

    void setDisplay(QLabel*);
    QLabel* getDisplay();
    void setPath(QString);
    QString getPath();
    cv::Mat getImg();
    void cloneImg(cv::Mat);


    cv::Scalar getBackgroundColor();
    void setBackgroundColor(cv::Scalar);
    bool isTransparent();
    void setTransparent(bool);
    void setTransparent(int);
    int getWidth();
    int getHeight();

    bool isImgArea(int, int);
    bool isImgAreaX(int);
    bool isImgAreaY(int);


public slots:
    void displaySlot(QLabel* = nullptr);
};

#endif // IMAGE_H
