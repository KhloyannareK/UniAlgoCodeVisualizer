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
#include "menubar.h"
#include "toolbar.h"

namespace ACV {

MainWindow* MainWindow::m_mainWindow{nullptr};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(1000,800);
    setMenuBar(new MenuBar(this));
    addToolBar(new ToolBar{this});
    setUpStatusBar();
}

MainWindow* MainWindow::getMainWindow()
{
    if(nullptr == m_mainWindow)
        m_mainWindow = new MainWindow;
    return m_mainWindow;
}

void MainWindow::setUpProgressBar()
{
    QProgressBar* progressBar = new QProgressBar(statusBar());
    progressBar->setValue(65);
    progressBar->setTextVisible(true);
    statusBar()->addWidget(progressBar,1);
}

void MainWindow::setUpWidgets()
{
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

void MainWindow::setUpStatusBar()
{
    setUpProgressBar();
    setUpWidgets();
}

}
