#include "PMSettingsWidget.h"
#include "PMSettings.h"

PMSettingsWidget::PMSettingsWidget(QWidget *parent) : QWidget(parent)
{

    QVBoxLayout *layout = new QVBoxLayout();

    // default date
    QGridLayout *settingslayout = new QGridLayout();
    QGroupBox *groupSettings = new QGroupBox(tr("Settings"), this);
    groupSettings->setLayout(settingslayout);
    layout->addWidget(groupSettings);

    m_errorLabel = new QLabel(this);
    m_errorLabel->setVisible(false);
    m_errorLabel->setStyleSheet("QLabel { background-color : #FE642E}");
    settingslayout->addWidget(m_errorLabel, 0, 0, 1, 3);

    settingslayout->addWidget(new QLabel(tr("Platform-Manager API URL")), 1, 0);
    m_apiUrl = new QLineEdit(this);
    settingslayout->addWidget(m_apiUrl, 1, 1);

    settingslayout->addWidget(new QLabel(tr("Platform-Manager space")), 2, 0);
    m_defaultSpace = new QLineEdit(this);
    settingslayout->addWidget(m_defaultSpace, 2, 1);

    settingslayout->addWidget(new QLabel(tr("Resource ID")), 3, 0);
    m_resourceID = new QLineEdit(this);
    settingslayout->addWidget(m_resourceID, 3, 1);

    settingslayout->addWidget(new QLabel(tr("Destination directory")), 4, 0);
    m_destinationFolder = new QLineEdit(this);
    QPushButton *browseButton = new QPushButton("...", this);
    connect(browseButton, SIGNAL(released()), this, SLOT(browseDefaultDir()));
    settingslayout->addWidget(m_destinationFolder, 4, 1);
    settingslayout->addWidget(browseButton, 4, 2);

    m_saveButton = new QPushButton("Save", this);
    connect(m_saveButton, SIGNAL(released()), this, SLOT(validated()));
    settingslayout->addWidget(m_saveButton, 5, 2);

    m_progressBar = new QProgressBar(this);
    m_progressBar->setValue(0);
    m_progressBar->setVisible(false);
    settingslayout->addWidget(m_progressBar, 6, 0, 1, 3);

    this->setLayout(layout);
}

void PMSettingsWidget::setErrorMessage(QString message){
    m_errorLabel->setText(message);
    m_errorLabel->setVisible(true);
}

void PMSettingsWidget::setSettings(PMSettings *settings){
    m_apiUrl->setText(settings->getApiUrl());
    m_defaultSpace->setText(settings->getDefaultSpaceName());
    m_destinationFolder->setText(settings->getDestinationFolder());
    m_resourceID->setText( QString::number( settings->getResourceID() ) );
}

void PMSettingsWidget::setProgressValue(int bytesReceived){
    m_progressBar->setValue(bytesReceived);
    m_progressBar->setVisible(true);
}

void PMSettingsWidget::setRange(int min, int max){
    m_progressBar->setRange(min, max);
}

void PMSettingsWidget::enableValidationButton(bool enable){
    m_saveButton->setEnabled(enable);
}

void PMSettingsWidget::validated(){

    emit validated(this->getSettings());
}

PMSettings* PMSettingsWidget::getSettings(){
    PMSettings *settings = new PMSettings;
    settings->setApiUrl(m_apiUrl->text());
    settings->setDefaultSpaceName(m_defaultSpace->text());
    settings->setDestinationFolder(m_destinationFolder->text());
    settings->setResourceID(m_resourceID->text().toInt());
    return settings;
}

void PMSettingsWidget::browseDefaultDir(){
    QString dir = QFileDialog::getExistingDirectory(this);
    m_destinationFolder->setText(dir);
}
