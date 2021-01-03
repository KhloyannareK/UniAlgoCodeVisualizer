#ifndef STATUSBAR_H
#define STATUSBAR_H

#include <QStatusBar>
#include <QProgressBar>

namespace ACV {

class StatusBar : public QStatusBar
{
    Q_OBJECT
public:
    StatusBar(QWidget* parent = nullptr);
    void setProgressValue(int v = 0);
private:
    void createComponents();
    void addComponents();
    QProgressBar* m_progress{nullptr};
};

}
#endif // STATUSBAR_H
