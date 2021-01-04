#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

namespace ACV {

class MenuBar : public QMenuBar
{
    Q_OBJECT
public:
    MenuBar(QWidget* parent = nullptr);
private:
    void createAndAddMenusAndActions();

    QMenu* m_menuView{nullptr};
    QMenu* m_menuExamples{nullptr};
    QMenu* m_menuSettings{nullptr};

    // connection will be set from mainWindow or may be a implementer class here
    // which will have methods to handle actions, therefore getters may be needed
    QAction* m_actTheme{nullptr};
    QAction* m_actWindowSize{nullptr};
    QAction* m_actColor{nullptr};

    QAction* m_actStatistics{nullptr};

    QAction* m_actCodeExamples{nullptr};
    QAction* m_actDemoVideo{nullptr};

    QAction* m_actRecordingDirectory{nullptr};
};

}
#endif // MENUBAR_H
