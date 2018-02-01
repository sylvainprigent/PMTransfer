#ifndef PMMenuWidget_H
#define PMMenuWidget_H

#include <QtWidgets>

class PMMenuWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PMMenuWidget(QWidget *parent = 0);

signals:
    void settings();
    void transfert();

protected slots:
    void quit(bool);
    void askSettings(bool);
    void askTransfert(bool);

protected:
    QMenu *m_fileMenu;
    QMenu *m_adminMenu;
    QAction *m_exitAction;
    QAction *m_settingsAction;
    QAction *m_transfertAction;
};

#endif // PMMenuWidget_H
