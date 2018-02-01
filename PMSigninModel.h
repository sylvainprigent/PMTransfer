#ifndef PMSIGNINMODEL_H
#define PMSIGNINMODEL_H

#include <QObject>
#include <QtNetwork>
#include "PMUser.h"
#include "PMSettingsAccess.h"

class PMSigninModel : public QObject
{
    Q_OBJECT
public:
    explicit PMSigninModel(QObject *parent = 0);

signals:
    void error(QString);
    void signedin(PMUser);

public slots:
    void signin(PMUser user);

protected slots:
    void checkResponse();
    void networkError(QNetworkReply::NetworkError);

protected:
    bool m_networkError;
    PMUser m_user;
};

#endif // PMSIGNINMODEL_H
