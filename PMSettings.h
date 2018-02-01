#ifndef PMSETTINGS_H
#define PMSETTINGS_H

#include <QtWidgets>

class PMSettings{


public:
    PMSettings();
    PMSettings(QString fileUrl);

public:
    void setFileUrl(QString fileUrl);
    void load();
    void save();

public:
    QString getApiUrl();
    QString getDefaultSpaceName();
    QString getDestinationFolder();
    int getResourceID();

    void setApiUrl(QString data);
    void setDefaultSpaceName(QString data);
    void setDestinationFolder(QString data);
    void setResourceID(int id);

protected:
    QString m_fileUrl;

protected:
    QString m_apiUrl;
    QString m_defaultSpaceName;
    QString m_destinationFolder;
    int m_resourceID;

};

#endif // PMSETTINGS_H
