#ifndef PMEXPLORERWIDGET_H
#define PMEXPLORERWIDGET_H

#include <QtWidgets>
#include "PMBookingListWidget.h"
#include "PMUploadWidget.h"

class PMExplorerWidget : public QWidget
{
    Q_OBJECT
public:
    PMExplorerWidget(QWidget * parent = 0);

public slots:
    void setProgress(QString label, int progress);
    void setProgressRange(int min, int max);
    void setRootPath(QString path);

protected:
    QLabel *m_progressLabel;
    QProgressBar *m_progressBar;
    PMBookingListWidget *m_bookingWidget ;
    PMBookingListModel *m_bookingListModel;

protected:
    QWidget* createFooter();

protected:
    QString m_rootPath;
};

#endif // PMEXPLORERWIDGET_H
