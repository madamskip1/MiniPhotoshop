#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "image.h"
#include "mouse.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void DisplayImage(QString);
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QImage imdisplay;
    QTimer* Timer;

private slots:
    void on_actionOpen_file_triggered();

    void on_actionSave_as_triggered();

    void on_actionBlur_triggered();

    void on_actionGaussian_Blur_triggered();

    void on_actionCanny_triggered();

    void on_actiontest_triggered();

    void on_actionSquare_triggered();

    void on_actionCircle_triggered();

private:
    Ui::MainWindow *ui;
    Image * mainImg;
    Mouse * mouse;
};

#endif // MAINWINDOW_H
