#include "PMSettingsAccess.h"

PMSettingsAccess::PMSettingsAccess()
{
    m_settings = new PMSettings();
}

PMSettingsAccess::PMSettingsAccess(QString fileUrl){
    m_settings = new PMSettings(fileUrl);
}

PMSettingsAccess::~PMSettingsAccess(){
    delete m_settings;
}

PMSettings* PMSettingsAccess::getSettings(){
    return m_settings;
}


