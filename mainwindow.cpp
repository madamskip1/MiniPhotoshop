#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QFileDialog>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->display_image);
  //  Timer = new QTimer(this);
 //   connect(Timer, SIGNAL(timeout()), this, SLOT(DisplayImage()));
   // Timer->start();

//cv::Mat img= cv::imread("img.jpg");
//cv::namedWindow("My Image");
//cv::imshow("My Image", img);

    ui->display_image->setText("qweq");
  //  DisplayImage("D:\\download\\img.jpg");
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
    mainImg = new Image(fileName);
    mainImg->display(ui->display_image);
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "save as");

}
