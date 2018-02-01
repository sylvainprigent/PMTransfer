#ifndef PMBOOKINGWIDGET_H
#define PMBOOKINGWIDGET_H

#include <QtWidgets>
#include "PMBookingModel.h"

class PMBookingWidget: public QWidget
{
    Q_OBJECT

public:
    PMBookingWidget(PMBookingModel model, QWidget *parent = 0 );

public:
    PMBookingModel getModel();

signals:
    void openBooking(PMBookingModel);

protected slots:
    void emitOpenBooking();

protected:
    PMBookingModel m_bookingModel;


};

#endif // PMBOOKINGWIDGET_H
