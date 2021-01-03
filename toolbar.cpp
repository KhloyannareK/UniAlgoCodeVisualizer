#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include "toolbar.h"

namespace ACV {

// SpeedWidget
const unsigned SpeedWidget::MAX_SPEED{32};

SpeedWidget::SpeedWidget(QWidget *parent)
    : QWidget(parent)
{
    QHBoxLayout* layout = new QHBoxLayout{this};
    setLayout(layout);
    createComponents();
    addComponents();
}

void SpeedWidget::createComponents()
{
    //label
    m_labelSpeed = new QLabel{this};
    m_labelSpeed->setText("Speed: x1");
    m_labelSpeed->setDisabled(true);
    m_labelSpeed->setFixedWidth(m_labelSpeed->width());
    //actions
    m_buttonSpeedUp = new QPushButton{tr("up"), this};
    m_buttonSpeedDown = new QPushButton{tr("down"), this};
    connect(m_buttonSpeedUp, SIGNAL(clicked()), this, SLOT(handleSpeedUpClick()));
    connect(m_buttonSpeedDown, SIGNAL(clicked()), this, SLOT(handleSpeedDownClick()));
}

void SpeedWidget::addComponents()
{
    layout()->addWidget(m_labelSpeed);
    layout()->addWidget(m_buttonSpeedUp);
    layout()->addWidget(m_buttonSpeedDown);
}

void SpeedWidget::handleSpeedUpClick()
{
    if(MAX_SPEED != m_speed) {
        m_speed *= 2;
        updateLabel();
    }
}

void SpeedWidget::handleSpeedDownClick()
{
    if(1 != m_speed) {
        m_speed /= 2;
        updateLabel();
    }
}

void SpeedWidget::updateLabel()
{
    m_labelSpeed->setText(QString("Speed: x") + (QString::number(m_speed)));
    // outer slots will be connected with this signal
    emit speedChanged(m_speed);
}

inline unsigned SpeedWidget::speed() const
{
    return m_speed;
}



// ToolBar
ToolBar::ToolBar(QWidget *parent)
    : QToolBar(parent)
{
    createTools();
    addTools();
}

void ToolBar::createTools()
{
    // may be icon + tooltips will be a good idea
    m_actCompile = new QAction(tr("Compile"), this);
    m_actPlay = new QAction(tr("Play"), this);
    m_actStop = new QAction(tr("Stop"), this);
    m_actRecord = new QAction(tr("Rec"), this);
    m_widgSpeed = new SpeedWidget(this);
}

void ToolBar::addTools()
{
    addAction(m_actCompile);
    addSeparator();
    addAction(m_actPlay);
    addAction(m_actStop);
    addSeparator();
    addAction(m_actRecord);
    addSeparator();
    addWidget(m_widgSpeed);
}

inline SpeedWidget* ToolBar::getSpeedPtr() const
{
    return m_widgSpeed;
}


}
