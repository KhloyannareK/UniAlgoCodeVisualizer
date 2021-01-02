#include <QApplication>
#include "mainwindow.h"

using namespace ACV;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = MainWindow::getMainWindow();
    w->show();

    return a.exec();
}
