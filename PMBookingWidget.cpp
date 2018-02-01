#include "PMBookingWidget.h"

PMBookingWidget::PMBookingWidget(PMBookingModel model, QWidget *parent) : QWidget(parent)
{

    m_bookingModel = model;

    QVBoxLayout *layout = new QVBoxLayout;

    QPushButton *button = new QPushButton(this);
    QString txt = "Reservation of " + model.getDate() + "\n";
    txt += "from "+ model.getHourStart() + " to " + model.getHourEnd() + "\n ";
    if ( model.getFileNumber() > 0 ){
        txt += QString::number(model.getFileNumber()) + " fichiers";
        button->setObjectName("btnBookingData");
    }
    else{
        button->setObjectName("btnBookingNoData");
    }
    button->setText(txt);

    layout->addWidget(button);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(2);
    this->setLayout(layout);
    this->setContentsMargins(0,0,0,0);

    connect(button, SIGNAL(released()), this, SLOT(emitOpenBooking()));
}

void PMBookingWidget::emitOpenBooking(){
    emit openBooking(m_bookingModel);
}

PMBookingModel PMBookingWidget::getModel(){
    return m_bookingModel;
}

