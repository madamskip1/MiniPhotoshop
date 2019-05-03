#include "filtergaussblur.h"
#include <opencv2/opencv.hpp>

FilterGaussBlur::FilterGaussBlur(Image* _img, QWidget *parent) : Filter(parent)
{
    img = _img;
    optionsBoxName = "Gaussian Blur";
    createLayout();
}

void FilterGaussBlur::createOptionBox()
{
    optionsBox = new QGroupBox();
    optionsBox->setTitle((optionsBoxName));

    QLabel* sliderLabel = new QLabel;
    sliderLabel->setText("Size: ");
    QSlider * size = new QSlider;
    size->setMaximum(101);
    size->setMinimum(1);
    size->setSingleStep(2);
    size->setOrientation(Qt::Horizontal);

    sizeValBox = new QSpinBox;
    sizeValBox->setMaximum(101);
    sizeValBox->setMinimum(1);
    sizeValBox->setSingleStep(2);
    connect(size, SIGNAL(valueChanged(int)), sizeValBox, SLOT(setValue(int)));
    connect(sizeValBox, SIGNAL(valueChanged(int)), size, SLOT(setValue(int)));

    QLabel *devLabel = new QLabel;
    devLabel->setText("Deviation X: ");
    QSlider * dev = new QSlider;
    dev->setMaximum(50);
    dev->setMinimum(1);
    dev->setSingleStep(1);
    dev->setOrientation(Qt::Horizontal);

    devValBox = new QSpinBox;
    devValBox->setMaximum(50);
    devValBox->setMinimum(1);
    devValBox->setSingleStep(1);
    connect(dev, SIGNAL(valueChanged(int)), devValBox, SLOT(setValue(int)));
    connect(devValBox, SIGNAL(valueChanged(int)), dev, SLOT(setValue(int)));

    optionLayout = new QGridLayout;
    optionLayout->addWidget(sliderLabel);
    optionLayout->addWidget(size);
    optionLayout->addWidget(sizeValBox);
    optionLayout->addWidget(devLabel);
    optionLayout->addWidget(dev);
    optionLayout->addWidget(devValBox);


    optionsBox->setLayout(optionLayout);
}

void FilterGaussBlur::applyFilter()
{
    int val = sizeValBox->value();
    if (val % 2 == 0) val += 1;

    cv::Size s = cv::Size(val, val);
    cv::Mat *im = img->getImg();
    cv::GaussianBlur(*im, *im, s, devValBox->value());
    img->display();
    close();
}

void FilterGaussBlur::check_Odd()
{
    if(sizeValBox->value() % 2 == 1)
    {
        sizeValBox->setValue((sizeValBox->value())-1);
    }
}
