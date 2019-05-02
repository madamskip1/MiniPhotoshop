#ifndef IM/AGE_H
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

    void loadImg();
    void convertToQT();
public:
    void save();
    void saveAs(QString);
    Image();
    Image(QString);
    void display(QLabel*);
};

#endif // IMAGE_H
