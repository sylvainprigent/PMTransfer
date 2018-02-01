#include "PMSettingsAccess.h"

PMSettings::PMSettings()
{
    m_resourceID = 0;
}

PMSettings::PMSettings(QString fileUrl){
    m_fileUrl = fileUrl;
}

void PMSettings::setFileUrl(QString fileUrl){
    m_fileUrl = fileUrl;
}

void PMSettings::load(){
    QFile file(m_fileUrl);
    file.open(QIODevice::ReadOnly);

    QDataStream in(&file);
    in >> m_apiUrl;
    in >> m_defaultSpaceName;
    in >> m_destinationFolder;
    in >> m_resourceID;

    file.close();
}

void PMSettings::save(){
    QFile file(m_fileUrl);
    file.open(QIODevice::WriteOnly);

    QDataStream out(&file);
    out << m_apiUrl;
    out << m_defaultSpaceName;
    out << m_destinationFolder;
    out << m_resourceID;

    file.close();
}

QString PMSettings::getApiUrl(){
    return m_apiUrl;
}

QString PMSettings::getDefaultSpaceName(){
    return m_defaultSpaceName;
}

QString PMSettings::getDestinationFolder(){
    return m_destinationFolder;
}

int PMSettings::getResourceID(){
    return m_resourceID;
}

void PMSettings::setApiUrl(QString data){
    m_apiUrl = data;
}

void PMSettings::setDefaultSpaceName(QString data){
    m_defaultSpaceName = data;
}

void PMSettings::setDestinationFolder(QString data){
    m_destinationFolder = data;
}

void PMSettings::setResourceID(int id){
    m_resourceID = id;
}
