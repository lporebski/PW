#include "manualwidget.h"
#include "ui_manualwidget.h"
#include <QMessageBox>
ManualWidget::ManualWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ManualWidget)
{
    ui->setupUi(this);
}

ManualWidget::~ManualWidget()
{
    delete ui;
}


void ManualWidget::on_pushButton_clicked()
{
    QMessageBox::information(this, "Message",ui->lineEdit->text());
}

