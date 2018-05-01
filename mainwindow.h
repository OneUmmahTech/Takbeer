#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlQuery>
#include <QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<iostream>
#include<QMessageBox>
#include<QDate>
#include<Qt>
#include<QLocale>
#include<QtWebKitWidgets/QWebFrame>

QString *get_info();// function decleration
void grabbing_times();

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     QSqlQuery  query;
     //flags for events
     bool eventDayUpdate=false;
     bool eventMonthUpdate=false;
     bool eventAqama=false;
     int storedMonth=4;
     int aqamaTime=15;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void showTime();
    void aqamEvent();
    void aqamShowElement();
    void aqamHideelement();


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

