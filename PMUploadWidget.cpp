#include "PMUploadWidget.h"
#include "PMUserAccess.h"

PMUploadWidget::PMUploadWidget(QWidget *parent) : QWidget(parent)
{

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget( createHomeWidget() );
    layout->addWidget( createFileViewWidget() );

    setAcceptDrops(true);
    this->setLayout(layout);

    m_homeLabel->show();
    m_viewglobal->hide();

    m_copyWidget = new PMCopyModel();
    connect(m_copyWidget, SIGNAL(progress(QString,int)), this, SIGNAL(progress(QString,int)));
}

void PMUploadWidget::openBooking(PMBookingModel model){

    QString directory = model.getRootPath() + QDir::separator() + PMUserAccess::instance()->getUser()->getLogin() + QDir::separator() + model.getDirName();

    QDir dir(directory);
    if ( !dir.exists() ){
        dir.mkpath(directory);
    }

    QString txt = "Reservation of " + model.getDate() + ", ";
    txt += "from "+ model.getHourStart() + " to " + model.getHourEnd() + "";
    m_navwidget->setText(txt);
    this->setPath(directory);
}

void PMUploadWidget::setPath( QString path ){

    m_homeLabel->hide();
    m_viewglobal->show();

    m_path = path;
    m_view->setRootIndex(m_dirmodel->setRootPath(path));
}

QWidget* PMUploadWidget::createFileViewWidget(){

    m_viewglobal = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;
    m_viewglobal->setLayout(layout);

    m_navwidget = new QLabel(this);
    layout->addWidget(m_navwidget);

    m_dirmodel = new QFileSystemModel(this);
    m_dirmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);

    m_view = new QTreeView(this);
    m_view->setModel(m_dirmodel);
    m_view->setContextMenuPolicy(Qt::CustomContextMenu);
    layout->addWidget(m_view);

    //connect(m_view, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(onCustomContextMenu(QPoint)));

    return m_viewglobal;
}

QWidget* PMUploadWidget::createHomeWidget(){

    m_homeLabel = new QLabel(this);
    m_homeLabel->setText("<p> Select a reservation on the left bar <p></p> and then drag & drop your files </p>");
    m_homeLabel->setAlignment(Qt::AlignCenter);
    return m_homeLabel;
}

void PMUploadWidget::uploadFile(QStringList files){

    int count = files.count();
    emit progressRange(0, count);
    m_copyWidget->setFileList(files);
    m_copyWidget->setPath(m_path);
    m_copyWidget->start();

}

void PMUploadWidget::dragEnterEvent(QDragEnterEvent *e)
{
    if (e->mimeData()->hasUrls()) {
        e->acceptProposedAction();
    }
}

void PMUploadWidget::dropEvent(QDropEvent *e)
{
    QStringList files;
    foreach (const QUrl &url, e->mimeData()->urls()) {
        QString fileName = url.toLocalFile();
        //qDebug() << "Dropped file:" << fileName;
        files.append(fileName);
    }
    this->uploadFile(files);
}
