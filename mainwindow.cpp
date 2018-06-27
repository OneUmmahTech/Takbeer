#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <iostream>
#include <QtWidgets/QMessageBox>
#include <QDate>
#include <Qt>
#include <QLocale>
#include <QtWebKitWidgets/QWebFrame>
#include <QtWebKit/QWebElement>
#include <QtWebKitWidgets/QtWebKitWidgets>
#include <QTimer>
#include <QDateTime>
#include <QVector>
#include <time.h>
#include <QSettings>
#include "settings.h"
#include "hijri.h"
#include "interface.h"
#include"database.h"
#include<QFile>
#include<QThread>
#include"login.h"
#include<QApplication>
#include<QDesktopWidget>

using namespace  std;
//Settings sett;
//QString PrintCalender(int d, int m, int y);
inline void delay(int millisecondsWait);

void MainWindow::showTime()
{
    QTime time =  QTime::currentTime();
    QString text = time.toString("hh:mm");
    QString Date_interface= QDate::currentDate().toString(Qt::ISODate);
    ui->GregorianDate->setText(Date_interface);

    if ((time.second() % 2) == 0)
        text[2] = ' ';
    // Position of Prayer Labels
       ui->ClockLabel->setText(text);
    if(time.toString()=="00:01:00")
        eventDayUpdate=true;
    if(QDate::currentDate().month()!=storedMonth)
        eventMonthUpdate=true;
    if(eventDayUpdate)
    {
        hijri hijriTime;
        ui->HijriDate->setText(hijriTime.PrintCalend());
       // updateDayInterface();
        interfacePrayerTimes(xPosition,yPosition,space);
        SettingsUpdateInterface();
        //    pray[0]=fajer;
        //    pray[1]=shrq;
        //    pray[2]=dhr;
        //    pray[3]=asr;
        //    pray[4]=mgrb;
        //    pray[5]=ash;
        //    pray[6]=MidNight;
        //    pray[7]=HadithArabic;
        //    pray[8]=HadithEnglish;
        //    pray[9]=EventEnglish;
        //    pray[10]=Eventtime;
        //    pray[11]=TypeHadith;
        //    pray[12]=EventArabic;
        QString *pray=get_info();
        ui->TimeLabelFajer->setText(pray[0]);
        ui->TimeLabelShrouq->setText(pray[1]);
        ui->TimeLabelDhuhr->setText(pray[2]);
        ui->TimeLabelAsr->setText(pray[3]);
        ui->TimeLabelMagrib->setText(pray[4]);
        ui->TimeLabelIshaa->setText(pray[5]);
        ui->ArabicHadithLabel->setText(pray[7]);
        ui->EnglishHadithLabel->setText(pray[8]);
        //ui->EventLabel->setText(pray[9]);
        if (pray[11]=="Quran"){
            ui->TabHadith->setText("آية اليوم\n Today's verse ");
        }else
        {

            ui->TabHadith->setText("حديث اليوم\n Today's Hadith");
        }

        eventDayUpdate=false;


    }
    if(eventMonthUpdate)
    {
        grabbing_times();
        eventMonthUpdate=false;
        settingsform.Settings_Pro->setValue("GrabbingMonthData/storedMonth",QDate::currentDate().month());

    }


}
void MainWindow::aqamEvent(){
    QTime time = QTime::currentTime();
    QString Fajer_con=ui->TimeLabelFajer->text()+":00";
    QString Sharouq_con=ui->TimeLabelShrouq->text()+":00";
    QString Dhuhr_con=ui->TimeLabelDhuhr->text()+":00";
    QString Asr_con=ui->TimeLabelAsr->text()+":00";
    QString Magrib_con=ui->TimeLabelMagrib->text()+":00";
    QString Ashaa_con=ui->TimeLabelIshaa->text()+":00";

    if(time.toString()==Fajer_con){
            eventAqama=true;
            AqamahFajer=settingsform.Settings_Pro->value("Prayer/AqamahFajer",30).toInt();
            aqamaTime=AqamahFajer;
            ui->TimeLabelIshaa->setProperty("Type",1);
            ui->TimeLabelIshaa->style()->polish(this);
            ui->TimeLabelIshaa->style()->unpolish(this);
            ui->TimeLabelIshaa->setStyleSheet(GuiCss(StyleSheetPath));
            ui->TimeLabelFajer->setProperty("Type",12);
            ui->TimeLabelFajer->style()->polish(this);
            ui->TimeLabelFajer->style()->unpolish(this);
            ui->TimeLabelFajer->setStyleSheet(GuiCss(StyleSheetPath));

          QString ArabicMessage="الوقت المتبقي لإقامة صلاة الفجر";
          QString EnglishMessage="Time remaining to Iqamah of Fajar Prayer";
        popUpMessage(EnglishMessage,ArabicMessage,eventAqama);
}
    if(time.toString()==Sharouq_con){

        ui->TimeLabelFajer->setProperty("Type",1);
        ui->TimeLabelFajer->style()->polish(this);
        ui->TimeLabelFajer->style()->unpolish(this);
        ui->TimeLabelFajer->setStyleSheet(GuiCss(StyleSheetPath));

    }
    if(time.toString()==Dhuhr_con){
        eventAqama=true;
        AqamahDhuhr=settingsform.Settings_Pro->value("Prayer/AqamahDhuhr",15).toInt();
        aqamaTime=AqamahDhuhr;
        QString ArabicMessage="الوقت المتبقي لإقامة صلاة الظهر";
        QString EnglishMessage="Time remaining to Iqamah of Dhuhr Prayer";

        ui->TimeLabelDhuhr->setProperty("Type",12);
        ui->TimeLabelDhuhr->style()->polish(this);
        ui->TimeLabelDhuhr->style()->unpolish(this);
        ui->TimeLabelDhuhr->setStyleSheet(GuiCss(StyleSheetPath));
         popUpMessage(EnglishMessage,ArabicMessage,eventAqama);



    }
    if(time.toString()==Asr_con){
        eventAqama=true;
        AqamahAsr=settingsform.Settings_Pro->value("Prayer/AqamahAsr",15).toInt();
        aqamaTime=AqamahAsr;
    QString ArabicMessage="الوقت المتبقي لإقامة صلاة العصر";
    QString EnglishMessage="Time remaining to Iqamah of Asr Prayer";
    ui->TimeLabelDhuhr->setProperty("Type",1);
    ui->TimeLabelDhuhr->style()->polish(this);
    ui->TimeLabelDhuhr->style()->unpolish(this);
    ui->TimeLabelDhuhr->setStyleSheet(GuiCss(StyleSheetPath));

    ui->TimeLabelAsr->setProperty("Type",12);
    ui->TimeLabelAsr->style()->polish(this);
    ui->TimeLabelAsr->style()->unpolish(this);
    ui->TimeLabelAsr->setStyleSheet(GuiCss(StyleSheetPath));
    popUpMessage(EnglishMessage,ArabicMessage,eventAqama);





    }
    if (time.toString()==Magrib_con)
    {
        eventAqama=true;
       AqamahMagrib=settingsform.Settings_Pro->value("Prayer/AqamahMagrib",15).toInt();
       aqamaTime=AqamahMagrib;
        QString ArabicMessage="الوقت المتبقي لإقامة صلاة المغرب";
       QString EnglishMessage="Time remaining to Iqamah of Maghrib Prayer";
       ui->TimeLabelAsr->setProperty("Type",1);
       ui->TimeLabelAsr->style()->polish(this);
       ui->TimeLabelAsr->style()->unpolish(this);
       ui->TimeLabelAsr->setStyleSheet(GuiCss(StyleSheetPath));

       ui->TimeLabelMagrib->setProperty("Type",12);
       ui->TimeLabelMagrib->style()->polish(this);
       ui->TimeLabelMagrib->style()->unpolish(this);
       ui->TimeLabelMagrib->setStyleSheet(GuiCss(StyleSheetPath));
       popUpMessage(EnglishMessage,ArabicMessage,eventAqama);


    }
    if (time.toString()==Ashaa_con)
    {
        eventAqama=true;
        AqamahIshaa=settingsform.Settings_Pro->value("Prayer/AqamahIshaa",15).toInt();
        aqamaTime=AqamahIshaa;
        QString ArabicMessage="الوقت المتبقي لإقامة صلاة العشاء";
        QString EnglishMessage="Time remaining to Iqamah of Isha Prayer";
        ui->TimeLabelMagrib->setProperty("Type",1);
        ui->TimeLabelMagrib->style()->polish(this);
        ui->TimeLabelMagrib->style()->unpolish(this);
        ui->TimeLabelMagrib->setStyleSheet(GuiCss(StyleSheetPath));

        ui->TimeLabelIshaa->setProperty("Type",12);
        ui->TimeLabelIshaa->style()->polish(this);
        ui->TimeLabelIshaa->style()->unpolish(this);
        ui->TimeLabelIshaa->setStyleSheet(GuiCss(StyleSheetPath));
        popUpMessage(EnglishMessage,ArabicMessage,eventAqama);

    }



}
inline void delay(int millisecondsWait)
{
    QEventLoop loop;
    QTimer t;
    t.connect(&t, &QTimer::timeout, &loop, &QEventLoop::quit);
    t.start(millisecondsWait);
    loop.exec();
}


void grabbing_times(){

    QUrl url = QUrl("https://www.gebetszeiten.de/Chemnitz/gebetszeiten-Chemnitz/169213-dit17de");
    QWebView *view = new QWebView();
    view->load(url);
    QString fajer_search_elements="tr.fajrRow";
    QString Shrouq_search_elements="tr.shuruukRow";
    QString dhuhr_search_elements="tr.dhuhrRow";
    QString assr_search_elements="tr.assrRow";
    QString magrib_search_elements="tr.maghrebRow";
    QString ishaa_search_elements="tr.ishaaRow";
    QEventLoop loop;
    QNetworkAccessManager num;
    QNetworkRequest req(url);
    QNetworkReply *reply = num.get(req);
    MainWindow::connect(reply,&QNetworkReply::finished,&loop,&QEventLoop::quit);
    loop.exec();
    QString buffer = reply->readAll();
    QWebFrame *frame =view->page()->mainFrame();
    frame->setHtml(buffer);
    QWebElement document = frame->documentElement();
    QWebElementCollection fajer_elements = document.findAll(fajer_search_elements);
    QWebElementCollection Shrouq_elements = document.findAll(Shrouq_search_elements);
    QWebElementCollection dhuhr_elements = document.findAll(dhuhr_search_elements);
    QWebElementCollection assr_elements = document.findAll(assr_search_elements);
    QWebElementCollection magrib_elements = document.findAll(magrib_search_elements);
    QWebElementCollection ishaa_elements = document.findAll(ishaa_search_elements);
    QRegExp rx("(\\ |\\,|\\.|\\t|\\n)");
    QStringList fajer_list;
    QStringList Shrouq_list;
    QStringList dhuhr_list;
    QStringList assr_list;
    QStringList magrib_list;
    QStringList ishaa_list;
    QStringList fajer_list_new;
    QStringList Shrouq_list_new;
    QStringList dhuhr_list_new;
    QStringList assr_list_new;
    QStringList magrib_list_new;
    QStringList ishaa_list_new;
    foreach (QWebElement fajer, fajer_elements){fajer_list= fajer.toPlainText().split(rx);for(int i=0;i<fajer_list.size();i++){if(fajer_list[i]=="Fadschr"|| fajer_list[i]=="*"){}else{fajer_list_new.append(fajer_list[i]);}}}
    foreach (QWebElement Shrouq, Shrouq_elements){Shrouq_list= Shrouq.toPlainText().split(rx);for(int i=0;i<Shrouq_list.size();i++){if(Shrouq_list[i]=="S'Aufgang"|| Shrouq_list[i]=="*"){}else{Shrouq_list_new.append(Shrouq_list[i]);}}}
    foreach (QWebElement dhuhr, dhuhr_elements){dhuhr_list= dhuhr.toPlainText().split(rx);for(int i=0;i<dhuhr_list.size();i++){if(dhuhr_list[i]=="Dhuhur"|| dhuhr_list[i]=="*"){}else{dhuhr_list_new.append(dhuhr_list[i]);}}}
    foreach (QWebElement assr, assr_elements){assr_list= assr.toPlainText().split(rx);for(int i=0;i<assr_list.size();i++){if(assr_list[i]=="'Assr"|| assr_list[i]=="*"){}else{assr_list_new.append(assr_list[i]);}}}
    foreach (QWebElement magrib, magrib_elements){magrib_list= magrib.toPlainText().split(rx);for(int i=0;i<magrib_list.size();i++){if(magrib_list[i]=="Maghrib"|| magrib_list[i]=="*"){}else{magrib_list_new.append(magrib_list[i]);}}}
    foreach (QWebElement ishaa, ishaa_elements){ishaa_list= ishaa.toPlainText().split(rx);for(int i=0;i<ishaa_list.size();i++){if(ishaa_list[i]=="Ischaa"|| ishaa_list[i]=="*"){}else{ishaa_list_new.append(ishaa_list[i]);}}}
    for(int i=0; i<fajer_list_new.size();i++){
        QString fajer=fajer_list_new[i];
        QString shrouq=Shrouq_list_new[i];
        QString dhuhr=dhuhr_list_new[i];
        QString assr=assr_list_new[i];
        QString mgrb=magrib_list_new[i];
        QString ishaa=ishaa_list_new[i];
        QDate current_date= QDate::currentDate();
        QDate date1;
        date1.setDate(current_date.year(),current_date.month(),1);
        QString date = date1.addDays(i).toString(Qt::ISODate);
        QSqlQuery query1;
//        QString ha="";
//        QString he="";

       query1.prepare("UPDATE `pry_table` SET `fjr`='"+fajer+"', `shrq`='"+shrouq+"', `dhr`='"+dhuhr+"', `asr`='"+assr+"', `mgrb`='"+mgrb+"', `ash`='"+ishaa+"' WHERE `date`='"+date+"'");
        query1.bindValue("date",date);
        query1.bindValue("fajer",fajer);
        query1.bindValue("shrouq",shrouq);
        query1.bindValue("dhuhr",dhuhr);
        query1.bindValue("assr",assr);
        query1.bindValue("mgrb",mgrb);
        query1.bindValue("ishaa",ishaa);
//        query1.bindValue("ha",ha);
//        query1.bindValue("he",he);
        query1.exec();




    }

}


QString* get_info(){struct QVariant;
                         {

        //define a variable for Date and convert it to string and this variable has a method to add days
        //so by increase g the date will increase
        QString date1 =QDate::currentDate().toString(Qt::ISODate);
       // qDebug()<<date1<<a;
        QSqlQuery query;
        query.prepare("SELECT `date`,TIME_FORMAT(`fjr`,'%H:%i'), TIME_FORMAT(`shrq`,'%H:%i'),TIME_FORMAT(`dhr`,'%H:%i') ,TIME_FORMAT(`asr`,'%H:%i'),TIME_FORMAT(`mgrb`,'%H:%i'),TIME_FORMAT(`ash`,'%H:%i'),`midnight`, `hadith_de`, `hadith_eng`, `eventEnglish`, `event_time`,`TypeHadith`,`eventArabic` FROM `pry_table` WHERE `date`='"+date1+"'");
        query.bindValue("date",date1);
        query.exec();
        //qDebug(query);
        query.first();

        //put the date in variables to use later
        QString fajer= query.value(1).toString();
        QString shrq= query.value(2).toString();
        QString dhr= query.value(3).toString();
        QString asr= query.value(4).toString();
        QString mgrb= query.value(5).toString();
        QString ash= query.value(6).toString();
        QString MidNight=query.value(7).toString();
        QString HadithArabic= query.value(8).toString();
        QString HadithEnglish= query.value(9).toString();
        QString EventEnglish= query.value(10).toString();
        QString Eventtime=query.value(11).toString();
        QString TypeHadith=query.value(12).toString();
        QString EventArabic=query.value(13).toString();
       // qDebug()<<he;
        QString* pray= new QString[13];

        pray[0]=fajer;
        pray[1]=shrq;
        pray[2]=dhr;
        pray[3]=asr;
        pray[4]=mgrb;
        pray[5]=ash;
        pray[6]=MidNight;
        pray[7]=HadithArabic;
        pray[8]=HadithEnglish;
        pray[9]=EventEnglish;
        pray[10]=Eventtime;
        pray[11]=TypeHadith;
        pray[12]=EventArabic;

        QString Dir_setting_file=QApplication::applicationDirPath()+"/Settings.ini";
        QSettings* Settings_Pro = new QSettings(Dir_setting_file, QSettings::IniFormat);
       if(Settings_Pro->value("Prayer/CheckBox",false).toBool()==true){
           int isha_Spec = Settings_Pro->value("Prayer/IshaTime",0).toInt();
           QTime isha = QTime::fromString(pray[4],"hh:mm");
           pray[5]=isha.addSecs(isha_Spec*60).toString("hh:mm");
         //  qDebug()<<isha<<pray[5]<<isha_Spec;

       }
        return pray;
                         }}



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    database databaseconnection;
    databaseconnection.connectDatabase();
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(showTime()));
     timer->start(1000);
   QObject::connect(sender,&Settings::xPositionClocksignal,this,&MainWindow::SettingsUpdateInterface);

    QTimer *timerEvent = new QTimer();
    connect(timerEvent, SIGNAL(timeout()),this,SLOT(aqamEvent()));
    timerEvent->start(1000);
    QMainWindow::showFullScreen();
    xPosition=settingsform.Settings_Pro->value("Interface/PrayerLabelsPositions/X-Position",500).toInt();
    yPosition=settingsform.Settings_Pro->value("Interface/PrayerLabelsPositions/Y-Position",500).toInt();
    space=settingsform.Settings_Pro->value("Interface/PrayerLabelsPositions/Space",80).toInt();
    xPositionClock=settingsform.Settings_Pro->value("Interface/ClockandDatePosition/X-Position",500).toInt();
    yPositionClock=settingsform.Settings_Pro->value("Interface/ClockandDatePosition/Y-Position",500).toInt();
    xPositionHadith=settingsform.Settings_Pro->value("Interface/HadithPosition/X-Position",500).toInt();
    yPositionHadith=settingsform.Settings_Pro->value("Interface/HadithPosition/Y-Position",500).toInt();
    widthHadith=settingsform.Settings_Pro->value("Interface/HadithPosition/Width",500).toInt();
    xPositionEvent=settingsform.Settings_Pro->value("Interface/EventPosition/X-Position",500).toInt();
    yPositionEvent=settingsform.Settings_Pro->value("Interface/EventPosition/Y-Position",500).toInt();
    widthEvent=settingsform.Settings_Pro->value("Interface/EventPosition/width",200).toInt();
    heightEvent=settingsform.Settings_Pro->value("Interface/EventPosition/height",300).toInt();
    interfaceEvent(xPositionEvent,yPositionEvent,widthEvent,heightEvent);
    //Adjustment of Positions Function
    interfacePrayerTimes(xPosition,yPosition,space);
    interfaceClock(xPositionClock,yPositionClock);
    interfaceHadith(xPositionHadith,yPositionHadith,widthHadith);
    hijri hijriTime;
    ui->HijriDate->setText(hijriTime.PrintCalend());
    BackgroundChanging();
    int height = rec.height();

    ui->pushButton->setGeometry(QRect(0,height-25,50,25));


}


MainWindow::~MainWindow()
{
    delete ui;
}
//intial g by -4 cause the date i have it is less then the current day by 4

void MainWindow::on_pushButton_clicked()
{
    //just uncomment the next function for grabbing date from Gebetszeit
   // grabbing_times();
    QObject::connect(sender,&Settings::xPositionClocksignal,this,&MainWindow::SettingsUpdateInterface);
    sender->show();



     //sender->show();
}
void MainWindow::SettingsUpdateInterface()
{
    xPosition=settingsform.Settings_Pro->value("Interface/PrayerLabelsPositions/X-Position",500).toInt();
    yPosition=settingsform.Settings_Pro->value("Interface/PrayerLabelsPositions/Y-Position",500).toInt();
    space=settingsform.Settings_Pro->value("Interface/PrayerLabelsPositions/Space",80).toInt();
    xPositionClock=settingsform.Settings_Pro->value("Interface/ClockandDatePosition/X-Position",500).toInt();
    yPositionClock=settingsform.Settings_Pro->value("Interface/ClockandDatePosition/Y-Position",500).toInt();
    xPositionHadith=settingsform.Settings_Pro->value("Interface/HadithPosition/X-Position",500).toInt();
    yPositionHadith=settingsform.Settings_Pro->value("Interface/HadithPosition/Y-Position",500).toInt();
    widthHadith=settingsform.Settings_Pro->value("Interface/HadithPosition/Width",500).toInt();
    xPositionEvent=settingsform.Settings_Pro->value("Interface/EventPosition/X-Position",500).toInt();
    yPositionEvent=settingsform.Settings_Pro->value("Interface/EventPosition/Y-Position",500).toInt();
    widthEvent=settingsform.Settings_Pro->value("Interface/EventPosition/width",200).toInt();
    heightEvent=settingsform.Settings_Pro->value("Interface/EventPosition/height",300).toInt();
    BackgroundChanging();
    interfaceEvent(xPositionEvent,yPositionEvent,widthEvent,heightEvent);
    interfacePrayerTimes(xPosition,yPosition,space);
    interfaceClock(xPositionClock,yPositionClock);
    interfaceHadith(xPositionHadith,yPositionHadith,widthHadith);
    ui->HijriDate->setText(hijriTime.PrintCalend());
    //    pray[0]=fajer;
    //    pray[1]=shrq;
    //    pray[2]=dhr;
    //    pray[3]=asr;
    //    pray[4]=mgrb;
    //    pray[5]=ash;
    //    pray[6]=MidNight;
    //    pray[7]=HadithArabic;
    //    pray[8]=HadithEnglish;
    //    pray[9]=EventEnglish;
    //    pray[10]=Eventtime;
    //    pray[11]=TypeHadith;
    //    pray[12]=EventArabic;
    QString *pray=get_info();
    ui->TimeLabelFajer->setText(pray[0]);
    ui->TimeLabelShrouq->setText(pray[1]);
    ui->TimeLabelDhuhr->setText(pray[2]);
    ui->TimeLabelAsr->setText(pray[3]);
    ui->TimeLabelMagrib->setText(pray[4]);
    ui->TimeLabelIshaa->setText(pray[5]);
    ui->ArabicHadithLabel->setText(pray[7]);
    ui->EnglishHadithLabel->setText(pray[8]);
    //ui->EventLabel->setText(pray[9]);
    if (pray[11]=="Quran"){
        ui->TabHadith->setText("آية اليوم\n Today's verse ");
    }else
    {

        ui->TabHadith->setText("حديث اليوم\n Today's Hadith");
    }



   }
QString MainWindow::GuiCss(QString CssFile){

    QFile styleFile(CssFile);
       styleFile.open(QIODevice::ReadOnly);
       QTextStream textStream(&styleFile);
       QString styleSheet = textStream.readAll();
       styleFile.close();
//       qDebug()<<styleSheet;
return styleSheet;
}

void MainWindow::interfacePrayerTimes(int xPosition, int yPosition, int space){

QString* PrayerTimes=get_info();
    //    pray[0]=fajer;
//    pray[1]=shrq;
//    pray[2]=dhr;
//    pray[3]=asr;
//    pray[4]=mgrb;
//    pray[5]=ash;
//    pray[6]=MidNight;
//    pray[7]=HadithArabic;
//    pray[8]=HadithEnglish;
//    pray[9]=EventEnglish;
//    pray[10]=Eventtime;
//    pray[11]=TypeHadith;
//    pray[12]=EventArabic;
//    //QLabel *TimeLabelFajer = new QLabel(this);
    ui->TimeLabelFajer->setGeometry(QRect(xPosition,yPosition,250,75));
    ui->TimeLabelFajer->setProperty("Type",1);
    ui->TimeLabelFajer->style()->polish(this);
    ui->TimeLabelFajer->style()->unpolish(this);
    ui->TimeLabelFajer->setAlignment(Qt::AlignCenter);
    ui->TimeLabelFajer->setText(PrayerTimes[0]);
    ui->TimeLabelFajer->setStyleSheet(GuiCss(StyleSheetPath));
    ui->TimeLabelFajer->show();
    //Fajer
    //QLabel *EnglishLabelTimeFajer= new QLabel (this);
    ui->EnglishLabelTimeFajer->setText("Fajer");
    ui->EnglishLabelTimeFajer->setGeometry(QRect(xPosition-220,yPosition,250,75));
    ui->EnglishLabelTimeFajer->setProperty("Type",2);
    ui->EnglishLabelTimeFajer->style()->polish(this);
    ui->EnglishLabelTimeFajer->style()->unpolish(this);
    ui->EnglishLabelTimeFajer->setAlignment(Qt::AlignCenter);
    ui->EnglishLabelTimeFajer->setStyleSheet(GuiCss(StyleSheetPath));
    ui->EnglishLabelTimeFajer->show();
    //Fajer
   // QLabel *ArabicLabelTimeFajer= new QLabel (this);
    ui->ArabicLabelTimeFajer->setText("الفجر");
    ui->ArabicLabelTimeFajer->setGeometry(QRect(xPosition+200,yPosition,250,75));
    ui->ArabicLabelTimeFajer->setProperty("Type",2);
    ui->ArabicLabelTimeFajer->style()->polish(this);
    ui->ArabicLabelTimeFajer->style()->unpolish(this);
    ui->ArabicLabelTimeFajer->setAlignment(Qt::AlignCenter);
    ui->ArabicLabelTimeFajer->setStyleSheet(GuiCss(StyleSheetPath));
    ui->ArabicLabelTimeFajer->show();
    //Shrouq
   // QLabel *TimeLabelShrouq = new QLabel(this);
    ui->TimeLabelShrouq->setGeometry(QRect(xPosition,yPosition+space,250,75));
    ui->TimeLabelShrouq->setProperty("Type",1);
    ui->TimeLabelShrouq->style()->polish(this);
    ui->TimeLabelShrouq->style()->unpolish(this);
    ui->TimeLabelShrouq->setAlignment(Qt::AlignCenter);
    ui->TimeLabelShrouq->setText(PrayerTimes[1]);
    ui->TimeLabelShrouq->setStyleSheet(GuiCss(StyleSheetPath));
    ui->TimeLabelShrouq->show();
    //Shrouq
    //QLabel *EnglishLabelTimeShrouq= new QLabel (this);
    ui->EnglishLabelTimeShrouq->setText("Shrouq");
    ui->EnglishLabelTimeShrouq->setGeometry(QRect(xPosition-220,yPosition+space,250,75));
    ui->EnglishLabelTimeShrouq->setProperty("Type",2);
    ui->EnglishLabelTimeShrouq->style()->polish(this);
    ui->EnglishLabelTimeShrouq->style()->unpolish(this);
    ui->EnglishLabelTimeShrouq->setAlignment(Qt::AlignCenter);
    ui->EnglishLabelTimeShrouq->setStyleSheet(GuiCss(StyleSheetPath));
    ui->EnglishLabelTimeShrouq->show();
    //shrouq
   // QLabel *ArabicLabelTimeShrouq= new QLabel (this);
    ui->ArabicLabelTimeShrouq->setText("شروق");
    ui->ArabicLabelTimeShrouq->setGeometry(QRect(xPosition+200,yPosition+space,250,75));
    ui->ArabicLabelTimeShrouq->setProperty("Type",2);
    ui->ArabicLabelTimeShrouq->style()->polish(this);
    ui->ArabicLabelTimeShrouq->style()->unpolish(this);
    ui->ArabicLabelTimeShrouq->setAlignment(Qt::AlignCenter);
    ui->ArabicLabelTimeShrouq->setStyleSheet(GuiCss(StyleSheetPath));
    ui->ArabicLabelTimeShrouq->show();
    //Dhuhr
   // QLabel *TimeLabelDhuhr = new QLabel(this);
    ui->TimeLabelDhuhr->setGeometry(QRect(xPosition,yPosition+(space*2),250,75));
    ui->TimeLabelDhuhr->setProperty("Type",1);
    ui->TimeLabelDhuhr->style()->polish(this);
    ui->TimeLabelDhuhr->style()->unpolish(this);
    ui->TimeLabelDhuhr->setAlignment(Qt::AlignCenter);
    ui->TimeLabelDhuhr->setText(PrayerTimes[2]);
    ui->TimeLabelDhuhr->setStyleSheet(GuiCss(StyleSheetPath));
    ui->TimeLabelDhuhr->show();
    //dhuhr
    //QLabel *EnglishLabelTimeDhuhr= new QLabel (this);
    ui->EnglishLabelTimeDhuhr->setText("Dhuhr");
    ui->EnglishLabelTimeDhuhr->setGeometry(QRect(xPosition-220,yPosition+(space*2),250,75));
    ui->EnglishLabelTimeDhuhr->setProperty("Type",2);
    ui->EnglishLabelTimeDhuhr->style()->polish(this);
    ui->EnglishLabelTimeDhuhr->style()->unpolish(this);
    ui->EnglishLabelTimeDhuhr->setAlignment(Qt::AlignCenter);
    ui->EnglishLabelTimeDhuhr->setStyleSheet(GuiCss(StyleSheetPath));
    ui->EnglishLabelTimeDhuhr->show();
    //dhuhr
   // QLabel *ArabicLabelTimeDhuhr= new QLabel (this);
    ui->ArabicLabelTimeDhuhr->setText("الظهر");
    ui->ArabicLabelTimeDhuhr->setGeometry(QRect(xPosition+200,yPosition+(space*2),250,75));
    ui->ArabicLabelTimeDhuhr->setProperty("Type",2);
    ui->ArabicLabelTimeDhuhr->style()->polish(this);
    ui->ArabicLabelTimeDhuhr->style()->unpolish(this);
    ui->ArabicLabelTimeDhuhr->setAlignment(Qt::AlignCenter);
    ui->ArabicLabelTimeDhuhr->setStyleSheet(GuiCss(StyleSheetPath));
    ui->ArabicLabelTimeDhuhr->show();

    //Asr
   // QLabel *TimeLabelAsr = new QLabel(this);
    ui->TimeLabelAsr->setGeometry(QRect(xPosition,yPosition+(space*3),250,75));
    ui->TimeLabelAsr->setProperty("Type",1);
    ui->TimeLabelAsr->style()->polish(this);
    ui->TimeLabelAsr->style()->unpolish(this);
    ui->TimeLabelAsr->setAlignment(Qt::AlignCenter);
    ui->TimeLabelAsr->setText(PrayerTimes[3]);
    ui->TimeLabelAsr->setStyleSheet(GuiCss(StyleSheetPath));
    ui->TimeLabelAsr->show();
    //Asr
   // QLabel *EnglishLabelTimeAsr= new QLabel (this);
    ui->EnglishLabelTimeAsr->setText("Asr");
    ui->EnglishLabelTimeAsr->setGeometry(QRect(xPosition-220,yPosition+(space*3),250,75));
    ui->EnglishLabelTimeAsr->setProperty("Type",2);
    ui->EnglishLabelTimeAsr->style()->polish(this);
    ui->EnglishLabelTimeAsr->style()->unpolish(this);
    ui->EnglishLabelTimeAsr->setAlignment(Qt::AlignCenter);
    ui->EnglishLabelTimeAsr->setStyleSheet(GuiCss(StyleSheetPath));
    ui->EnglishLabelTimeAsr->show();
    //asr
   // QLabel *ArabicLabelTimeAsr= new QLabel (this);
    ui->ArabicLabelTimeAsr->setText("العصر");
    ui->ArabicLabelTimeAsr->setGeometry(QRect(xPosition+200,yPosition+(space*3),250,75));
    ui->ArabicLabelTimeAsr->setProperty("Type",2);
    ui->ArabicLabelTimeAsr->style()->polish(this);
    ui->ArabicLabelTimeAsr->style()->unpolish(this);
    ui->ArabicLabelTimeAsr->setAlignment(Qt::AlignCenter);
    ui->ArabicLabelTimeAsr->setStyleSheet(GuiCss(StyleSheetPath));
    ui->ArabicLabelTimeAsr->show();
    //Magrib
   // QLabel *TimeLabelMagrib = new QLabel(this);
    ui->TimeLabelMagrib->setGeometry(QRect(xPosition,yPosition+(space*4),250,75));
    ui->TimeLabelMagrib->setProperty("Type",1);
    ui->TimeLabelMagrib->style()->polish(this);
    ui->TimeLabelMagrib->style()->unpolish(this);
    ui->TimeLabelMagrib->setAlignment(Qt::AlignCenter);
    ui->TimeLabelMagrib->setText(PrayerTimes[4]);
    ui->TimeLabelMagrib->setStyleSheet(GuiCss(StyleSheetPath));
    ui->TimeLabelMagrib->show();
    //Magrib
   // QLabel *EnglishLabelTimeMagrib= new QLabel (this);
    ui->EnglishLabelTimeMagrib->setText("Magrib");
    ui->EnglishLabelTimeMagrib->setGeometry(QRect(xPosition-220,yPosition+(space*4),250,75));
    ui->EnglishLabelTimeMagrib->setProperty("Type",2);
    ui->EnglishLabelTimeMagrib->style()->polish(this);
    ui->EnglishLabelTimeMagrib->style()->unpolish(this);
    ui->EnglishLabelTimeMagrib->setAlignment(Qt::AlignCenter);
    ui->EnglishLabelTimeMagrib->setStyleSheet(GuiCss(StyleSheetPath));
    ui->EnglishLabelTimeMagrib->show();
    //magrib
    //QLabel *ArabicLabelTimemagrib= new QLabel (this);
    ui->ArabicLabelTimemagrib->setText("المغرب");
    ui->ArabicLabelTimemagrib->setGeometry(QRect(xPosition+200,yPosition+(space*4),250,75));
    ui->ArabicLabelTimemagrib->setProperty("Type",2);
    ui->ArabicLabelTimemagrib->style()->polish(this);
    ui->ArabicLabelTimemagrib->style()->unpolish(this);
    ui->ArabicLabelTimemagrib->setAlignment(Qt::AlignCenter);
    ui->ArabicLabelTimemagrib->setStyleSheet(GuiCss(StyleSheetPath));
    ui->ArabicLabelTimemagrib->show();
    //ishaa
  //  QLabel *TimeLabelIshaa = new QLabel(this);
    ui->TimeLabelIshaa->setGeometry(QRect(xPosition,yPosition+(space*5),250,75));
    ui->TimeLabelIshaa->setProperty("Type",1);
    ui->TimeLabelIshaa->style()->polish(this);
    ui->TimeLabelIshaa->style()->unpolish(this);
    ui->TimeLabelIshaa->setAlignment(Qt::AlignCenter);
    ui->TimeLabelIshaa->setText(PrayerTimes[5]);
    ui->TimeLabelIshaa->setStyleSheet(GuiCss(StyleSheetPath));
    ui->TimeLabelIshaa->show();
    //ishaa
  //  QLabel *EnglishLabelTimeIshaa= new QLabel (this);
    ui->EnglishLabelTimeIshaa->setText("Ishaa");
    ui->EnglishLabelTimeIshaa->setGeometry(QRect(xPosition-220,yPosition+(space*5),250,75));
    ui->EnglishLabelTimeIshaa->setProperty("Type",2);
    ui->EnglishLabelTimeIshaa->style()->polish(this);
    ui->EnglishLabelTimeIshaa->style()->unpolish(this);
    ui->EnglishLabelTimeIshaa->setAlignment(Qt::AlignCenter);
    ui->EnglishLabelTimeIshaa->setStyleSheet(GuiCss(StyleSheetPath));
    ui->EnglishLabelTimeIshaa->show();
    //ishaa
   // QLabel *ArabicLabelTimeIshaa= new QLabel (this);
    ui->ArabicLabelTimeIshaa->setText("العشاء");
    ui->ArabicLabelTimeIshaa->setGeometry(QRect(xPosition+200,yPosition+(space*5),250,75));
    ui->ArabicLabelTimeIshaa->setProperty("Type",2);
    ui->ArabicLabelTimeIshaa->style()->polish(this);
    ui->ArabicLabelTimeIshaa->style()->unpolish(this);
    ui->ArabicLabelTimeIshaa->setAlignment(Qt::AlignCenter);
    ui->ArabicLabelTimeIshaa->setStyleSheet(GuiCss(StyleSheetPath));
    ui->ArabicLabelTimeIshaa->show();


}

void MainWindow::interfaceClock(int xPositionClock,int yPositionClock){

     //clock position
    ui->ClockLabel->setGeometry(QRect(xPositionClock,yPositionClock,500,400));
    ui->ClockLabel->setProperty("Type",3);
    ui->ClockLabel->style()->polish(this);
    ui->ClockLabel->style()->unpolish(this);
    ui->ClockLabel->setAlignment(Qt::AlignTop);
     ui->ClockLabel->setAlignment(Qt::AlignCenter);
    ui->ClockLabel->setStyleSheet(GuiCss(StyleSheetPath));
    ui->ClockLabel->show();
     //Date Hijri
    ui->HijriDate->setGeometry(QRect(xPositionClock+30,yPositionClock+200,400,200));
    ui->HijriDate->setProperty("Type",4);
    ui->HijriDate->style()->polish(this);
    ui->HijriDate->style()->unpolish(this);
    ui->HijriDate->setAlignment(Qt::AlignCenter);
    ui->HijriDate->setStyleSheet(GuiCss(StyleSheetPath));
    ui->HijriDate->show();
    //Date Gregoian
    ui->GregorianDate->setGeometry(QRect(xPositionClock+30,yPositionClock+150,400,200));
    ui->GregorianDate->setProperty("Type",4);
    ui->GregorianDate->style()->polish(this);
    ui->GregorianDate->style()->unpolish(this);
    ui->GregorianDate->setAlignment(Qt::AlignCenter);
    ui->GregorianDate->setStyleSheet(GuiCss(StyleSheetPath));
    ui->GregorianDate->show();

}
void MainWindow::interfaceHadith(int xPositionHadith, int yPositionHadith, int widthHadith){
    QString *Hadith = get_info();
//    pray[0]=fajer;
//    pray[1]=shrq;
//    pray[2]=dhr;
//    pray[3]=asr;
//    pray[4]=mgrb;
//    pray[5]=ash;
//    pray[6]=MidNight;
//    pray[7]=HadithArabic;
//    pray[8]=HadithEnglish;
//    pray[9]=EventEnglish;
//    pray[10]=Eventtime;
//    pray[11]=TypeHadith;
//    pray[12]=EventArabic;
    if (Hadith[11]=="Hadith"){
        ui->TabHadith->setText("حديث اليوم\n Today's Hadith");
    }
    if (Hadith[11]=="Quran"){
        ui->TabHadith->setText("آية اليوم\n Today's verse ");
    }

    ui->TabHadith->setGeometry(QRect(xPositionHadith+widthHadith-200,yPositionHadith-50,200,50));
    ui->TabHadith->setProperty("Type",6);
    ui->TabHadith->style()->polish(this);
    ui->TabHadith->style()->unpolish(this);

    ui->TabHadith->setAlignment(Qt::AlignTop);
    ui->TabHadith->setAlignment(Qt::AlignCenter);
    ui->TabHadith->setStyleSheet(GuiCss(StyleSheetPath));
    ui->TabHadith->show();
    //Arabic Hadith
    ui->ArabicHadithLabel->setGeometry(QRect(xPositionHadith,yPositionHadith,widthHadith,200));
    ui->ArabicHadithLabel->setProperty("Type",5);
    ui->ArabicHadithLabel->style()->polish(this);
    ui->ArabicHadithLabel->style()->unpolish(this);
    ui->ArabicHadithLabel->setText(Hadith[7]);
    ui->ArabicHadithLabel->setAlignment(Qt::AlignTop);
    ui->ArabicHadithLabel->setAlignment(Qt::AlignCenter);
    ui->ArabicHadithLabel->setStyleSheet(GuiCss(StyleSheetPath));
    ui->ArabicHadithLabel->show();
    //English Hadith
    ui->EnglishHadithLabel->setGeometry(QRect(xPositionHadith,yPositionHadith+203,widthHadith,200));
    ui->EnglishHadithLabel->setProperty("Type",5);
    ui->EnglishHadithLabel->style()->polish(this);
    ui->EnglishHadithLabel->style()->unpolish(this);
    ui->EnglishHadithLabel->setText(Hadith[8]);
    ui->EnglishHadithLabel->setAlignment(Qt::AlignTop);
    ui->EnglishHadithLabel->setAlignment(Qt::AlignCenter);
    ui->EnglishHadithLabel->setStyleSheet(GuiCss(StyleSheetPath));
    ui->EnglishHadithLabel->show();
}
void MainWindow::BackgroundChanging(){

    int day= QDate::currentDate().day();
    QString path= QApplication::applicationDirPath();

    this->setStyleSheet("QMainWindow{border-image: url("+path+"/Background/Background"+QVariant(day).toString()+".jpg) 0 0 0 0 stretch stretch;border-width: 0px}");

}
void MainWindow::popUpMessage(QString EnglishMessage, QString ArabicMessage, bool eventAqama){

    Settings ScreenDim;
    int xPositionMessage=0;
    int yPositionMessage=ScreenDim.height/2;
    int width =ScreenDim.width;

   // qDebug()<<ScreenDim.width;
    ui->PopMessageBackground->setGeometry(QRect(xPositionMessage,yPositionMessage,width,500));
    ui->PopMessageBackground->setProperty("Type",8);
    ui->PopMessageBackground->style()->polish(this);
    ui->PopMessageBackground->style()->unpolish(this);
    ui->PopMessageBackground->setAlignment(Qt::AlignTop);
     ui->PopMessageBackground->setAlignment(Qt::AlignCenter);
    ui->PopMessageBackground->setStyleSheet(GuiCss(StyleSheetPath));
    ui->PopMessageBackground->show();
    ui->AqamaLabelCounter->setGeometry(QRect(xPositionMessage,yPositionMessage+180,width,500));
    ui->AqamaLabelCounter->setProperty("Type",9);
    ui->AqamaLabelCounter->style()->polish(this);
    ui->AqamaLabelCounter->style()->unpolish(this);
    ui->AqamaLabelCounter->setAlignment(Qt::AlignCenter);
    ui->AqamaLabelCounter->setStyleSheet(GuiCss(StyleSheetPath));
    ui->AqamaLabelCounter->show();
    ui->AqamahTimeunit->setGeometry(QRect(xPositionMessage+500,yPositionMessage+300,300,200));
    ui->AqamahTimeunit->setProperty("Type",10);
    ui->AqamahTimeunit->style()->polish(this);
    ui->AqamahTimeunit->style()->unpolish(this);
    ui->AqamahTimeunit->setAlignment(Qt::AlignCenter);
    ui->AqamahTimeunit->setStyleSheet(GuiCss(StyleSheetPath));
    ui->AqamahTimeunit->show();

    if(eventAqama)
    {

    for(int i=aqamaTime ; i>=1 ;--i)
    {


 QString counter=QVariant(i).toString();
 QHBoxLayout *layout = new QHBoxLayout;
layout->addWidget(ui->AqamahTimeunit);
layout->addWidget(ui->AqamaLabelCounter);

        ui->AqamahTimeunit->setText("دقيقة \n Minutes");
        ui->AqamaLabelCounter->setText(counter);
        ui->PopMessageBackground->setText(""+ArabicMessage+"\n"+EnglishMessage+"");
        delay(60000);

    }
    ui->AqamahTimeunit->hide();
    ui->AqamaLabelCounter->hide();
    ui->PopMessageBackground->hide();
    eventAqama=false;

}



}
void MainWindow::interfaceEvent(int xPositionEvent, int yPositionEvent, int widthEvent, int heightEvent){
    //    pray[0]=fajer;
    //    pray[1]=shrq;
    //    pray[2]=dhr;
    //    pray[3]=asr;
    //    pray[4]=mgrb;
    //    pray[5]=ash;
    //    pray[6]=MidNight;
    //    pray[7]=HadithArabic;
    //    pray[8]=HadithEnglish;
    //    pray[9]=EventEnglish;
    //    pray[10]=Eventtime;
    //    pray[11]=TypeHadith;
    //    pray[12]=EventArabic;
    QString *pray=get_info();
    QString title="معلومات \n Information \n"+pray[12]+"\n"+pray[9]+"";
    ui->EventLabel->setGeometry(QRect(xPositionEvent,yPositionEvent,widthEvent,heightEvent));
    ui->EventLabel->setProperty("Type",13);
    ui->EventLabel->setText(title);
    ui->EventLabel->style()->polish(this);
    ui->EventLabel->style()->unpolish(this);
    ui->EventLabel->setAlignment(Qt::AlignTop);
    ui->EventLabel->setAlignment(Qt::AlignCenter);
    ui->EventLabel->setStyleSheet(GuiCss(StyleSheetPath));
    ui->EventLabel->show();

}
