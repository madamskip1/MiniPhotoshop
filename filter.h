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
public:
    explicit Filter(QWidget *parent = nullptr);
signals:

public slots:

protected slots:
//    virtual void applyFilter()=0;

private:
    void createButtonBox();
    virtual void createOptionBox()=0;

    QDialogButtonBox* buttonBox;
    QPushButton* closeButton;
    QPushButton* applyButton;

    QLayout* layout;

protected slots:
    virtual void applyFilter()=0;
protected:
    void createLayout();

    Image * img;
    QString optionsBoxName;

    QGroupBox* optionsBox;
    QLayout* optionLayout;
};

#endif // FILTER_H
