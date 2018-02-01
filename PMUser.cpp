#include "PMUser.h"

PMUser::PMUser()
{

}

QString PMUser::getLogin(){
    return m_login;
}

QString PMUser::getPassword(){
    return m_password;
}

QString PMUser::getStatus(){
    return m_status;
}

QString PMUser::getSpace(){
    return m_space;
}

void PMUser::setLogin(QString login){
    m_login = login;
}

void PMUser::setPassword(QString password){
    m_password = password;
}

void PMUser::setStatus(QString status){
    m_status = status;
}

void PMUser::setSpace(QString space){
    m_space = space;
}

void PMUser::print(){
    qDebug() << "PMUser:";
    qDebug() << "login:" << m_login;
    qDebug() << "status:" << m_status;
    qDebug() << "space:" << m_space;
}
