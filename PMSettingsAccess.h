#ifndef PMSETTINGSACCESS_H
#define PMSETTINGSACCESS_H

#include <QtWidgets>
#include "PMSingleton.h"
#include "PMSettings.h"

class PMSettingsAccess : public PMSingleton<PMSettingsAccess>{

    friend class PMSingleton<PMSettingsAccess>;

public:
    PMSettingsAccess();
    PMSettingsAccess(QString fileUrl);
    ~PMSettingsAccess();

public:
    PMSettings* getSettings();


protected:
    PMSettings* m_settings;

};

#endif // PMSETTINGSACCESS_H
