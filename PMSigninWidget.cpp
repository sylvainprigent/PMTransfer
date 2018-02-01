#include "PMSigninWidget.h"

PMSigninWidget::PMSigninWidget(QWidget *parent) : QWidget(parent)
{

    QGridLayout *layout = new QGridLayout();
    //this->setLayout(layout);

    QLabel* titleLabel = new QLabel(tr("Platform-Manager <br/> Data transfer"), this);
    titleLabel->setAlignment(Qt::AlignHCenter | Qt::AlignHCenter);
    titleLabel->setMinimumHeight(130);
    titleLabel->setStyleSheet(".QLabel {font-size: 24px;}");
    layout->addWidget(titleLabel, 0, 0, 1, 2);

    m_errorLabel = new QLabel(this);
    m_errorLabel->setVisible(false);
    m_errorLabel->setStyleSheet("QLabel { background-color : #FE642E}");
    layout->addWidget(m_errorLabel, 1, 0, 1, 2);

    QLabel *loginLabel = new QLabel(tr("Login"), this);
    m_loginLineEdit = new QLineEdit(this);
    layout->addWidget(loginLabel, 2, 0);
    layout->addWidget(m_loginLineEdit, 2,1);

    QLabel *passwordLabel = new QLabel(tr("Password"), this);
    m_passwordLineEdit = new QLineEdit(this);
    m_passwordLineEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordLabel, 3, 0);
    layout->addWidget(m_passwordLineEdit, 3,1);

    QLabel *spaceLabel = new QLabel(tr("Space"), this);
    m_spaceLineEdit = new QLineEdit(this);
    layout->addWidget(spaceLabel, 4, 0);
    layout->addWidget(m_spaceLineEdit, 4,1);

    QPushButton *loginButton = new QPushButton(tr("Login"), this);
    loginButton->setObjectName("btnPrimary");
    layout->addWidget(loginButton, 5, 0, 1, 2);


    //QWidget * widget = new QWidget;
    QGridLayout * layoutglobal = new QGridLayout(this);
    this->setLayout(layoutglobal);
    QWidget * signinWidget = new QWidget(this);
    signinWidget->setMinimumWidth(300);
    signinWidget->setLayout(layout);

    layoutglobal->addWidget(signinWidget);
    layoutglobal->setAlignment(signinWidget, Qt::AlignCenter);

    connect(loginButton, SIGNAL(released()), this, SLOT(emitLogin()));

}

void PMSigninWidget::setDefaultSpace(QString spaceName){
    m_spaceLineEdit->setText(spaceName);
}

void PMSigninWidget::setError(QString text){
    m_errorLabel->setText(text);
    m_errorLabel->setVisible(true);
}

void PMSigninWidget::emitLogin(){

    PMUser user;
    user.setLogin(m_loginLineEdit->text());
    user.setPassword(m_passwordLineEdit->text());
    user.setSpace(m_spaceLineEdit->text());
    emit login(user);
}
