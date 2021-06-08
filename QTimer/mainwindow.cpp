#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QTimer>
#include <QLCDNumber>
#include <QPlainTextEdit>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::showTime);
        timer->start(1000);

        showTime();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setAlarm(){
    h=ui->spinBox->value();
    min=ui->spinBox_2->value();
    message = ui->plainTextEdit->toPlainText();
    alert = true;
}

void MainWindow::showTime()
{

    QTime time = QTime::currentTime();
        QString text = time.toString("hh:mm");
        if ((time.second() % 2) == 0)
            text[2] = ' ';
        if(time.hour()==h && time.minute() == min && alert == true){
            QMessageBox::about(this, "Alarm", message);
            alert = false;
        }
        ui ->lcdNumber -> display(text);
}



void MainWindow::on_pushButton_clicked()
{
    setAlarm();
}

