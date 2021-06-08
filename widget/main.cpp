#include "manualwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ManualWidget mw;
    mw.show();
    return a.exec();
}
