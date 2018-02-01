#ifndef PMCOPYMODEL_H
#define PMCOPYMODEL_H

#include <QThread>

class PMCopyModel: public QThread
{
    Q_OBJECT
public:
    PMCopyModel();
    void setFileList(QStringList files);
    void setPath(QString path);

signals:
    void progress(QString , int);

protected slots:
    void run();

private:
    QStringList m_files;
    QString m_path;
};

#endif // PMCOPYMODEL_H
