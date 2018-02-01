#include "PMSettingsController.h"
#include "PMSettingsAccess.h"

PMSettingsController::PMSettingsController(QObject *parent) : QObject(parent)
{

    // build the view
    m_settingsWidget = new PMSettingsWidget();
    m_settingsWidget->setSettings(PMSettingsAccess::instance()->getSettings());

    connect(m_settingsWidget, SIGNAL(validated(PMSettings*)), this, SLOT( checkSettings(PMSettings*) ));

}

QWidget *PMSettingsController::getView(){
    return m_settingsWidget;
}

void PMSettingsController::checkSettings(PMSettings* settings){

    m_settingsWidget->enableValidationButton(false);

    m_networkError = false;
    const QUrl url = QUrl(settings->getApiUrl() + "/apiping/");
    const QNetworkRequest requete(url);
    QNetworkAccessManager *m = new QNetworkAccessManager;
    QNetworkReply *r = m->get(requete);
    connect(r, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(pingError(QNetworkReply::NetworkError)));
    connect(r, SIGNAL(finished()), this, SLOT(checkSettingsResponse()));
    connect(r, SIGNAL(downloadProgress(qint64, qint64)), this, SLOT(pingProgress(qint64, qint64) ));

}

void PMSettingsController::pingError(QNetworkReply::NetworkError){
    m_networkError = true;
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());
    m_settingsWidget->setErrorMessage(tr("Error cannot contact the Platform-Manager API. Please verify the URL <br /><br /> Error code : <br /><em>") + QString(r->errorString()) + "</em>");
    m_settingsWidget->enableValidationButton(true);
}

void PMSettingsController::checkSettingsResponse() {
    if(!m_networkError) {

        QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());
        QString response = QString(r->readAll());
        if (response =="true"){
            emit settings(m_settingsWidget->getSettings());
        }
    }
}

void PMSettingsController::pingProgress(qint64 bytesReceived, qint64 bytesTotal){

    if (bytesTotal != -1){
        m_settingsWidget->setRange(0, bytesTotal);
        m_settingsWidget->setProgressValue(bytesReceived);
    }
}



