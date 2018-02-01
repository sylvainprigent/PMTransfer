#ifndef PMTRANSFERTWIDGET_H
#define PMTRANSFERTWIDGET_H

#include <QWidget>
#include "blSlidingStackedWidget.h"
#include "PMSigninWidget.h"
#include "PMMenuWidget.h"
#include "PMSettingsWidget.h"
#include "PMExplorerWidget.h"

class PMTransferWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PMTransferWidget();

signals:
    void login(PMUser);
    void editSettings(PMSettings*);

public slots:
    void setDefaultSpace(QString spaceName);
    PMSigninWidget* getSigninWidget();
    void setRootPath(QString rootPath);
    void showTransferWidget();
    void setUserStatus(int status);

protected slots:
    void showSettingsWidget();
    void showLogin();

protected:
    blSlidingStackedWidget *m_centralWidget;
    PMSigninWidget *m_signinWidget;
    PMMenuWidget *m_menuWidget;
    PMExplorerWidget *m_transferWidget;
    PMSettingsWidget *m_settingsWidget;
    QWidget *m_appWidget;
};

#endif // PMTRANSFERTWIDGET_H
