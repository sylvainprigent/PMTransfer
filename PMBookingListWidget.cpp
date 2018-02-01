#include "PMBookingListWidget.h"
#include "PMBookingWidget.h"

PMBookingListWidget::PMBookingListWidget(QWidget *parent) : QWidget(parent)
{

    m_layout = new QVBoxLayout;
    QLabel* label = new QLabel(tr("Reservations"), this);
    m_layout->addWidget(label);

    this->setLayout(m_layout);

}

PMBookingListWidget::PMBookingListWidget(PMBookingListModel *bookingList, QWidget *parent) : QWidget(parent)
{

    m_layout = new QVBoxLayout;
    QLabel* label = new QLabel(tr("Reservations"), this);
    m_layout->addWidget(label);
    this->setLayout(m_layout);
    m_model = bookingList;
    connect(m_model, SIGNAL( initdone() ), this, SLOT( setBookingList() ) );

}

void PMBookingListWidget::setBookingList(){
    setBookingList(m_model);
}

void PMBookingListWidget::setBookingList(PMBookingListModel *bookingList)
{

    qDebug() << "booking list count = " << bookingList->count();
    for (int i = 0 ; i < bookingList->count() ; i++){

        PMBookingWidget *widget = new PMBookingWidget(bookingList->getBooking(i));
        connect(widget, SIGNAL(openBooking(PMBookingModel)), this, SIGNAL(openBooking(PMBookingModel)));
        connect(widget, SIGNAL(openBooking(PMBookingModel)), this, SLOT(openBookingChangeView(PMBookingModel)));

        m_layout->addWidget(widget, 0, Qt::AlignTop);

    }
    m_layout->addWidget(new QWidget, 1, Qt::AlignTop);
}

void PMBookingListWidget::openBookingChangeView(PMBookingModel model){

    for (int i = 0; i < m_layout->count(); ++i){
        QWidget *widget = m_layout->itemAt(i)->widget();
        if (widget != NULL)
        {
            PMBookingWidget *w = dynamic_cast<PMBookingWidget*>(widget);
            if (w){
                if ( w->getModel().getDirName() ==  model.getDirName() ){
                    widget->setStyleSheet("border: 3px solid #ff0000;");
                }
                else{
                    widget->setStyleSheet("border: 1px solid #000000;");
                }
            }
        }
    }
}
