#include "filter_blur.h"
#include <opencv2/opencv.hpp>
Filter_Blur::Filter_Blur(Image* _img, QWidget *parent) : Filter(parent)
{
    img = _img;
    optionsBoxName = "Blur";
    createLayout();
}

void Filter_Blur::createOptionBox()
{
    optionsBox = new QGroupBox();
    optionsBox->setTitle((optionsBoxName));

    QSlider * slider = new QSlider;
    slider->setMaximum(50);
    slider->setMinimum(1);
    slider->setSingleStep(1);
    slider->setOrientation(Qt::Horizontal);

    valBox = new QSpinBox;
    valBox->setMaximum(50);
    valBox->setMinimum(1);
    valBox->setSingleStep(1);
    connect(slider, SIGNAL(valueChanged(int)), valBox, SLOT(setValue(int)));
    connect(valBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));


    optionLayout = new QGridLayout;
    optionLayout->addWidget(slider);
    optionLayout->addWidget(valBox);

    optionsBox->setLayout(optionLayout);
}

void Filter_Blur::applyFilter()
{
    cv::Size s = cv::Size(valBox->value(), valBox->value());
    cv::Mat *im = img->getImg();
    cv::blur(*im, *im, s);
    img->display();
    close();
}
