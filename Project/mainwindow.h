#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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


    void on_acceptButton_clicked();

    void on_deleteButton_clicked();

    void on_editButton_clicked();

    void on_generateButton_clicked();

    void on_hideButton_clicked();

    void on_actionSaveFile_triggered();

    void on_actionOpenFile_triggered();

    void on_actionAbout_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
