#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
