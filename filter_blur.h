#ifndef FILTER_BLUR_H
#define FILTER_BLUR_H

#include "filter.h"
#include <QGridLayout>
class Filter_Blur : public Filter
{
public:
    Filter_Blur(Image* _img, QWidget *parent = nullptr);

private slots:
    void applyFilter();
private:
    void createOptionBox();
//    void applyFilter();

    QSpinBox * valBox;
};

#endif // FILTER_BLUR_H
