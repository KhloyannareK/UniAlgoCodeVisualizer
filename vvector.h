#ifndef VVECTOR_H
#define VVECTOR_H

#include <QWidget>
#include <vector>
#include <QGraphicsView>
#include <QString>
#include <QFrame>

class Vvector : public QWidget
{
    Q_OBJECT
public:
    Vvector(std::initializer_list<unsigned> list);
    ~Vvector();
    void assign(size_t i, unsigned val);
    void resizeEvent(QResizeEvent *event) override;
    size_t Vsize() const;
    unsigned operator[](size_t i)const;
private:
    void initScene2DField();
    void initSceneItems();

    QGraphicsView* m_view;
    QGraphicsScene* m_scene;
    QFrame* m_frame;
    std::vector<unsigned> m_array;
    std::vector<QGraphicsRectItem*> m_arrayItems;
    unsigned m_maxElement{0};
    unsigned m_minElement{0};
    qreal m_itemWidth{0};
    qreal m_itemHeightUnit{0};
};

#endif // VVECTOR_H
