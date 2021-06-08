#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showTime();
    void setAlarm();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int h;
    int min;
    QString message;
    bool alert=false;
};
#endif // MAINWINDOW_H
