#include "PMMenuWidget.h"

PMMenuWidget::PMMenuWidget(QWidget *parent) : QWidget(parent)
{

    QVBoxLayout *layout = new QVBoxLayout();
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);
    QToolBar *toolBAr = new QToolBar();
    layout->addWidget(toolBAr);
    m_transfertAction = new QAction(tr("Transfert"), this);
    m_settingsAction = new QAction(tr("Settings"), this);
    QList<QAction*> list;
    list.append(m_transfertAction);
    list.append(m_settingsAction);
    toolBAr->addActions(list);

    connect(m_transfertAction, SIGNAL(triggered(bool)), this, SLOT(askTransfert(bool)));
    connect(m_settingsAction, SIGNAL(triggered(bool)), this, SLOT(askSettings(bool)));

}

void PMMenuWidget::askTransfert(bool){
    emit transfert();
}

void PMMenuWidget::quit(bool){
    qApp->quit();
}

void PMMenuWidget::askSettings(bool){
    emit settings();
}
