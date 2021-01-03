#include "menubar.h"

namespace ACV {
MenuBar::MenuBar(QWidget *parent)
    : QMenuBar(parent)
{
    createMenusAndActions();
}


void MenuBar::createMenusAndActions()
{
    // menu: View
    m_menuView = new QMenu(tr("&View"), this);
    m_actTheme      = m_menuView->addAction("Theme");
    m_actWindowSize = m_menuView->addAction("Window size");
    m_actColor      = m_menuView->addAction("Color");
    addMenu(m_menuView);

    // action: Statistics
    m_actStatistics = new QAction(tr("Statistics"), this);
    addAction(m_actStatistics);

    // menu: Examples
    m_menuExamples = new QMenu(tr("&Examples"), this);
    m_actCodeExamples = m_menuExamples->addAction(tr("Code+Examples"));
    m_actDemoVideo = m_menuExamples->addAction(tr("Demo Video"));
    addMenu(m_menuExamples);

    // menu: Settings
    m_menuSettings = new QMenu(tr("&Settings"), this);
    m_actRecordingDirectory = m_menuSettings->addAction(tr("Recording Directory"));
    addMenu(m_menuSettings);
}

}
