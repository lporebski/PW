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
    void closeEvent(QCloseEvent *e);

    void saveFile();

    void on_actionCut_triggered();

    void on_actionOpen_triggered();

    void on_actionNew_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionSave_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionClose_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionAboutQt_triggered();

    void on_actionFont_triggered();

private:
    Ui::MainWindow *ui;
    MainWindow *sWindow;
    bool m_modified=true;

};
#endif // MAINWINDOW_H
