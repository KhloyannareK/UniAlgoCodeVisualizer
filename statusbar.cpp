#include "statusbar.h"


namespace ACV {

StatusBar::StatusBar(QWidget *parent)
    : QStatusBar(parent)
{
    hide();
    createComponents();
    addComponents();

    connect(this, SIGNAL(messageChanged(const QString&)), this, SLOT(show()));
}

void StatusBar::createComponents()
{
    // progressBar
    m_progress = new QProgressBar{this};
    m_progress->setRange(0,100);
    m_progress->setTextVisible(true);
}

void StatusBar::addComponents()
{
    //progressBar
    addPermanentWidget(m_progress,0);
}

void StatusBar::setProgressValue(int v)
{
    m_progress->setValue(v);
}


}
