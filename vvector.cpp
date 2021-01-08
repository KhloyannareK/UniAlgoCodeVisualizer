#include "vvector.h"
#include "mainwindow.h"
#include "Utils.cpp"
#include <QGraphicsRectItem>
#include <QGridLayout>


#include <QTime>
#include <QCoreApplication>
void delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(8);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
}


void vectorTextV::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    m_frame->resize(size());
    m_view->resize(size());
    m_view->fitInView(m_scene->itemsBoundingRect(), Qt::KeepAspectRatio);
    // TODO: set m_elemWidth, m_heightUnit
}

vectorTextV::vectorTextV(std::initializer_list<valueType> list)
    : QWidget(ACV::MainWindow::getMainWindow()->centralWidget()), m_array{list}
{
    initScene2DField();
    calculateParameters();
    cloneArrayToItemsArray();
}

vectorTextV::~vectorTextV()
{
    indexType sz = Vsize();
    for(indexType i = 0; i < sz; ++i)
    {
        delete m_arrayItems[i];
        delete m_arrayTexts[i];
    }
    delete m_view;
    delete m_scene;
    delete m_frame;
}

void vectorTextV::initScene2DField()
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

bool vectorTextV::resetElemsIfoverLoaded()
{
    if( (width() / m_elemWidth * m_array.size()) >= m_maxLoadFactor )
    {
        calculateParameters();
        cloneArrayToItemsArray();
        return true;
    }
    return false;
}

void vectorTextV::calculateParameters()
{
    m_elemWidth = 2.5*(width() * m_minLoadFactor) / (m_array.size() + 1);
    m_elemHeightUnit = height() / 2.0;
    m_minY = m_elemHeightUnit / 2.0;
    m_textScale = 0.16 - 0.001*m_array.size();
    if(m_textScale < 0.05)
        m_textScale = 0.05;
}

void vectorTextV::cloneArrayToItemsArray()
{
    size_t sz = m_arrayItems.size();
    if(sz != m_array.size()) {
        for(size_t i = 0; i < sz; ++i) {
            delete m_arrayItems[i];
            delete m_arrayTexts[i];
        }
        m_arrayItems.clear();
        m_arrayTexts.clear();
    }

    sz = m_array.size();
    m_arrayItems.resize(sz);
    m_arrayTexts.resize(sz);

    qreal xp = m_minX, yp = m_minY, yh = m_elemHeightUnit;
    for(indexType i = 0; i < sz; ++i)
    {
        m_arrayItems[i] = m_scene->addRect(xp, yp, m_elemWidth, yh, m_pen, calculateColor(m_array[i]));
        QGraphicsTextItem* text = m_scene->addText( ACV::toQString(m_array[i]) );
        m_arrayTexts[i] = text;
        text->setDefaultTextColor(calculateTextColor(m_array[i]));
        text->setParentItem(m_arrayItems[i]);
        text->setScale(m_textScale);
        text->adjustSize();
        text->setPos({xp,yp});
        xp += m_elemWidth;
    }
}

QBrush vectorTextV::calculateColor(vectorTextV::valueType value) const
{
    int r = value*23%256;//value & 0x30; // 1100 0000
    int g = value*29%256;//value & 0xc0; // 0011 0000
    int b = value*31%256;//value & 0x0f; // 0000 1111
    return QBrush(QColor(r,g,b));
}
QColor vectorTextV::calculateTextColor(vectorTextV::valueType value) const
{
    int r = (value*23%256) ^ 255; //value & 0x30; // 1100 0000
    int g = (value*29%256) ^ 255; //value & 0xc0; // 0011 0000
    int b = (value*31%256) ^ 255; //value & 0x0f; // 0000 1111
    return QColor(r,g,b);
}

void vectorTextV::assign(vectorTextV::indexType pos, vectorTextV::valueType value)
{
    indexType sz = m_array.size();
    if(pos < sz) {
        m_array[pos] = value;
        QGraphicsRectItem* rect = m_arrayItems[pos];
        rect->setBrush(m_modifyNotifColor);
        QGraphicsTextItem* text = m_arrayTexts[pos];
        text->setDefaultTextColor(m_modifyNotifColor);
        delay();
        rect->setBrush(calculateColor(value));
        text->setDefaultTextColor(calculateTextColor(value));
        text->setPlainText( ACV::toQString(value) );
        if(Vsize() < 20)
            text->adjustSize();
    }
}

vectorTextV::valueType vectorTextV::operator[](vectorTextV::indexType pos) const
{
    return m_array[pos];
}

vectorTextV::indexType vectorTextV::Vsize() const
{
    return m_array.size();
}


/*void Vvector::push_back(unsigned val)
{
    m_array.push_back(val);
    m_arrayItems.push_back(new QGraphicsRectItem);
    if(m_minElement > val)
        m_minElement = val;
    else if(m_maxElement < val)
        m_maxElement = val;

    unsigned sz = m_array.size();
    m_itemWidth = qreal(width())/(sz+1);
    m_itemHeightUnit = qreal(height())/(m_maxElement-m_minElement+1);
    for(size_t i = 0; i < sz-1; ++i)
        m_scene->removeItem(m_arrayItems[i]);
    initSceneItems();
    m_frame->resize(size());
    m_view->resize(size());
    m_view->fitInView(m_scene->itemsBoundingRect(), Qt::KeepAspectRatio);
}*/




