#include "settings.h"
#include "ui_settings.h"
#include"mainwindow.h"
#include<QSettings>
#include<QApplication>
#include<QDesktopWidget>
Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    ui->checkBox->setChecked(Settings_Pro->value("Prayer/CheckBox",false).toBool());
    ui->Isha_Time->setText(Settings_Pro->value("Prayer/IshaTime",1).toString());
            if(ui->checkBox->isChecked()==true){
                 ui->Isha_Time->setDisabled(false);
               }else{
                ui->Isha_Time->setDisabled(true);
            }

            QRect rec = QApplication::desktop()->screenGeometry();
            int height = rec.height();
            int width = rec.width();
    ui->AddingVar->setValue(Settings_Pro->value("HijriAdjust/AddingDay",0).toInt());
    ui->xpositionvalue->setValue(Settings_Pro->value("Interface/PrayerLabelsPositions/X-Position",width/2).toInt());
    ui->ypositionvalue->setValue(Settings_Pro->value("Interface/PrayerLabelsPositions/Y-Position",height/2).toInt());
    ui->spacevalue->setValue(Settings_Pro->value("Interface/PrayerLabelsPositions/Space",80).toInt());

    ui->xpositionvalue->setMaximum(width);
    ui->ypositionvalue->setMaximum(height);
    ui->spinBoxHadithXPosition->setMaximum(width);
    ui->spinBoxHadithYPosition->setMaximum(height);
    ui->MaximumValueX->setText(QVariant(width).toString());
    ui->MaximumValueY->setText(QVariant(height).toString());
    ui->xPositionClockMaximum->setText(QVariant(width).toString());
    ui->yPositionClockMaximum->setText(QVariant(height).toString());
    ui->xPositionClock->setValue(Settings_Pro->value("Interface/ClockandDatePosition/X-Position",width/2).toInt());
    ui->yPositionClock->setValue(Settings_Pro->value("Interface/ClockandDatePosition/Y-Position",height/2).toInt());
    ui->xPositionClock->setMaximum(width);
    ui->yPositionClock->setMaximum(height);
    ui->spinBoxFajer->setValue(Settings_Pro->value("Prayer/AqamahFajer",30).toInt());
    ui->spinBoxDhuhr->setValue(Settings_Pro->value("Prayer/AqamahDhuhr",15).toInt());
    ui->spinBoxAsr->setValue(Settings_Pro->value("Prayer/AqamahAsr",15).toInt());
    ui->spinBoxMagrib->setValue(Settings_Pro->value("Prayer/AqamahMagrib",15).toInt());
    ui->spinBoxIshaa->setValue(Settings_Pro->value("Prayer/AqamahIshaa",15).toInt());
    ui->spinBoxHadithXPosition->setValue(Settings_Pro->value("Interface/HadithPosition/X-Position",width/2).toInt());
    ui->spinBoxHadithYPosition->setValue(Settings_Pro->value("Interface/HadithPosition/Y-Position",height/2).toInt());



}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_checkBox_stateChanged(int arg1)
{
    //Disabling Textbox according to checkbox
            if(ui->checkBox->isChecked()==true){
            ui->Isha_Time->setDisabled(false);
            }else{
            ui->Isha_Time->setDisabled(true);
            }

}

void Settings::on_save_push_clicked()
{
    //saving the settings
    Settings_Pro->setValue("Prayer/IshaTime",ui->Isha_Time->text());
    Settings_Pro->setValue("Prayer/CheckBox",ui->checkBox->isChecked());
    Settings_Pro->setValue("HijriAdjust/AddingDay",ui->AddingVar->value());
    Settings_Pro->setValue("Interface/PrayerLabelsPositions/X-Position",ui->xpositionvalue->value());
    Settings_Pro->setValue("Interface/PrayerLabelsPositions/Y-Position",ui->ypositionvalue->value());
    Settings_Pro->setValue("Interface/PrayerLabelsPositions/Space",ui->spacevalue->value());
    Settings_Pro->setValue("Interface/ClockandDatePosition/X-Position",ui->xPositionClock->value());
    Settings_Pro->setValue("Interface/ClockandDatePosition/Y-Position",ui->yPositionClock->value());
    Settings_Pro->setValue("Prayer/AqamahFajer",ui->spinBoxFajer->value());
    Settings_Pro->setValue("Prayer/AqamahDhuhr",ui->spinBoxDhuhr->value());
    Settings_Pro->setValue("Prayer/AqamahAsr",ui->spinBoxAsr->value());
    Settings_Pro->setValue("Prayer/AqamahMagrib",ui->spinBoxMagrib->value());
    Settings_Pro->setValue("Prayer/AqamahIshaa",ui->spinBoxIshaa->value());
    Settings_Pro->setValue("Interface/HadithPosition/Y-Position",ui->spinBoxHadithYPosition->value());
    Settings_Pro->setValue("Interface/HadithPosition/X-Position",ui->spinBoxHadithXPosition->value());
    emit xPositionClocksignal();
}

void Settings::on_Grabbing_PButton_clicked()
{
    grabbing_times();
}

void Settings::on_Grabbing_Day_PButton_clicked()
{
//triggerDayUpdate=true;
}

void Settings::on_xPositionClock_editingFinished()
{

}
