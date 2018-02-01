#include "PMSigninModel.h"

PMSigninModel::PMSigninModel(QObject *parent) : QObject(parent)
{

}

void PMSigninModel::signin(PMUser user){


    m_user = user;

    //qDebug() << "MSigninModel::signin begining";
    PMSettings *settings = PMSettingsAccess::instance()->getSettings();

    m_networkError = false;
    //qDebug() << "MSigninModel::signin url " + settings->getApiUrl() + "/apilogin";
    const QUrl url = QUrl(settings->getApiUrl() + "/apilogin");
    const QNetworkRequest requete(url);
    QNetworkAccessManager *m = new QNetworkAccessManager;

    //qDebug() << "MSigninModel::signin run post";
    QString postData = "login="+user.getLogin()+"&password="+user.getPassword()+"&space="+user.getSpace();
    //qDebug() << "MSigninModel::signin request = " + postData;
    QNetworkReply *r = m->post(requete, postData.toUtf8());
    //qDebug() << "MSigninModel::signin connect";
    connect(r, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(networkError(QNetworkReply::NetworkError)));
    connect(r, SIGNAL(finished()), this, SLOT(checkResponse()));
    //qDebug() << "MSigninModel::signin done";
}

void PMSigninModel::networkError(QNetworkReply::NetworkError){
    //qDebug() << "MSigninModel::networkError begin";
    m_networkError = true;
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());
    emit error(tr("Error code : <br /><em>") + QString(r->errorString()) + "</em>");
    //qDebug() << "MSigninModel::networkError done";
}

void PMSigninModel::checkResponse() {
    //qDebug() << "MSigninModel::checkResponse begin";

    if(!m_networkError) {

        QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());
        QString response = QString(r->readAll());
        qDebug() << "login response = " << response;

        QJsonDocument jsonResponse = QJsonDocument::fromJson(response.toUtf8());
        QJsonObject jsonObject = jsonResponse.object();
        qDebug() << "status = " + jsonObject["status"].toString();
        if ( jsonObject["status"]  == "allowed"){
            qDebug() << "user space role = " + jsonObject["space_role"].toString();
            m_user.setStatus(jsonObject["space_role"].toString());
            emit signedin(m_user);
        }
        else{
            qDebug() << "error = " + jsonObject["error"].toString();
            emit error(jsonObject["error"].toString());
        }
    }
    //qDebug() << "MSigninModel::checkResponse done";
}
