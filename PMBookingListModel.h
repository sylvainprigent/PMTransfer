#ifndef PMBOOKINGLISTMODEL_H
#define PMBOOKINGLISTMODEL_H

#include <QObject>
#include <QtNetwork>
#include "PMBookingModel.h"

class PMBookingListModel : public QObject
{
    Q_OBJECT
public:
    explicit PMBookingListModel(QObject *parent = 0);

signals:
    void error(QString);
    void initdone();

public slots:
    void init();
    void uploadReservations();
    int count();
    PMBookingModel getBooking(int i);

protected slots:
    void checkResponse();
    void networkError(QNetworkReply::NetworkError);

private:
   QList<PMBookingModel> m_booking;
   bool m_networkError;
};

#endif // PMBOOKINGLISTMODEL_H
