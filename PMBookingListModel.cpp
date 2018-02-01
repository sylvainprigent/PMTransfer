#include "PMBookingListModel.h"
#include "PMSettingsAccess.h"
#include "PMUserAccess.h"

PMBookingListModel::PMBookingListModel(QObject *parent) : QObject(parent)
{
}

int PMBookingListModel::count(){
    return m_booking.count();
}

PMBookingModel PMBookingListModel::getBooking(int i){
    return m_booking[i];
}

void PMBookingListModel::init(){
    uploadReservations();
}

void PMBookingListModel::uploadReservations(){

    PMSettings* settings = PMSettingsAccess::instance()->getSettings();
    PMUser* user = PMUserAccess::instance()->getUser();
    user->print();


    QUrl bookingapiUrl = QUrl( settings->getApiUrl() + "/bookinggetreservations/" + QString::number(settings->getResourceID()) + "/" + user->getLogin() );

    m_networkError = false;
    const QUrl url = QUrl(bookingapiUrl);
    const QNetworkRequest requete(url);
    QNetworkAccessManager *m = new QNetworkAccessManager;

    QNetworkReply *r = m->get(requete);
    connect(r, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(networkError(QNetworkReply::NetworkError)));
    connect(r, SIGNAL(finished()), this, SLOT(checkResponse()));
}

void PMBookingListModel::networkError(QNetworkReply::NetworkError){

    m_networkError = true;
    QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());
    emit error(tr("Error code : <br /><em>") + QString(r->errorString()) + "</em>");

}

void PMBookingListModel::checkResponse() {

    if(!m_networkError) {

        QNetworkReply *r = qobject_cast<QNetworkReply*>(sender());
        QString response = QString(r->readAll());

        QJsonDocument jsonResponse = QJsonDocument::fromJson(response.toUtf8());

        QString rootPath = PMSettingsAccess::instance()->getSettings()->getDestinationFolder();

        QJsonArray jsonArray = jsonResponse.array();

        foreach (const QJsonValue & value, jsonArray) {
            QJsonObject obj = value.toObject();
            PMBookingModel bookingmodel;
            bookingmodel.setBookingID(obj["id"].toInt());
            bookingmodel.setDirName(obj["datetimebegin"].toString());
            bookingmodel.setRootPath(rootPath);
            bookingmodel.setDate(obj["date"].toString());
            bookingmodel.setHourStart(obj["hourstart"].toString());
            bookingmodel.setHourEnd(obj["hourend"].toString());
            bookingmodel.checkDir();

            m_booking.append( bookingmodel );
            qDebug() << "reservation : " << m_booking.count() ;
        }
        emit initdone();
    }
}
