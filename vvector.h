#ifndef VVECTOR_H
#define VVECTOR_H

#include <QWidget>
#include <vector>
#include <QGraphicsView>
#include <QString>
#include <QFrame>


// histogram view
class vectorTextV : public QWidget
{
    Q_OBJECT
public:
    using valueType = unsigned;
    using indexType = size_t;

    vectorTextV(std::initializer_list<valueType> list);
    //vectorTextV(indexType size, valueType value = 0);
    //vectorTextV();
    ~vectorTextV();

    //void pop_back();
    //void push_back(valueType value);
    //void insert(indexType pos, valueType value);
    //void insert(indexType pos, indexType count, const valueType& value);
    //void erase(indexType pos);
    //void erase(indexType pos, indexType last);
    void assign(indexType pos, valueType value);
    valueType operator[](indexType pos) const;
    indexType Vsize() const;

    void resizeEvent(QResizeEvent *event) override;
protected:
    virtual QColor calculateTextColor(valueType value) const;
    virtual QBrush calculateColor(valueType value) const;
    virtual void cloneArrayToItemsArray();
    virtual void calculateParameters();
    virtual void initScene2DField();
    virtual bool resetElemsIfoverLoaded();
    std::vector<unsigned> m_array;
    std::vector<QGraphicsRectItem*> m_arrayItems;
    std::vector<QGraphicsTextItem*> m_arrayTexts;
    QGraphicsView* m_view;
    QGraphicsScene* m_scene;
    QFrame* m_frame;
    QColor m_modifyNotifColor{255,255,0};
    QPen m_pen{(Qt::black) };
    qreal m_minLoadFactor{0.8};
    qreal m_maxLoadFactor{0.95};
    qreal m_minX{0};
    qreal m_minY{0};
    qreal m_elemWidth;
    qreal m_elemHeightUnit;
    qreal m_textScale{0.15};

};

// value as text on all Elems
class vectorBottleV : public vectorTextV
{
public:
    vectorBottleV(std::initializer_list<unsigned> list);
    vectorBottleV(indexType size, valueType value = 0);
    vectorBottleV();
};

// value water in the bottel + text on the elems
class vectorHistogramV : public vectorTextV
{
public:
    vectorHistogramV(std::initializer_list<unsigned> list);
    vectorHistogramV(indexType size, valueType value = 0);
    vectorHistogramV();
};


#endif // VVECTOR_H
