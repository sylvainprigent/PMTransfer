#ifndef PMUPLOADWIDGET_H
#define PMUPLOADWIDGET_H

#include <QtWidgets>
#include "PMBookingModel.h"
#include "PMCopyModel.h"

class PMUploadWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PMUploadWidget(QWidget *parent = 0);

signals:
    void progressRange(int, int);
    void progress(QString, int);

public slots:
    void setPath( QString path );
    void openBooking(PMBookingModel model);
    void uploadFile(QStringList files);

private:
    QWidget* createFileViewWidget();
    QWidget* createHomeWidget();

protected:
    QTreeView *m_view;
    QFileSystemModel *m_dirmodel;
    QLabel *m_homeLabel;
    QLabel *m_navwidget;
    QWidget *m_viewglobal;

protected:
    QString m_path;
    PMCopyModel *m_copyWidget;

protected:
    void dragEnterEvent(QDragEnterEvent *e);
    void dropEvent(QDropEvent *e);
};

#endif // PMUPLOADWIDGET_H
