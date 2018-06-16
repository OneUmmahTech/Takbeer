#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include<QApplication>
#include<QDesktopWidget>
#include"login.h"
#include<QKeyEvent>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

public:
    QRect rec = QApplication::desktop()->screenGeometry();
    int width;
    int height;
     QString Dir_setting_file=QApplication::applicationDirPath()+"/Settings.ini";
     QSettings* Settings_Pro = new QSettings(Dir_setting_file, QSettings::IniFormat);
     bool tests(){return triggerDayUpdate;}
     explicit Settings(QWidget *parent = 0);
    ~Settings();

private slots:
    void on_checkBox_stateChanged(int arg1);
    void on_save_push_clicked();

    void on_Grabbing_PButton_clicked();
    //void Updatetest(bool value);

    void on_Grabbing_Day_PButton_clicked();
    void on_xPositionClock_editingFinished();

    void on_BackupButton_clicked();
    void updateinterface();

    void on_AdvanceSettingsButton_clicked();
    void closeEvent(QCloseEvent *event);

signals:
    void xPositionClocksignal();
    void onClick();



private:
    Ui::Settings *ui;
    bool triggerDayUpdate=false;

};

#endif // SETTINGS_H
