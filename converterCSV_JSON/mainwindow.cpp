#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>

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
            }
                    QString text = "";
                    QStringList split;
                    QJsonArray jsonArray;
                    QString fileWriteName = QFileDialog::getSaveFileName(this, "Zapisz", "", "Plik tekstowy (*.json)");
                    if (fileWriteName != "") {
                        QFile fileWrite(fileWriteName);
                        if (fileWrite.open(QIODevice::ReadWrite)){

                            while (!file.atEnd()) {
                                QString line = file.readLine();
                                split = line.split(',');
                                text = split[6];
                                text = text.remove(QChar('\r'));
                                text = text.remove(QChar('\n'));
                                split[6] = text;

                                text = split[1];
                                split[1] = text;

                                 QJsonObject jsonObject;

                                 jsonObject.insert("ID_Eksperymentu", QJsonValue::fromVariant(split[0]));
                                 jsonObject.insert("Prowadzacy", QJsonValue::fromVariant(split[1]));
                                 jsonObject.insert("Rezultat", QJsonValue::fromVariant(split[2]));
                                 jsonObject.insert("Temperatura", QJsonValue::fromVariant(split[3]));
                                 jsonObject.insert("Cisnienie", QJsonValue::fromVariant(split[4]));
                                 jsonObject.insert("Wiatr", QJsonValue::fromVariant(split[5]));
                                 jsonObject.insert("Projekt", QJsonValue::fromVariant(split[6]));
                                 jsonArray.push_back(jsonObject);
                            }
                            QJsonDocument eksperymenty(jsonArray);
                            qDebug() << eksperymenty.toJson();
                            fileWrite.write(eksperymenty.toJson(QJsonDocument::Indented));
                            file.close();
                        }
                    }

}

