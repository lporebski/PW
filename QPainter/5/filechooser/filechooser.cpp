#include "filechooser.h"
#include <QFileDialog>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>

FileChooser::FileChooser(QWidget *parent)
    : QWidget(parent)
{
    lineEdit = new QLineEdit(this);
    button = new QPushButton(tr("..."), this);
    lineEdit->setGeometry(5, 5, 200, 20);
    button->setGeometry(210, 5, 20, 20);
    QHBoxLayout *layout= new QHBoxLayout(this);
    layout->addWidget(lineEdit);
    layout->addWidget(button);
    connect(button, SIGNAL(clicked()),this,SLOT(chooseFile()));
}

void FileChooser::chooseFile() {
    QString path=QFileDialog::getOpenFileName(this);
    setFile(path);
}
QString FileChooser::file() const{
    return lineEdit->text();
}
void FileChooser::setFile(const QString &file){
    lineEdit->setText(file);
}
