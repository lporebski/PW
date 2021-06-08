#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLineEdit>
#include <QListWidget>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QFileDialog>
#include <QFile>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->listWidget->setDragDropMode(QAbstractItemView::InternalMove);
    connect(ui->clearButton, SIGNAL(clicked()),ui->listWidget, SLOT(clear()));

}


MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "O Autorze", "Łukasz Porębski grupa ISI3");
    QMessageBox::aboutQt(this, "O QT");
}

void MainWindow::on_acceptButton_clicked(){
    QString login_password;
    QString loginText = ui->loginEdit->text();
    QString passwordText = ui->passwordEdit->text();
    QString serviceText = ui->serviceEdit->text();
    if(loginText.isEmpty()){
        QMessageBox::critical(this, "Alarm", "Podaj login");
    }else if(passwordText.isEmpty()){
        QMessageBox::critical(this, "Alarm", "Podaj hasło");
    }else if(serviceText.isEmpty()){
        QMessageBox::critical(this, "Alarm", "Podaj serwis");
    }else{
        login_password =loginText+" - "+passwordText+" - "+serviceText;
        ui->listWidget->addItem(login_password);
        ui->loginEdit->clear();
        ui->passwordEdit->clear();
        ui->serviceEdit->clear();
    }
}


void MainWindow::on_deleteButton_clicked(){
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete ui->listWidget->takeItem(ui->listWidget->row(item));
    }
}


void MainWindow::on_editButton_clicked(){
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
       item->setFlags(item->flags() | Qt::ItemIsEditable);
       ui->listWidget->editItem(item);

    }

}



void MainWindow::on_generateButton_clicked(){
    const char alpha[] = "0123456789!@#$%^&*abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int strLen=sizeof(alpha)-1;
    QString password = "";
    srand(time(0));
    QString passwordText = ui->passwordEdit->text();
    for(int i = 0; i < 9; i++){
        password +=alpha[rand() % strLen];
    }
    ui->passwordEdit->setText(password);
}



bool checked = true;

void MainWindow::on_hideButton_clicked()
{

    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        if(checked == true){
            item->setHidden(true);
            checked = false;
        }else{
            item->setHidden(false);
            checked = true;
        }

    }
}


void MainWindow::on_actionSaveFile_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Zapisz"), "*.txt");
    QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            // bind it
            QTextStream stream(&file);
            for (int i = 0; i < ui->listWidget->count(); i++) {
                QListWidgetItem *item = ui->listWidget->item(i);
                stream << item->text() << '\n';
            }

            file.close();
        }

         ui->listWidget->clear();
}


void MainWindow::on_actionOpenFile_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Otwórz"), "*.txt");
    QFile file(filename);
        if (!file.open(QIODevice::ReadOnly)){
            return;
         }
            ui->listWidget->clear();
            while (!file.atEnd()) {
                QString line = file.readLine();
                ui->listWidget->addItem(line);
                }
}




