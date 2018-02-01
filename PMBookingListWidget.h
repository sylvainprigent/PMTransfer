#ifndef PMBOOKINGLISTWIDGET_H
#define PMBOOKINGLISTWIDGET_H

#include <QtWidgets>
#include "PMBookingListModel.h"

class PMBookingListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PMBookingListWidget(QWidget *parent = 0);
    explicit PMBookingListWidget(PMBookingListModel *bookingList, QWidget *parent = 0);

signals:
    void openBooking(PMBookingModel);

private slots:
    void setBookingList(PMBookingListModel *bookingList);
    void setBookingList();
    void openBookingChangeView(PMBookingModel model);

private:
    QVBoxLayout *m_layout;

private:
    PMBookingListModel *m_model;
};

#endif // PMBOOKINGLISTWIDGET_H
