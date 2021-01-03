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
    //TODO
private:
    void setUpStatusBar();
    void setUpProgressBar();
    void setUpWidgets();

};

}

#endif // MAINWINDOW_H
