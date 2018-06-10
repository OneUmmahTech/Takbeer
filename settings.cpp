#include "settings.h"
#include "ui_settings.h"
#include"mainwindow.h"
#include<QSettings>
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

    ui->AddingVar->setValue(Settings_Pro->value("HijriAdjust/AddingDay",0).toInt());

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

}

void Settings::on_Grabbing_PButton_clicked()
{
    grabbing_times();
}

void Settings::on_Grabbing_Day_PButton_clicked()
{
//triggerDayUpdate=true;
}
