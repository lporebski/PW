#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QXmlStreamWriter>
#include <QMessageBox>

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


void MainWindow::on_pushButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Otwórz"), QDir::currentPath());
    QFile file(filename);
            if (!file.open(QIODevice::ReadOnly)) {
                qDebug() << file.errorString();
            }
            QXmlStreamWriter xmlWriter(&file);
                    QString text = "";
                    QStringList split;
                    int i = 0;
                    QString fileWriteName = QFileDialog::getSaveFileName(this, "Zapisz", "", "Plik tekstowy (*.xml)");
                    if (fileWriteName != "") {
                        QFile fileWrite(fileWriteName);
                        if (fileWrite.open(QIODevice::ReadWrite)){

                            QXmlStreamWriter stream(&fileWrite);
                            stream.setAutoFormatting(true);

                            stream.writeStartDocument();
                            while (!file.atEnd()) {
                                QString line = file.readLine();
                                split = line.split(',');

                                text = split[6];
                                split[6] = text;
                                stream.writeStartElement("Projekt");
                                stream.writeAttribute("nazwa", split[6]);
                                stream.writeStartElement("Experyment");
                                stream.writeAttribute("id", split[0]);
                                stream.writeAttribute("naukowiec_id", QString::number(i));
                                stream.writeTextElement("Rezultat", split[2]);
                                stream.writeTextElement("Temperatura", split[3]);
                                stream.writeTextElement("Ciśnienie", split[4]);
                                stream.writeTextElement("Wiatr", split[5]);
                                stream.writeEndElement();
                                stream.writeEndElement();
                                i++;
                            }

                            file.close();
                        }
                    }

}

