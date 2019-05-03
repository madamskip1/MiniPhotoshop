#ifndef FILTER_BLUR_H
#define FILTER_BLUR_H

#include "filter.h"
#include <QGridLayout>
class FilterBlur : public Filter
{
public:
    FilterBlur(Image* _img, QWidget *parent = nullptr);

private slots:
    void applyFilter();

private:
    void createOptionBox();

    QSpinBox * valBox;
};

#endif // FILTER_BLUR_H
