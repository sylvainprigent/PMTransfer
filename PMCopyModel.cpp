#include "PMCopyModel.h"

#include <QFileInfo>
#include <iostream>
#include <QDir>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>
#include <QString>

PMCopyModel::PMCopyModel()
{

}

void PMCopyModel::setFileList(QStringList files){
    m_files = files;
}

void PMCopyModel::setPath(QString path){
    m_path = path;
}

void PMCopyModel::run(){

    for(int i = 0 ; i < m_files.count() ; i++){

        emit progress("Copy file " + QString::number(i+1) + "/" + QString::number(m_files.count()), i);
        QFileInfo fi(m_files[i]);
        QString copyfileurl = m_path + QDir::separator() + fi.fileName();
        QFile::copy(m_files[i], copyfileurl);

    }
    emit progress("Done", m_files.count());

}
