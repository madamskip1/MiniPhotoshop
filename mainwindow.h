#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "image.h"
#include "mouse.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Ui::MainWindow *ui;
    Image * mainImg;    /**< active image */
    Mouse * mouse;      /**< handle mouse events */
    cv::Scalar color;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage imdisplay;
private:
    void deleteMouse();
    void setColor(int, int, int);

public slots:
    void colorPick(int, int, int);
private slots:


    void on_actionOpen_file_triggered();

    void on_actionSave_as_triggered();

    void on_actionBlur_triggered();

    void on_actionGaussian_Blur_triggered();

    void on_actionCanny_triggered();

    void on_actiontest_triggered();

    void on_actionSquare_triggered();

    void on_actionCircle_triggered();

    void on_actioncircle_triggered();

    void on_actionOff_triggered();

    void on_actionDraw_triggered();

    void on_actionpicke_triggered();

    void on_actionSquare_2_triggered();

    void on_actionCircle_2_triggered();

    void on_drawButton_clicked();
    void on_brushButton_clicked();
    void on_rubberButton_clicked();

    void on_colorShow_clicked();
    void on_pickerButton_clicked();
};

#endif // MAINWINDOW_H
