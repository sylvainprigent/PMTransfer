#include "PMInitController.h"
#include "PMSettingsAccess.h"
#include "PMSettingsController.h"
#include "PMTransferController.h"

PMInitController::PMInitController(QObject *parent)
    : QObject(parent)
{

    PMSettings* settings = PMSettingsAccess::instance()->getSettings();

    // if the settings are not set: show the initialisation page
    if (settings->getApiUrl() == ""){
        this->showSettingsWidget();
    }
    // if the settings are set: show the transfert widget
    else{
        this->showTransferWidget(settings);
    }
}

PMInitController::~PMInitController()
{

}

void PMInitController::showSettingsWidget(){

    m_settingsController = new PMSettingsController(this);
    connect(m_settingsController, SIGNAL(settings(PMSettings*)), this, SLOT(showTransferWidgetFromSettings(PMSettings*)));
    m_settingsController->getView()->show();
}

void PMInitController::showTransferWidgetFromSettings(PMSettings* settings){

    PMSettings* settingssingleton = PMSettingsAccess::instance()->getSettings();
    settingssingleton->setApiUrl(settings->getApiUrl());
    settingssingleton->setDefaultSpaceName(settings->getDefaultSpaceName());
    settingssingleton->setDestinationFolder(settings->getDestinationFolder());
    settingssingleton->setResourceID(settings->getResourceID());
    settingssingleton->save();

    m_settingsController->getView()->hide();
    this->showTransferWidget(settings);
}

void PMInitController::showTransferWidget(PMSettings* settings){

    PMTransferController *transfertController = new PMTransferController(this);
    transfertController->show();

}
