#include <QApplication>
#include "mainwindow.h"
#include "vvector.h"

using namespace ACV;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = MainWindow::getMainWindow();
    w->show();
    vectorTextV v0{1,22222};
    vectorTextV v{1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,22222,17,18,19,10,5,7,3,5,12,6,15,2,3,4,5,6,7,5,4};
    vectorTextV v2{1,2,3,4,5,4,2,3,1,10,4,12,11,2,12,6,7,22222,8,12,10,5,7,3,5,9,6,15,2,3,4,5,6,19,3,1};
    vectorTextV v3{1,2,3,4,5,4,2,3,1,10,4,12,11,2,12,6,7,22222,8,12,10,5,7,3,5,9,6,15,2,3,4,5,6,19,3,1,
                  222222,1,2,3,4,5,4,2,3,1,10,4,12,11,2,12,6,7,22222,8,12,10,5,7,3,5,9,6,15,2,3,4,5,6,19,3,1};
    vectorTextV v4{1,2,3,4,5,6,7,8,9,10,222,2222,22222};
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
    for(size_t i = 0; i < v4.Vsize(); ++i)
        for(size_t j = i+1; j<v4.Vsize(); ++j) {
            if(v4[i] < v4[j])
            {
                unsigned val = v4[j];
                v4.assign(j,v4[i]);
                v4.assign(i,val);
            }
        }
    for(size_t i = 0; i < v3.Vsize(); ++i)
        for(size_t j = i+1; j<v3.Vsize(); ++j) {
            if(v3[i] < v3[j])
            {
                unsigned val = v3[j];
                v3.assign(j,v3[i]);
                v3.assign(i,val);
            }
        }
    for(size_t i = 0; i < v0.Vsize(); ++i)
        for(size_t j = i+1; j<v0.Vsize(); ++j) {
            if(v0[i] < v0[j])
            {
                unsigned val = v0[j];
                v0.assign(j,v0[i]);
                v0.assign(i,val);
            }
        }



    return a.exec();
}
