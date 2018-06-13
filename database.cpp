#include "database.h"
#include <QtSql/QtSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QMessageBox>

database::database()
{

}
void database::connectDatabase(){

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


