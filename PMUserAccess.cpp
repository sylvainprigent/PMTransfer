#include "PMUserAccess.h"

PMUserAccess::PMUserAccess()
{
    m_user = new PMUser();
}

PMUserAccess::~PMUserAccess(){
    delete m_user;
}

PMUser* PMUserAccess::getUser(){
    return m_user;
}
