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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setMinimumSize(1000,800);
    setUpMenuBar();
    setUpToolBar();
    setUpStatusBar();

}

MainWindow* MainWindow::getMainWindow()
{
    if(nullptr == m_mainWindow)
        m_mainWindow = new MainWindow;
    return m_mainWindow;
}

void MainWindow::menu_handleViewAction()
{
    // TODO
}

void MainWindow::menu_handeWindowSizeAction()
{
    // TODO
}

void MainWindow::menu_handleColorAction()
{
    // TODO
}

void MainWindow::menu_handleCodeVisAcion()
{
    // TODO
}

void MainWindow::menu_handleDemoAction()
{
    // TODO
}

void MainWindow::menu_recDirAction()
{
    // TODO
}


void MainWindow::tool_recAction()
{
    // TODO
}

void MainWindow::tool_compileAction()
{
    // TODO
}

void MainWindow::setUpMenuBar()
{
    // new QMenu class may be defined and used in this class as composition
    QMenu* viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(tr("Theme"), this, &MainWindow::menu_handleViewAction); // save/for current/cancel
    viewMenu->addAction(tr("Window Size"), this, &MainWindow::menu_handeWindowSizeAction); // save/cancel
    viewMenu->addAction(tr("Color"), this, &MainWindow::menu_handleColorAction); // containers/code/tab

    QMenu* statMenu = menuBar()->addMenu(tr("&Statistics"));
    // add some action for to show vector: c1 \n matrix: c2 ... \n recordings: cn

    QMenu* exampleMenu = menuBar()->addMenu(tr("&Examples"));
    exampleMenu->addAction(tr("Code+Visualization"), this, &MainWindow::menu_handleCodeVisAcion);
    exampleMenu->addAction(tr("Demo video"), this, &MainWindow::menu_handleDemoAction);

    QMenu* settingsMenu = menuBar()->addMenu(tr("&Settings"));
    settingsMenu->addAction(tr("&Recording directory"), this, &MainWindow::menu_recDirAction);
}

void MainWindow::setUpToolBar()
{
    QToolBar* toolBar = new QToolBar("Actions", this);
    toolBar->addAction(tr("Compile"), this, &MainWindow::tool_compileAction);
    toolBar->addAction(tr("Rec"), this, &MainWindow::tool_recAction);

    addToolBar(toolBar);
}

void MainWindow::setUpProgressBar()
{
    QProgressBar* progressBar = new QProgressBar(statusBar());
    progressBar->setValue(65);
    progressBar->setTextVisible(true);
    statusBar()->addWidget(progressBar,1);
}

void MainWindow::setUpRunStopButton()
{
    QPushButton* button = new QPushButton(tr("Run/Stop"), statusBar());
    button->setCheckable(true);
    button->setBackgroundRole(QPalette::ColorRole::Highlight);
    statusBar()->addWidget(button,1);
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

void MainWindow::setUpSpeedLine()
{
    QLabel* label = new QLabel("Speed:");
    QLineEdit* speedLine = new QLineEdit(statusBar());
    speedLine->setText("x1");
    statusBar()->addWidget(label, 1);
    statusBar()->addWidget(speedLine, 1);
}

void MainWindow::setUpStatusBar()
{
    setUpSpeedLine();
    setUpProgressBar();
    setUpRunStopButton();
    setUpWidgets();
}

}
