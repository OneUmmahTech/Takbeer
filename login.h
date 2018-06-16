#ifndef LOGIN_H
#define LOGIN_H

#include <QObject>
#include <QWidget>
#include <QtGui>
#include <QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QMessageBox>
#include <QStyle>
#include <QDesktopWidget>
#include<QApplication>


class Login : public QWidget
{
    Q_OBJECT

public:
     explicit Login(QWidget *parent=0);
     ~Login();
public:
    void reject();
    QRect rec = QApplication::desktop()->screenGeometry();
    int width=rec.width();
    int height=rec.height();
    int randomNumber=qrand()%100;
    bool logvaild=false;
    QLabel *verification;
    QLabel *userLabel;
    QLabel *passLabel;
    QLineEdit *userLineEdit;
    QLineEdit *passLineEdit;
    QPushButton *loginButton;
    QPushButton *cancelButton;
private slots:
    void OnQuit();
    void OnLogin();

signals:
    void update();

};


#endif // LOGIN_H
