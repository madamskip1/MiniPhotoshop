#ifndef FILTERGAUSSBLUR_H
#define FILTERGAUSSBLUR_H

#include "filter.h"

class FilterGaussBlur : public Filter
{
public:
    FilterGaussBlur(Image* _img, QWidget *parent = nullptr);

private slots:
    void applyFilter();
    void check_Odd();

private:
    void createOptionBox();

    QSpinBox * sizeValBox;
    QSpinBox * devValBox;
};

#endif // FILTERGAUSSBLUR_H
