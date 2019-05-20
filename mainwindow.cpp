#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTimer>
#include <QFileDialog>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include "filterblur.h"
#include "filtergaussblur.h"
#include "mouse.h"
#include "rubber.h"
#include "brush.h"
#include "draw.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainWidget->setLayout(ui->horizontalLayout);
    this->setCentralWidget(ui->mainWidget);
    ui->display_image->setText("qweq");
    ui->menu->setLayout(ui->menuGrid);

    // Create Image object. Load default img.
    mainImg = new Image();
    mainImg->setPath("D:\\Download\\img.jpg");
    mainImg->setDisplay(ui->display_image);
    mainImg->load();
    mainImg->display();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Otwórz plik");
    if(fileName == "") return;

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

void MainWindow::on_actionSquare_triggered()
{
    delete mouse;
    mouse = new Rubber(ui->display_image, mainImg, Shapes::Square);
    mouse->setSize(35);
}

void MainWindow::on_actionCircle_triggered()
{
    delete mouse;
    mouse = new Rubber(ui->display_image, mainImg);
    mouse->setSize(40);
}

void MainWindow::on_actioncircle_triggered()
{
    delete mouse;
    mouse = new Brush(ui->display_image, mainImg);
}

void MainWindow::on_actionOff_triggered()
{
    delete mouse;
}

void MainWindow::on_actionDraw_triggered()
{
//    delete mouse;
//    mouse = new Draw(ui->display_image, mainImg);
}

void MainWindow::on_actionpicke_triggered()
{
    QColor color = QColorDialog::getColor();
    qDebug() << color.name();
}

void MainWindow::on_actionSquare_2_triggered()
{
    delete mouse;
    mouse = new Draw(ui->display_image, mainImg, Shapes::Square);
}

void MainWindow::on_actionCircle_2_triggered()
{
    delete mouse;
    mouse = new Draw(ui->display_image, mainImg, Shapes::Circle);
}

void MainWindow::on_drawButton_clicked()
{
    qDebug() << "Draw clicked";
}
