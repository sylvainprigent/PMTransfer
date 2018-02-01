#include "PMBookingModel.h"
#include "PMUserAccess.h"
#include <QDir>
#include <iostream>

PMBookingModel::PMBookingModel()
{
    m_dirExists = false;
    m_dirEmpty = true;
    m_fileNumber = 0;
}

PMBookingModel::PMBookingModel(QString rootPath, QString dirname, int bookingID){
    m_rootPath = rootPath;
    m_dirName = dirname;
    m_bookingID = bookingID;
    checkDir();
}

void PMBookingModel::setRootPath(QString path){
    m_rootPath = path;
}

void PMBookingModel::setDirName(QString dirName){
    m_dirName = dirName;
}

void PMBookingModel::setDate(QString date){
    m_date = date;
}

void PMBookingModel::setBookingID(int id){
    m_bookingID = id;
}

void PMBookingModel::setHourStart(QString hour){
    m_hourStart = hour;
}

void PMBookingModel::setHourEnd(QString hour){
    m_hourEnd = hour;
}

QString PMBookingModel::getRootPath(){
    return m_rootPath;
}

QString PMBookingModel::getDirName(){
    return m_dirName;
}

int PMBookingModel::getBookingID(){
    return m_bookingID;
}

QString PMBookingModel::getHourStart(){
    return m_hourStart;
}

QString PMBookingModel::getHourEnd(){
    return m_hourEnd;
}

QString PMBookingModel::getDate(){
    return m_date;
}

int PMBookingModel::getFileNumber(){
    return m_fileNumber;
}

void PMBookingModel::checkDir(){

    QString path = m_rootPath + QDir::separator() + PMUserAccess::instance()->getUser()->getLogin() + QDir::separator() + m_dirName;
    std::cout << "PMBookingModel dirname = " << path.toStdString() << std::endl;
    QDir dir(path);
    if ( dir.exists() ){
        m_dirExists = true;
        m_fileNumber = dir.count() - 2;

        if ( m_fileNumber > 0 ){
            m_dirEmpty = false;
        }
        else{
            m_dirEmpty = true;
        }
    }
    else{
        m_dirExists = false;
        m_dirEmpty = true;
        m_fileNumber = 0;
    }
    //qDebug() << "dir count for " << path << " : " << m_fileNumber;
}
