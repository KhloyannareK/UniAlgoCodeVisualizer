#include <QApplication>
#include "mainwindow.h"
#include "vvector.h"

using namespace ACV;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = MainWindow::getMainWindow();
    w->show();
    Vvector v{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,10,5,7,3,5,12,6,15,2,3,4,5,6,7,5,4};
    Vvector v2{1,2,3,4,5,4,2,3,1,10,4,12,11,2,12,6,7,8,12,10,5,7,3,5,9,6,15,2,3,4,5,6,19,3,1};
    for(size_t i = 0; i < v.Vsize(); ++i)
        for(size_t j = i+1; j<v.Vsize(); ++j) {
            if(v[i] < v[j])
            {
                unsigned val = v[j];
                v.assign(j,v[i]);
                v.assign(i,val);
            }
            if(v2[i] > v2[j])
            {
                unsigned val = v2[j];
                v2.assign(j,v2[i]);
                v2.assign(i,val);
            }
        }

    return a.exec();
}
