#ifndef PMSETTINGSCONTROLLER_H
#define PMSETTINGSCONTROLLER_H

#include <QObject>
#include "PMSettingsWidget.h"

class PMSettingsController : public QObject
{
    Q_OBJECT
public:
    explicit PMSettingsController(QObject *parent = 0);

signals:
    void settings(PMSettings*);

public slots:
    QWidget *getView();

protected slots:
    void checkSettingsResponse();
    void pingError(QNetworkReply::NetworkError);
    void checkSettings(PMSettings* settings);
    void pingProgress(qint64 bytesReceived, qint64 bytesTotal);

protected:
    PMSettingsWidget *m_settingsWidget;
    bool m_networkError;
};

#endif // PMSETTINGSCONTROLLER_H
