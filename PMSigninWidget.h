#ifndef PMSIGNINWIDGET_H
#define PMSIGNINWIDGET_H

#include <QtWidgets>
#include "PMUser.h"

class PMSigninWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PMSigninWidget(QWidget *parent = 0);

signals:
    void login(PMUser user);

public slots:
    void setError(QString text);
    void setDefaultSpace(QString spaceName);

protected slots:
    void emitLogin();

protected:
    QLineEdit* m_passwordLineEdit;
    QLineEdit* m_loginLineEdit;
    QLineEdit* m_spaceLineEdit;
    QLabel* m_errorLabel;
};

#endif // PMSIGNINWIDGET_H
