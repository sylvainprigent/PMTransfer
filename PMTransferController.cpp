#include "PMTransferController.h"
#include "PMUserAccess.h"


PMTransferController::PMTransferController(QObject *parent) : QObject(parent)
{

    // Widget
    m_transfertWidget = new PMTransferWidget();
    m_transfertWidget->setDefaultSpace(PMSettingsAccess::instance()->getSettings()->getDefaultSpaceName());
    QRect rec = QApplication::desktop()->availableGeometry();
    m_transfertWidget->setMinimumWidth(rec.width()/2);
    m_transfertWidget->setMinimumHeight(rec.height()/2);

    // models
    m_signinModel = new PMSigninModel(this);

    connect(m_transfertWidget, SIGNAL(login(PMUser)), m_signinModel, SLOT(signin(PMUser)));
    connect(m_transfertWidget, SIGNAL(editSettings(PMSettings*)), this, SLOT(editSettings(PMSettings*)));
    connect(m_signinModel, SIGNAL(error(QString)), m_transfertWidget->getSigninWidget(), SLOT(setError(QString)));
    connect(m_signinModel, SIGNAL(signedin(PMUser)), this, SLOT(signedin(PMUser)));
}

void PMTransferController::show(){
    m_transfertWidget->show();
}

void PMTransferController::signedin(PMUser user){
    PMUser* puser = PMUserAccess::instance()->getUser();
    puser->setLogin(user.getLogin());
    puser->setPassword(user.getPassword());
    puser->setSpace(user.getSpace());
    puser->setStatus(user.getStatus());

    qDebug() << "signed in user: ";
    puser->print();

    QString destination = PMSettingsAccess::instance()->getSettings()->getDestinationFolder();

    m_transfertWidget->setUserStatus(puser->getStatus().toInt());
    m_transfertWidget->setRootPath( destination + puser->getLogin() );
    m_transfertWidget->showTransferWidget();

}

void PMTransferController::editSettings(PMSettings* settings){
    PMSettings *settingsg = PMSettingsAccess::instance()->getSettings();
    settingsg->setApiUrl(settings->getApiUrl());
    settingsg->setDefaultSpaceName(settings->getDefaultSpaceName());
    settingsg->setDestinationFolder(settings->getDestinationFolder());
    settingsg->save();
}

