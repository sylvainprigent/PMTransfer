#ifndef PMUSERSACCESS_H
#define PMUSERSACCESS_H

#include <QtWidgets>
#include "PMSingleton.h"
#include "PMUser.h"

class PMUserAccess : public PMSingleton<PMUserAccess>{

    friend class PMSingleton<PMUserAccess>;

public:
    PMUserAccess();
    PMUserAccess(QString fileUrl);
    ~PMUserAccess();

public:
    PMUser* getUser();


protected:
    PMUser* m_user;

};

#endif // PMUSERSACCESS_H
