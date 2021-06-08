#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QCloseEvent>
#include <QFont>
#include <QFontDialog>
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
void MainWindow::saveFile(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Zapisz plik"),"", tr("Plik tekstowy (*.txt)"));
        if (fileName.isEmpty())
            return;
        else {
            QFile file(fileName);
            QTextStream out(&file);
            if (!file.open(QIODevice::WriteOnly)) {
                QMessageBox::information(this, tr("Nie udało się otworzyć pliku"),
                    file.errorString());
                return;
            }else{
                out << ui -> textEdit -> toPlainText();
                file.close();
            }
       }
}
void MainWindow::closeEvent(QCloseEvent *e) {
    if(m_modified){
        switch(QMessageBox::question(this, "","Chcesz zapisać plik?\n",QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel)){
        case QMessageBox::Yes:
            saveFile();
          break;
        case QMessageBox::No:
            break;
        case QMessageBox::Cancel:
            e->ignore();
            break;
        }
    }else{
        e->accept();
    }
}

void MainWindow::on_actionNew_triggered()
{
    sWindow = new MainWindow();
    sWindow->show();
}

void MainWindow::on_actionOpen_triggered()
{
    QString text="";
    QString fileName = QFileDialog::getOpenFileName(this, tr("Otwórz plik"),"", tr("Plik tekstowy (*.txt)"));
    QFile file(fileName);
            if (!file.open(QIODevice::ReadOnly)) {
                return;
            }
            while (!file.atEnd()) {
                QString line = file.readLine();
                text+=line;
                }
            ui->textEdit->setText(text);
            m_modified=false;
            file.close();
       }

void MainWindow::on_actionSave_triggered()
{
   saveFile();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionClose_triggered()
{
    this->close();
}

void MainWindow::on_actionExit_triggered()
{
    qApp->closeAllWindows();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "Autor", "Łukasz Porębski grupa ISI3");
}

void MainWindow::on_actionAboutQt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok, QFont("Helvetica[Cronyx]", 12), this);
    if(ok){
        ui->textEdit->setFont(font);
    }
}
