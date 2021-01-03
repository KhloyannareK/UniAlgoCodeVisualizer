#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>
class QLabel;
class QPushButton;
namespace ACV {

class SpeedWidget : public QWidget
{
    Q_OBJECT
public:
    SpeedWidget(QWidget* parent = nullptr);
    unsigned speed() const;
signals:
    void speedChanged(int speed);
private slots:
    void handleSpeedUpClick();
    void handleSpeedDownClick();
private:
    void createComponents();
    void addComponents();
    void updateLabel();
    QLabel* m_labelSpeed{nullptr};
    QPushButton* m_buttonSpeedUp{nullptr};
    QPushButton* m_buttonSpeedDown{nullptr};
    unsigned m_speed{1};

    static const unsigned MAX_SPEED;
};

class ToolBar : public QToolBar
{
    Q_OBJECT
public:
    ToolBar(QWidget* parent = nullptr);
    SpeedWidget* getSpeedPtr() const;
private:
    void createTools();
    void addTools();
    // someHow should be connected to the outer slots
    QAction* m_actCompile{nullptr};
    QAction* m_actPlay{nullptr};
    QAction* m_actStop{nullptr};
    QAction* m_actRecord{nullptr};
    SpeedWidget* m_widgSpeed{nullptr};

};

}
#endif // TOOLBAR_H
