#ifndef FILTER_H
#define FILTER_H

#include <QObject>
//#include <QWidget>
#include <QtWidgets>
#include <QDialog>
#include "image.h"
//#include <QDialogButtonBox>
//#include <QPushButton>

class Filter : public QDialog
{
    Q_OBJECT
private:
    QDialogButtonBox* buttonBox; /**< Box with dialog buttons */
    QPushButton* closeButton;
    QPushButton* applyButton;
    QLayout* layout;

protected:
    Image * img;
    QString optionsBoxName;
    QGroupBox* optionsBox; /**< Box with sliders, value input etc. */
    QLayout* optionLayout;

public:
    explicit Filter(QWidget *parent = nullptr);

private:
    void createButtonBox();
    virtual void createOptionBox()=0;

protected slots:
    virtual void applyFilter()=0;
protected:
    void createLayout();
};

#endif // FILTER_H
