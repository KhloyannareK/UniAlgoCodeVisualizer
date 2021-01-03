#include "mainwindow.h"
#include <QProgressBar>
#include <QMenuBar>
#include <QToolBar>
#include <QGuiApplication>
#include <QScreen>
#include <QStatusBar>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>
#include <QLayout>
#include <QGroupBox>

namespace ACV {

MainWindow* MainWindow::m_mainWindow{nullptr};

MainWindow* MainWindow::getMainWindow()
{
    if(nullptr == m_mainWindow)
        m_mainWindow = new MainWindow;
    return m_mainWindow;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(1000,800);
    m_menuBar = new MenuBar{this};
    setMenuBar(m_menuBar);
    m_toolBar = new ToolBar{this};
    addToolBar(m_toolBar);
    m_statusBar = new StatusBar{this};
    setStatusBar(m_statusBar);
    m_statusBar->setProgressValue(65);
    m_statusBar->showMessage("Hello");

    QTextEdit* central = new QTextEdit(this);
    central->setTextBackgroundColor(QPalette::Dark);
    setCentralWidget(central);
    QHBoxLayout* layout = new QHBoxLayout(central);
    layout->setDirection(QHBoxLayout::Direction::LeftToRight);
    central->setLayout(layout);
    QTextEdit* codeText = new QTextEdit("//Code here", central);
    QTextEdit* widget = new QTextEdit("Visualizations here", central);
    layout->addWidget(codeText, 2);
    layout->addWidget(widget,4);
}



}
