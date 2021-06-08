#ifndef MANUALWIDGET_H
#define MANUALWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ManualWidget; }
QT_END_NAMESPACE

class ManualWidget : public QWidget
{
    Q_OBJECT

public:
    ManualWidget(QWidget *parent = nullptr);
    ~ManualWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ManualWidget *ui;
};
#endif // MANUALWIDGET_H
