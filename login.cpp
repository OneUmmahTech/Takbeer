#include "login.h"
#include <QHBoxLayout>
#include <QObject>
#include <QWidget>
#include <QtGui>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include"settings.h"
#include"mainwindow.h"
Login::Login(QWidget *parent):QWidget(parent)
{
    setGeometry(width/2,height/2,300,120);
       setFixedSize(300, 120);
       setWindowTitle("Login Settings");
    loginButton = new QPushButton("Login");
    cancelButton= new QPushButton("Cancel");
    QHBoxLayout* hLayout = new QHBoxLayout();
    QHBoxLayout* hLayout1 = new QHBoxLayout();
    QHBoxLayout* hLayout3 = new QHBoxLayout();
     QHBoxLayout* hLayout2 = new QHBoxLayout();
    QVBoxLayout* vLayout = new QVBoxLayout(this);
        userLabel = new QLabel("Username:");
        passLabel = new QLabel("Password:");
        verification = new QLabel("Verification Number is : "+QVariant(randomNumber).toString()+"");
        userLineEdit = new QLineEdit();
        passLineEdit = new QLineEdit();
        passLineEdit->setEchoMode(QLineEdit::Password);
        hLayout3->addWidget(verification,1);
        hLayout1->addWidget(userLabel,1);
        hLayout1->addWidget(userLineEdit,2);
        hLayout2->addWidget(passLabel,1);
        hLayout2->addWidget(passLineEdit,2);
    hLayout->addWidget(loginButton,1);
    hLayout->addWidget(cancelButton,2);
    vLayout->addSpacing(1);
    vLayout->addLayout(hLayout3);
    vLayout->addLayout(hLayout1);
    vLayout->addLayout(hLayout2);
    vLayout->addLayout(hLayout);
    setLayout(vLayout);
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(OnQuit()));
        connect(loginButton, SIGNAL(clicked()), this, SLOT(OnLogin()));
}

void Login::reject()
{
    OnQuit();
}

void Login::OnQuit()
{
    this->close();
  //  parentWidget()->close();
}

void Login::OnLogin()
{
    QString username = userLineEdit->text();
    QString password = passLineEdit->text();
    int pass= randomNumber*3+2009;
    // Checking if username or password is empty
    if (username.isEmpty() || password.isEmpty())
        QMessageBox::information(this, tr("Info"), "Password and  Username can not be empty");
    else
        this->destroy();
    if(username=="admin" && password==QVariant(pass).toString()){
        emit update();


        //QObject::connect(Setting,&Settings::xPositionClocksignal,this,&MainWindow::SettingsUpdateInterface);

    }else{
        QMessageBox::information(this, tr("Info"), "Your Password or Username wrong");
    }

}
Login::~Login()
{

}
