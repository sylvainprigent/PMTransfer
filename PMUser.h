#ifndef PMUSER_H
#define PMUSER_H

#include <QtWidgets>

class PMUser
{
public:
    PMUser();

public:
    QString getLogin();
    QString getPassword();
    QString getStatus();
    QString getSpace();

    void setLogin(QString login);
    void setPassword(QString password);
    void setStatus(QString status);
    void setSpace(QString space);

    void print();

protected:
    QString m_login;
    QString m_password;
    QString m_status;
    QString m_space;

};

#endif // PMUSER_H
