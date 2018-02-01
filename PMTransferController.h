#ifndef PMTRANSFERCONTROLLER_H
#define PMTRANSFERCONTROLLER_H

#include <QObject>
#include "PMTransferWidget.h"
#include "PMSigninModel.h"

class PMTransferController : public QObject
{
    Q_OBJECT
public:
    explicit PMTransferController(QObject *parent = 0);

signals:

public slots:
    void show();
    void signedin(PMUser user);
    void editSettings(PMSettings* settings);

protected:
    // View
    PMTransferWidget *m_transfertWidget;

    // models
    PMSigninModel *m_signinModel;

};

#endif // PMTRANSFERCONTROLLER_H
