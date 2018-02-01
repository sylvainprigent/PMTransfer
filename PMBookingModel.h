#ifndef PMBOOKINGMODEL_H
#define PMBOOKINGMODEL_H

#include <QString>

class PMBookingModel
{
public:
    PMBookingModel();
    PMBookingModel(QString rootPath, QString dirname, int bookingID);

    void setRootPath(QString path);
    void setDirName(QString dirName);
    void setBookingID(int id);
    void checkDir();
    void setHourStart(QString hour);
    void setHourEnd(QString hour);
    void setDate(QString date);


    QString getRootPath();
    QString getDirName();
    int getBookingID();
    QString getHourStart();
    QString getHourEnd();
    int getFileNumber();
    QString getDate();

private:
    QString m_rootPath; // root path of the folder
    int m_bookingID; // id of the booking in Platform-Manager booking module
    QString m_dirName; // directory containing the data
    bool m_dirExists; // true if the dir exists on the server
    bool m_dirEmpty; // true if the directory does not contains data
    QString m_hourStart;
    QString m_hourEnd;
    int m_fileNumber;
    QString m_date;
};

#endif // PMBOOKINGMODEL_H
