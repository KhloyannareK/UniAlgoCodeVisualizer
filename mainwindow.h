#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menubar.h"
#include "toolbar.h"
#include "statusbar.h"


/// Algo Code Visualizer
namespace ACV {

class MainWindow : public QMainWindow
{
    Q_OBJECT
    // Singletone provided
    explicit MainWindow(QWidget* parent = nullptr);
    static MainWindow* m_mainWindow;
public:
    static MainWindow* getMainWindow();

public slots:
    //TODO
private:
    void setUpWidgets();

    // holding to avoid many get/set calls and dynamic casting
    MenuBar* m_menuBar{nullptr};
    ToolBar* m_toolBar{nullptr};
    StatusBar* m_statusBar{nullptr};
};

}

#endif // MAINWINDOW_H
