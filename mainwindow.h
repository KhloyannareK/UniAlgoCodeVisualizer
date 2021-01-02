#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void menu_handleViewAction();
    void menu_handeWindowSizeAction();
    void menu_handleColorAction();
    void menu_handleCodeVisAcion();
    void menu_handleDemoAction();
    void menu_recDirAction();

    void tool_recAction();
    void tool_compileAction();
private:
    void setUpMenuBar();
    void setUpToolBar();
    void setUpStatusBar();
    void setUpSpeedLine();
    void setUpProgressBar();
    void setUpRunStopButton();
    void setUpWidgets();

};

}

#endif // MAINWINDOW_H
