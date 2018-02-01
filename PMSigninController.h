#ifndef PMSIGNINCONTROLLER_H
#define PMSIGNINCONTROLLER_H

#include <QObject>
#include "PMSigninWidget.h"

class PMSigninController : public QObject
{
    Q_OBJECT
public:
    explicit PMSigninController(QObject *parent = 0);

signals:

public slots:

protected:
    PMSigninWidget *m_signinWidget;
};

#endif // PMSIGNINCONTROLLER_H
