#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include<iostream>
#include<QtWidgets/QMessageBox>
#include<QDate>
#include<Qt>
#include<QLocale>
#include<QtWebKitWidgets/QWebFrame>
#include<QtWebKit/QWebElement>
#include<QtWebKitWidgets/QtWebKitWidgets>
#include<QTimer>
#include<QDateTime>
#include<QVector>
#include<time.h>
#include<QSettings>
#include"settings.h"
#include"hijri.h"


using namespace  std;
//Settings sett;
//QString PrintCalender(int d, int m, int y);
inline void delay(int millisecondsWait);
void MainWindow::updateDayInterface(){
        QString* pray= new QString[7];
        pray=get_info();
 ui->Fajer->setText(pray[0]);
       // qDebug()<<pray[0]<<;
        // Updating the times on current GUI
        //MainWindow::ui->Fajer->setText("test");
        ui->Shourq->setText(pray[1]);
        ui->Duhur->setText(pray[2]);
        ui->Asr->setText(pray[3]);
        ui->Magrib->setText(pray[4]);
        ui->Asha->setText(pray[5]);
        // Updating Hadith arabic and English with Automatic sizing of the font
        ui->label_13->setText(pray[6]);
        ui->label_15->setText(pray[7]);

}
//void MainWindow::setter_triggerDayUpdate(bool x){
//    qDebug()<<"function wroks"<<x;
//    triggerDayUpdate=x;
//      qDebug()<<"function wroks"<<triggerDayUpdate<<x;
//}
void MainWindow::aqamHideelement(){
    ui->graphicsView->hide();
    ui->graphicsView_2->hide();
    ui->label_14->hide();
    ui->AqamaLabelCounter->hide();
    ui->time_remain_en->hide();
    ui->time_value->hide();
    ui->time_remain_ar->hide();
}
void MainWindow::aqamShowElement(){
    ui->AqamaLabelCounter->show();
    ui->graphicsView->show();
    ui->graphicsView_2->show();
    ui->label_14->show();
    ui->time_remain_en->show();
    ui->time_value->show();
    ui->time_remain_ar->show();
    }

void MainWindow::showTime()
{
     //qDebug()<<eventDayUpdate<<endl;
    QTime time =  QTime::currentTime();
    QString text = time.toString("hh:mm");
    QString Date_interface= QDate::currentDate().toString(Qt::ISODate);
    ui->Magrib_2->setText(Date_interface);
    hijri hijriTime;
    ui->label_16->setText(hijriTime.PrintCalend());
//    qDebug()<<triggerDayUpdate;
    if ((time.second() % 2) == 0)
        text[2] = ' ';        updateDayInterface();

    ui->min->setText(text);
    if(ui->Fajer->text()=="00:00")
        eventDayUpdate=true;
    if(time.toString()=="00:01:00")
        eventDayUpdate=true;
    if(QDate::currentDate().month()!=storedMonth)
        eventMonthUpdate=true;
//    if(sett.tests()==true){
//        updateDayInterface();
//       // sett->triggerDayUpdate=false;
//        qDebug()<<"it triggered";
//    }
    if(eventDayUpdate)
    {
       // updateDayInterface();

        eventDayUpdate=false;
    }
    if(eventMonthUpdate)
    {
        grabbing_times();
        eventMonthUpdate=false;
        //Settings->setValue("Gerenal/StoredMonth",QDate::currentDate().month());

    }


}
void MainWindow::aqamEvent(){
    QTime time = QTime::currentTime();
    QString Fajer_con=ui->Fajer->text()+":00";
    QString Dhuhr_con=ui->Duhur->text()+":00";
    QString Asr_con=ui->Asr->text()+":00";
    QString Magrib_con=ui->Magrib->text()+":00";
    QString Ashaa_con=ui->Asha->text()+":00";
   // qDebug()<<Fajer_con<<Dhuhr_con<<Asr_con<<Magrib_con<<Ashaa_con;
    if(time.toString()==Fajer_con){
            eventAqama=true;
            aqamaTime=20;
            ui->time_remain_ar->setText("الوقت المتبقي لإقامة صلاة الفجر");
            ui->time_remain_en->setText("Time remaining for Iqamah of Fajar Prayer");

}
    if(time.toString()==Dhuhr_con){
        eventAqama=true;
        aqamaTime=15;
        ui->time_remain_ar->setText("الوقت المتبقي لإقامة صلاة الظهر");
        ui->time_remain_en->setText("Time remaining for Iqamah of Dhuhr Prayer");

    }
    if(time.toString()==Asr_con){
        eventAqama=true;
        aqamaTime=15;
        ui->time_remain_ar->setText("الوقت المتبقي لإقامة صلاة العصر");
        ui->time_remain_en->setText("Time remaining for Iqamah of Assr Prayer");


    }
    if (time.toString()==Magrib_con)
    {
        eventAqama=true;
        aqamaTime=5;
        ui->time_remain_ar->setText("الوقت المتبقي لإقامة صلاة المغرب");
        ui->time_remain_en->setText("Time remaining for Iqamah of Maghrib Prayer");

    }
    if (time.toString()==Ashaa_con)
    {
        eventAqama=true;
        aqamaTime=5;
        ui->time_remain_ar->setText("الوقت المتبقي لإقامة صلاة العشاء");
        ui->time_remain_en->setText("Time remaining for Iqamah of Isha Prayer");

    }
    if(eventAqama)
    {

    for(int i=aqamaTime ; i>=1 ;--i)
    {


        QString counter=QVariant(i).toString();
        aqamShowElement();
        ui->AqamaLabelCounter->setText(counter);

        delay(60000);

    }
    eventAqama=false;
    aqamHideelement();
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
//    qDebug()<<fajer_list_new;
//    qDebug()<<dhuhr_list_new;
//    qDebug()<<Shrouq_list_new;
//    qDebug()<<assr_list_new;
//    qDebug()<<magrib_list_new;
//    qDebug()<<ishaa_list_new;
    //query to delete the table before we insert the new data for one month
//    QSqlQuery query_delete_table;
//    query_delete_table.prepare("TRUNCATE TABLE pry_table");
//    query_delete_table.exec();
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

void connect_database(){

    QMessageBox msg;
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("root");
    db.setDatabaseName("db_ib");

    if(db.open()){
//        msg.setText("the database connected");
//        msg.exec();
    }
    else{
        msg.setText("the database unconnected");
        msg.exec();
    }
}


QString* get_info(){struct QVariant;
                         {

        //define a variable for Date and convert it to string and this variable has a method to add days
        //so by increase g the date will increase
        QString date1 =QDate::currentDate().toString(Qt::ISODate);
       // qDebug()<<date1<<a;
        QSqlQuery query;
        query.prepare("SELECT `date`,TIME_FORMAT(`fjr`,'%H:%i'), TIME_FORMAT(`shrq`,'%H:%i'),TIME_FORMAT(`dhr`,'%H:%i') ,TIME_FORMAT(`asr`,'%H:%i'),TIME_FORMAT(`mgrb`,'%H:%i'),TIME_FORMAT(`ash`,'%H:%i'),`midnight`, `hadith_eng`, `hadith_de` FROM `pry_table` WHERE `date`='"+date1+"'");
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
        QString ha= query.value(8).toString();
        QString he= query.value(9).toString();

        QString* pray= new QString[8];
        pray[0]=fajer;
        pray[1]=shrq;
        pray[2]=dhr;
        pray[3]=asr;
        pray[4]=mgrb;
        pray[5]=ash;
        pray[6]=ha;
        pray[7]=he;
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
    connect_database();
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start(1000);
    QTimer *timerEvent = new QTimer();
    connect(timerEvent, SIGNAL(timeout()),this,SLOT(aqamEvent()));
    timerEvent->start(1000);
    QMainWindow::showFullScreen();

    aqamHideelement();


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
    Settings settingForm ;
    settingForm.setModal(true);
    settingForm.exec();

}
