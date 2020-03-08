#include "filterblur.h"
#include <opencv2/opencv.hpp>

/**
 * @brief FilterBlur::FilterBlur a constructor.
 * @param _img
 * @param parent
 */
FilterBlur::FilterBlur(Image* _img, QWidget *parent) : Filter(parent)
{
    img = _img;
    optionsBoxName = "Blur";
    createLayout();
}

/**
 * @brief FilterBlur::createOptionBox
 *
 * Create option box with size inputs (slider and box).
 */
void FilterBlur::createOptionBox()
{
    optionsBox = new QGroupBox();
    optionsBox->setTitle((optionsBoxName));

    // Size slider
    QSlider * slider = new QSlider;
    slider->setMaximum(50);
    slider->setMinimum(1);
    slider->setSingleStep(1);
    slider->setOrientation(Qt::Horizontal);

    // Size value box
    valBox = new QSpinBox;
    valBox->setMaximum(50);
    valBox->setMinimum(1);
    valBox->setSingleStep(1);

    // Subscribe signals/slots
    connect(slider, SIGNAL(valueChanged(int)), valBox, SLOT(setValue(int)));
    connect(valBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

    // Create option layout and add widgets
    optionLayout = new QGridLayout;
    optionLayout->addWidget(slider);
    optionLayout->addWidget(valBox);

    optionsBox->setLayout(optionLayout);
}


/**
 * @brief FilterBlur::applyFilter blur
 *
 * Apply blur filter to the photo. Display photo with filter.
 */
void FilterBlur::applyFilter()
{
    cv::Size s = cv::Size(valBox->value(), valBox->value());
    cv::Mat im = img->getImg();
    cv::blur(im, im, s);
    img->display();
    close();
}
