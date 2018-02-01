#include "PMExplorerWidget.h"

PMExplorerWidget::PMExplorerWidget(QWidget *parent) : QWidget(parent)
{

    // create widget
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setSpacing(2);

    // create booking widget
    QSplitter *splitter = new QSplitter;


    m_bookingListModel = new PMBookingListModel(this);
    m_bookingWidget = new PMBookingListWidget(m_bookingListModel, this);

    PMUploadWidget *uploadWidget = new PMUploadWidget();

    splitter->addWidget( m_bookingWidget );
    splitter->addWidget( uploadWidget );

    layout->addWidget(splitter, 1);
    layout->addWidget(this->createFooter(), 0);

    this->setLayout(layout);

    connect(m_bookingWidget, SIGNAL(openBooking(PMBookingModel)), uploadWidget, SLOT(openBooking(PMBookingModel)));
    connect(uploadWidget, SIGNAL(progressRange(int, int)), this, SLOT(setProgressRange(int, int)));
    connect(uploadWidget, SIGNAL(progress(QString, int)), this, SLOT(setProgress(QString, int)));
}

// ------------------------------------------
//                  Widgets
// ------------------------------------------
QWidget* PMExplorerWidget::createFooter(){
    QWidget *widget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout;
    widget->setLayout(layout);

    m_progressLabel = new QLabel(this);
    m_progressBar = new QProgressBar(this);

    layout->addWidget(new QWidget(this), 0, Qt::AlignRight);
    layout->addWidget( m_progressLabel, 1, Qt::AlignRight);
    layout->addWidget( m_progressBar, 1, Qt::AlignRight);

    m_progressLabel->setVisible(false);
    m_progressBar->setVisible(false);

    return widget;
}

// ------------------------------------------
//              PUBLIC SLOTS
// ------------------------------------------
void PMExplorerWidget::setProgress(QString label, int progress){

    m_progressLabel->setText(label);
    m_progressBar->setValue(progress);

    if (progress == m_progressBar->maximum()){
        m_progressLabel->setVisible(false);
        m_progressBar->setVisible(false);
    }
    else{
        m_progressLabel->setVisible(true);
        m_progressBar->setVisible(true);
    }
}

void PMExplorerWidget::setProgressRange(int min, int max){
    m_progressBar->setRange(min, max);
}

void PMExplorerWidget::setRootPath(QString path){
    m_rootPath = path;
    m_bookingListModel->init();
}
