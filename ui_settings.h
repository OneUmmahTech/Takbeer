/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QTabWidget *tabWidget;
    QWidget *General;
    QGroupBox *Grabbing_GBox;
    QPushButton *Grabbing_PButton;
    QPushButton *Grabbing_Day_PButton;
    QWidget *Prayer;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QLineEdit *Isha_Time;
    QLabel *label;
    QWidget *Date;
    QGroupBox *Hijri_Adjustment;
    QSpinBox *AddingVar;
    QLabel *AddingDayLable;
    QPushButton *save_push;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(624, 421);
        tabWidget = new QTabWidget(Settings);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 0, 591, 371));
        General = new QWidget();
        General->setObjectName(QStringLiteral("General"));
        Grabbing_GBox = new QGroupBox(General);
        Grabbing_GBox->setObjectName(QStringLiteral("Grabbing_GBox"));
        Grabbing_GBox->setGeometry(QRect(10, 10, 171, 121));
        Grabbing_PButton = new QPushButton(Grabbing_GBox);
        Grabbing_PButton->setObjectName(QStringLiteral("Grabbing_PButton"));
        Grabbing_PButton->setGeometry(QRect(10, 30, 141, 29));
        Grabbing_Day_PButton = new QPushButton(Grabbing_GBox);
        Grabbing_Day_PButton->setObjectName(QStringLiteral("Grabbing_Day_PButton"));
        Grabbing_Day_PButton->setGeometry(QRect(10, 70, 141, 29));
        tabWidget->addTab(General, QString());
        Prayer = new QWidget();
        Prayer->setObjectName(QStringLiteral("Prayer"));
        groupBox = new QGroupBox(Prayer);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 161, 121));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(10, 30, 95, 27));
        Isha_Time = new QLineEdit(groupBox);
        Isha_Time->setObjectName(QStringLiteral("Isha_Time"));
        Isha_Time->setGeometry(QRect(10, 60, 71, 29));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(90, 60, 67, 21));
        tabWidget->addTab(Prayer, QString());
        Date = new QWidget();
        Date->setObjectName(QStringLiteral("Date"));
        Hijri_Adjustment = new QGroupBox(Date);
        Hijri_Adjustment->setObjectName(QStringLiteral("Hijri_Adjustment"));
        Hijri_Adjustment->setGeometry(QRect(10, 10, 201, 111));
        AddingVar = new QSpinBox(Hijri_Adjustment);
        AddingVar->setObjectName(QStringLiteral("AddingVar"));
        AddingVar->setGeometry(QRect(110, 60, 61, 30));
        AddingVar->setMinimum(-33);
        AddingVar->setMaximum(32);
        AddingDayLable = new QLabel(Hijri_Adjustment);
        AddingDayLable->setObjectName(QStringLiteral("AddingDayLable"));
        AddingDayLable->setGeometry(QRect(10, 60, 101, 21));
        tabWidget->addTab(Date, QString());
        save_push = new QPushButton(Settings);
        save_push->setObjectName(QStringLiteral("save_push"));
        save_push->setGeometry(QRect(510, 380, 91, 29));

        retranslateUi(Settings);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Settings", Q_NULLPTR));
        Grabbing_GBox->setTitle(QApplication::translate("Settings", "Grabbing Data", Q_NULLPTR));
        Grabbing_PButton->setText(QApplication::translate("Settings", "Grabbing Month", Q_NULLPTR));
        Grabbing_Day_PButton->setText(QApplication::translate("Settings", "Grabbing Day", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(General), QApplication::translate("Settings", "Gerenal", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Settings", "Specific Time for Isha", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Settings", "Active ", Q_NULLPTR));
        label->setText(QApplication::translate("Settings", "Minutes", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Prayer), QApplication::translate("Settings", "Prayer", Q_NULLPTR));
        Hijri_Adjustment->setTitle(QApplication::translate("Settings", "Hijri Adjustment", Q_NULLPTR));
        AddingDayLable->setText(QApplication::translate("Settings", "Adding Days", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Date), QApplication::translate("Settings", "Date", Q_NULLPTR));
        save_push->setText(QApplication::translate("Settings", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
