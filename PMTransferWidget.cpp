#include "PMTransferWidget.h"
#include "PMSettingsAccess.h"

PMTransferWidget::PMTransferWidget() : QWidget()
{

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0,0,0,0);
    this->setLayout(layout);

    // create the widget
    m_centralWidget = new blSlidingStackedWidget(this);
    layout->addWidget(m_centralWidget);

    // login page
    m_signinWidget = new PMSigninWidget(this);
    m_centralWidget->addWidget(m_signinWidget);

    // other pages
    m_appWidget = new QWidget(this);
    QVBoxLayout *applayout = new QVBoxLayout();
    applayout->setContentsMargins(0,0,0,0);
    m_appWidget->setLayout(applayout);
    // menu
    m_menuWidget = new PMMenuWidget(this);
    applayout->addWidget(m_menuWidget, 0, Qt::AlignTop);

    // transfer page
    m_transferWidget = new PMExplorerWidget(this);
    applayout->addWidget(m_transferWidget);

    // settings page
    m_settingsWidget = new PMSettingsWidget(this);
    m_settingsWidget->setSettings(PMSettingsAccess::instance()->getSettings());
    applayout->addWidget(m_settingsWidget, 1, Qt::AlignTop);

    m_centralWidget->addWidget(m_appWidget);

    this->showLogin();

    // connections
    connect(m_menuWidget, SIGNAL(settings()), this, SLOT(showSettingsWidget()));
    connect(m_menuWidget, SIGNAL(transfert()), this, SLOT(showTransferWidget()));
    connect(m_signinWidget, SIGNAL(login(PMUser)), this, SIGNAL(login(PMUser)));
    connect(m_settingsWidget, SIGNAL(validated(PMSettings*)), this, SIGNAL(editSettings(PMSettings*)));
}

PMSigninWidget *PMTransferWidget::getSigninWidget(){
    return m_signinWidget;
}

void PMTransferWidget::setDefaultSpace(QString spaceName){
    m_signinWidget->setDefaultSpace(spaceName);
}

void PMTransferWidget::setRootPath(QString rootPath){
    m_transferWidget->setRootPath(rootPath);

}

void PMTransferWidget::showTransferWidget(){
    m_centralWidget->slideInIdx(1);
    m_transferWidget->setVisible(true);
    m_settingsWidget->setVisible(false);
}

void PMTransferWidget::showSettingsWidget(){
    m_centralWidget->slideInIdx(1);
    m_transferWidget->setVisible(false);
    m_settingsWidget->setVisible(true);
}

void PMTransferWidget::setUserStatus(int status){
    if (status >= 3){
        m_menuWidget->setVisible(true);
    }
    else{
        m_menuWidget->setVisible(false);
    }
}

void PMTransferWidget::showLogin(){
    m_centralWidget->slideInIdx(0);
}
