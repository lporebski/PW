#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fraktale.h"
#include <QPainter>
#include <cmath>
#include <cstdlib>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*){
    QPainter painter(this);
    rysujFraktal(&painter);
}
