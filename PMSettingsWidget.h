#ifndef PMSETTINGSWIDGET_H
#define PMSETTINGSWIDGET_H

#include <QtWidgets>
#include <QtNetwork>

#include "PMSettings.h"

class PMSettingsWidget : public QWidget
{
    Q_OBJECT

public:
    PMSettingsWidget(QWidget* parent = 0);

signals:
    void validated(PMSettings* settings);

public slots:
    void enableValidationButton(bool enable);
    void setProgressValue(int bytesReceived);
    void setRange(int min, int max);
    void setSettings(PMSettings *settings);
    void setErrorMessage(QString message);
    PMSettings* getSettings();

protected slots:
    void browseDefaultDir();
    void validated();


protected:
    QLineEdit *m_apiUrl;
    QLineEdit *m_defaultSpace;
    QLineEdit *m_destinationFolder;
    QLineEdit *m_resourceID;
    QPushButton *m_saveButton;
    QProgressBar *m_progressBar;
    QLabel *m_errorLabel;
};

#endif // PMSETTINGSWIDGET_H
