#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QFileDialog>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

#include "filter_blur.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->display_image);

    ui->display_image->setText("qweq");
    mainImg = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayImage(QString fileName)
{
Mat img;
img = imread(fileName.toStdString());
cvtColor(img, img, cv::COLOR_BGR2RGB);
QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
ui->display_image->setPixmap(QPixmap::fromImage(imdisplay));
}

void MainWindow::on_actionOpen_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Otwórz plik");
    if(fileName == "") return;
    mainImg = new Image(fileName, ui->display_image);
    mainImg->display();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "save as");
    mainImg->saveAs(fileName);
}

void MainWindow::on_actionBlur_triggered()
{
    Filter* fil = new Filter_Blur(mainImg);
    fil->exec();

    //mainImg->blur();
    //mainImg->display(ui->display_image);
}
