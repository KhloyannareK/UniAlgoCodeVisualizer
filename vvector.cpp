#include "vvector.h"
#include "mainwindow.h"
#include <QGraphicsRectItem>
#include <QGridLayout>

Vvector::Vvector(std::initializer_list<unsigned> list)
    : QWidget(ACV::MainWindow::getMainWindow()->centralWidget()),
      m_array{list}

{
    m_arrayItems.resize(list.size());
    initScene2DField();
    initSceneItems();
}


void Vvector::initScene2DField()
{
    m_frame = new QFrame;
    m_frame->resize(size());
    m_frame->setLayout(new QVBoxLayout);
    m_scene = new QGraphicsScene{this};
    m_view = new QGraphicsView{m_scene};
    m_view->resize(size());
    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff) ;
    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff) ;
    m_frame->layout()->addWidget(m_view);
    setLayout(new QGridLayout);
    layout()->addWidget(m_frame);
    ACV::MainWindow::getMainWindow()->centralWidget()->layout()->addWidget(this);
}
void Vvector::initSceneItems()
{
    size_t sz = m_array.size();
    if(!sz)
        return;

    // setting min, max, widthUnit, heightUnit
    m_maxElement = m_minElement = m_array[0];
    for(unsigned i = 1; i < sz; ++i) {
        if(m_array[i] > m_maxElement)
            m_maxElement = m_array[i];
        if(m_array[i] < m_minElement)
            m_minElement = m_array[i];
    }
    m_itemWidth = qreal(width())/(sz+1);
    m_itemHeightUnit = qreal(height())/(m_maxElement-m_minElement+1);

    //set Scene Rectangles
    qreal xp = 0, xw = m_itemWidth;
    qreal yh, yp, ylimit = m_itemHeightUnit*sz;
    for(size_t i = 0; i < sz; ++i)
    {
        yh = m_array[i]*m_itemHeightUnit;
        yp = ylimit - yh;
        QPen pen = QPen (Qt::black) ;
        QBrush brush = QBrush (QColor(0,200+m_array[i]%50,50+m_array[i]*10%200)) ;
        m_arrayItems[i] = m_scene->addRect(xp, yp, xw, yh, pen, brush);
        xp += xw;
    }
}

size_t Vvector::Vsize() const
{
    return m_array.size();
}

unsigned Vvector::operator[](size_t i) const
{
    if(i >= m_array.size())
        throw "out of bounds";
    return m_array[i];
}


void Vvector::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    m_frame->resize(size());
    m_view->resize(size());
    m_view->fitInView(m_scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}


Vvector::~Vvector()
{
    for(size_t i = 0; i < m_arrayItems.size(); ++i)
    {
        delete m_arrayItems[i];
        m_arrayItems[i] = nullptr;
    }
}

#include <QTime>
#include <QCoreApplication>

void delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(5);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
}

void Vvector::assign(size_t i, unsigned val)
{
    unsigned sz = m_array.size();
    if(i < sz) {
        m_array[i] = val;
        QGraphicsRectItem* rect = m_arrayItems[i];
        QBrush brush = QBrush (QColor(0,0,255));
        rect->setBrush(brush);
        delay();
        qreal xw = m_itemWidth;
        qreal yh = val*m_itemHeightUnit, yp = m_itemHeightUnit*sz - yh;
        rect->setRect(xw*i,yp,xw,yh);
        brush = QBrush (QColor(0,200+val%50,50+val*10%200));
        rect->setBrush(brush);
    }
}

