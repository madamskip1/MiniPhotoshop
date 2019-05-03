#ifndef IMAGE_H
#define IMAGE_H
#include <QString>
#include <QImage>
#include <QLabel>
#include <opencv2/opencv.hpp>

class Image
{
private:
    QString name;
    QString format;
    QString path;
    cv::Mat img;
    cv::Mat imgRgb;
    QImage * qtImg;
    QLabel* displayLabel;

    void loadImg();
    void convertToQT();
public:
    void save();
    void saveAs(QString);
    Image();
    Image(QString, QLabel* = nullptr);
    void display(QLabel* = nullptr);
    void blur();

    void setDisplay(QLabel*);
    cv::Mat* getImg();
};

#endif // IMAGE_H
