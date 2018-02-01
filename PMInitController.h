#ifndef PMTRANSFERT_H
#define PMTRANSFERT_H

#include <QWidget>
#include "PMSettingsController.h"

class PMInitController : public QObject
{
    Q_OBJECT

public:
    PMInitController(QObject *parent = 0);
    ~PMInitController();

protected slots:
    void showTransferWidgetFromSettings(PMSettings* settings);

protected:
    void showSettingsWidget();
    void showTransferWidget(PMSettings *settings);

protected:
    PMSettingsController *m_settingsController;
};

#endif // PMTRANSFERT_H
