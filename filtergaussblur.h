#ifndef FILTERGAUSSBLUR_H
#define FILTERGAUSSBLUR_H

#include "filter.h"

class FilterGaussBlur : public Filter
{
private:
    QSpinBox * sizeValBox;  /**< reference to size input */
    QSpinBox * devValBox;   /**< reference to deviation input */
public:
    FilterGaussBlur(Image* _img, QWidget *parent = nullptr);

private slots:
    void applyFilter();

private:
    void createOptionBox();

};

#endif // FILTERGAUSSBLUR_H
