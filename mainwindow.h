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
#include<QSettings>
#include<QApplication>
#include "settings.h"
#include"hijri.h"
#include<QApplication>
#include<QDesktopWidget>
#include"login.h"


QString *get_info();// function decleration
void grabbing_times();

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
     Settings settingsform;
     Settings *sender= new Settings;
     Login *Log = new Login;
     QSqlQuery  query;
     QString StyleSheetPath=""+QApplication::applicationDirPath()+"/StyleSheet/stylesheet.css";
     int xPosition;
     int yPosition;
     int space;
     int xPositionClock;
     int yPositionClock;
     int yPositionHadith;
     int xPositionHadith;
     int widthHadith;
     int xPositionEvent;
     int yPositionEvent;
     int widthEvent;
     int heightEvent;
     int aqamaTime;
     hijri hijriTime;
     QRect rec = QApplication::desktop()->screenGeometry();
     //flags for events
     bool eventDayUpdate=false;
     bool eventMonthUpdate=false;
     bool eventAqama=false;
     int storedMonth=settingsform.Settings_Pro->value("GrabbingMonthData/storedMonth",1).toInt();
     int AqamahFajer=settingsform.Settings_Pro->value("Prayer/AqamahFajer",30).toInt();
     int AqamahDhuhr=settingsform.Settings_Pro->value("Prayer/AqamahDhuhr",15).toInt();
     int AqamahAsr=settingsform.Settings_Pro->value("Prayer/AqamahAsr",15).toInt();
     int AqamahMagrib=settingsform.Settings_Pro->value("Prayer/AqamahMagrib",15).toInt();
     int AqamahIshaa=settingsform.Settings_Pro->value("Prayer/AqamahIshaa",15).toInt();
     bool triggerDayUpdate=false;
     void BackgroundChanging();
     void interfacePrayerTimes(int xPosition,int yPosition, int space);
     void interfaceClock(int xPositionClock,int yPositionClock);
     void interfaceHadith(int xPositionHadith,int yPositionHadith,int widthHadith);
     void popUpMessage(QString EnglishMessage, QString ArabicMessage, bool eventAqama);
     void interfaceEvent(int xPositionEvent,int yPositionEvent , int widthEvent , int heightEvent);
     QString GuiCss(QString);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_pushButton_clicked();
    void showTime();
    void aqamEvent();
    void SettingsUpdateInterface();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

