#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "filterblur.h"
#include "filtergaussblur.h"
#include "mouse.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->display_image);

    ui->display_image->setText("qweq");
    mainImg = new Image();
    mainImg->setPath("D:\\Download\\img.jpg");
    mainImg->setDisplay(ui->display_image);
    mainImg->load();
    mainImg->display();
    Mouse * mouse = new Mouse(this->ui->display_image, mainImg);
//    connect(ui->display_image, &DisplayImageLabel::mouseLeftClick, mouse, &Mouse::mousePressed);
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
    //mainImg = new Image(fileName, ui->display_image);
    mainImg->setPath(fileName);
    mainImg->setDisplay(ui->display_image);
    mainImg->load();
    mainImg->display();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "save as");
    mainImg->saveAs(fileName);
}

void MainWindow::on_actionBlur_triggered()
{
    Filter* fil = new FilterBlur(mainImg);
    fil->exec();
}

void MainWindow::on_actionGaussian_Blur_triggered()
{
    Filter* fil = new FilterGaussBlur(mainImg);
    fil->exec();
}

void MainWindow::on_actionCanny_triggered()
{
//    Image * im = new Image("D:\\download\\img.jpg", ui->display_image);
//    cv::Mat img = im->getImg();

//    cv::Canny(mainImg->getImg(), img, 30, 90);
//    im->display();
}

void MainWindow::on_actiontest_triggered()
{

}
