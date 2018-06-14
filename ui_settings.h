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
#include <QtWidgets/QTextBrowser>
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
    QGroupBox *BackupSettings;
    QPushButton *BackupButton;
    QTextBrowser *textBrowser;
    QWidget *Prayer;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QLineEdit *Isha_Time;
    QLabel *label;
    QGroupBox *AqamahGroup;
    QLabel *AqamahLabelFajer;
    QLabel *AqamahLabelDhuhr;
    QLabel *AqamahLabelAsr;
    QLabel *AqamahLabelMagrib;
    QLabel *AqamahLabelIshaa;
    QSpinBox *spinBoxFajer;
    QSpinBox *spinBoxDhuhr;
    QSpinBox *spinBoxAsr;
    QSpinBox *spinBoxMagrib;
    QSpinBox *spinBoxIshaa;
    QWidget *Date;
    QGroupBox *Hijri_Adjustment;
    QSpinBox *AddingVar;
    QLabel *AddingDayLable;
    QWidget *Interface;
    QGroupBox *PrayerLabelsPosition;
    QSpinBox *xpositionvalue;
    QSpinBox *ypositionvalue;
    QLabel *xPosition;
    QLabel *yPosition;
    QLabel *Spacelabel;
    QSpinBox *spacevalue;
    QLabel *MaximumValueX;
    QLabel *MaximumValueY;
    QLabel *MaximumValueS;
    QLabel *MaxLabelXposition;
    QLabel *MaxLabelYposition;
    QLabel *MaxLabelSpace;
    QGroupBox *ClockInterface;
    QSpinBox *xPositionClock;
    QSpinBox *yPositionClock;
    QLabel *xPositionClockLabel;
    QLabel *yPositionClockLabel;
    QLabel *xPositionClockMaximum;
    QLabel *yPositionClockMaximum;
    QLabel *MaxLabelYposition_2;
    QLabel *MaxLabelXposition_2;
    QGroupBox *HadithPosition;
    QLabel *HadithYPositionLabel;
    QLabel *HadithXpositionLabel;
    QSpinBox *spinBoxHadithXPosition;
    QSpinBox *spinBoxHadithYPosition;
    QSpinBox *spinBoxHadithWidth;
    QLabel *HadithWidthLabel;
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
        BackupSettings = new QGroupBox(General);
        BackupSettings->setObjectName(QStringLiteral("BackupSettings"));
        BackupSettings->setGeometry(QRect(10, 140, 571, 131));
        BackupButton = new QPushButton(BackupSettings);
        BackupButton->setObjectName(QStringLiteral("BackupButton"));
        BackupButton->setGeometry(QRect(10, 30, 111, 29));
        textBrowser = new QTextBrowser(BackupSettings);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 70, 551, 51));
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
        AqamahGroup = new QGroupBox(Prayer);
        AqamahGroup->setObjectName(QStringLiteral("AqamahGroup"));
        AqamahGroup->setGeometry(QRect(10, 140, 161, 191));
        AqamahLabelFajer = new QLabel(AqamahGroup);
        AqamahLabelFajer->setObjectName(QStringLiteral("AqamahLabelFajer"));
        AqamahLabelFajer->setGeometry(QRect(10, 40, 67, 21));
        AqamahLabelDhuhr = new QLabel(AqamahGroup);
        AqamahLabelDhuhr->setObjectName(QStringLiteral("AqamahLabelDhuhr"));
        AqamahLabelDhuhr->setGeometry(QRect(10, 70, 67, 21));
        AqamahLabelAsr = new QLabel(AqamahGroup);
        AqamahLabelAsr->setObjectName(QStringLiteral("AqamahLabelAsr"));
        AqamahLabelAsr->setGeometry(QRect(10, 100, 67, 21));
        AqamahLabelMagrib = new QLabel(AqamahGroup);
        AqamahLabelMagrib->setObjectName(QStringLiteral("AqamahLabelMagrib"));
        AqamahLabelMagrib->setGeometry(QRect(10, 130, 67, 21));
        AqamahLabelIshaa = new QLabel(AqamahGroup);
        AqamahLabelIshaa->setObjectName(QStringLiteral("AqamahLabelIshaa"));
        AqamahLabelIshaa->setGeometry(QRect(10, 160, 67, 21));
        spinBoxFajer = new QSpinBox(AqamahGroup);
        spinBoxFajer->setObjectName(QStringLiteral("spinBoxFajer"));
        spinBoxFajer->setGeometry(QRect(80, 30, 50, 30));
        spinBoxDhuhr = new QSpinBox(AqamahGroup);
        spinBoxDhuhr->setObjectName(QStringLiteral("spinBoxDhuhr"));
        spinBoxDhuhr->setGeometry(QRect(80, 60, 50, 30));
        spinBoxAsr = new QSpinBox(AqamahGroup);
        spinBoxAsr->setObjectName(QStringLiteral("spinBoxAsr"));
        spinBoxAsr->setGeometry(QRect(80, 90, 50, 30));
        spinBoxMagrib = new QSpinBox(AqamahGroup);
        spinBoxMagrib->setObjectName(QStringLiteral("spinBoxMagrib"));
        spinBoxMagrib->setGeometry(QRect(80, 120, 50, 30));
        spinBoxIshaa = new QSpinBox(AqamahGroup);
        spinBoxIshaa->setObjectName(QStringLiteral("spinBoxIshaa"));
        spinBoxIshaa->setGeometry(QRect(80, 150, 50, 30));
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
        Interface = new QWidget();
        Interface->setObjectName(QStringLiteral("Interface"));
        PrayerLabelsPosition = new QGroupBox(Interface);
        PrayerLabelsPosition->setObjectName(QStringLiteral("PrayerLabelsPosition"));
        PrayerLabelsPosition->setGeometry(QRect(10, 20, 351, 151));
        xpositionvalue = new QSpinBox(PrayerLabelsPosition);
        xpositionvalue->setObjectName(QStringLiteral("xpositionvalue"));
        xpositionvalue->setGeometry(QRect(140, 40, 81, 30));
        xpositionvalue->setMaximum(10000);
        ypositionvalue = new QSpinBox(PrayerLabelsPosition);
        ypositionvalue->setObjectName(QStringLiteral("ypositionvalue"));
        ypositionvalue->setGeometry(QRect(140, 70, 81, 30));
        ypositionvalue->setMaximum(10000);
        xPosition = new QLabel(PrayerLabelsPosition);
        xPosition->setObjectName(QStringLiteral("xPosition"));
        xPosition->setGeometry(QRect(10, 50, 81, 21));
        yPosition = new QLabel(PrayerLabelsPosition);
        yPosition->setObjectName(QStringLiteral("yPosition"));
        yPosition->setGeometry(QRect(10, 80, 81, 21));
        Spacelabel = new QLabel(PrayerLabelsPosition);
        Spacelabel->setObjectName(QStringLiteral("Spacelabel"));
        Spacelabel->setGeometry(QRect(10, 110, 111, 21));
        spacevalue = new QSpinBox(PrayerLabelsPosition);
        spacevalue->setObjectName(QStringLiteral("spacevalue"));
        spacevalue->setGeometry(QRect(140, 100, 81, 30));
        spacevalue->setMaximum(500);
        MaximumValueX = new QLabel(PrayerLabelsPosition);
        MaximumValueX->setObjectName(QStringLiteral("MaximumValueX"));
        MaximumValueX->setGeometry(QRect(270, 50, 67, 21));
        MaximumValueY = new QLabel(PrayerLabelsPosition);
        MaximumValueY->setObjectName(QStringLiteral("MaximumValueY"));
        MaximumValueY->setGeometry(QRect(270, 80, 67, 21));
        MaximumValueS = new QLabel(PrayerLabelsPosition);
        MaximumValueS->setObjectName(QStringLiteral("MaximumValueS"));
        MaximumValueS->setGeometry(QRect(270, 110, 67, 21));
        MaxLabelXposition = new QLabel(PrayerLabelsPosition);
        MaxLabelXposition->setObjectName(QStringLiteral("MaxLabelXposition"));
        MaxLabelXposition->setGeometry(QRect(230, 50, 31, 21));
        MaxLabelYposition = new QLabel(PrayerLabelsPosition);
        MaxLabelYposition->setObjectName(QStringLiteral("MaxLabelYposition"));
        MaxLabelYposition->setGeometry(QRect(230, 80, 31, 21));
        MaxLabelSpace = new QLabel(PrayerLabelsPosition);
        MaxLabelSpace->setObjectName(QStringLiteral("MaxLabelSpace"));
        MaxLabelSpace->setGeometry(QRect(230, 110, 31, 21));
        ClockInterface = new QGroupBox(Interface);
        ClockInterface->setObjectName(QStringLiteral("ClockInterface"));
        ClockInterface->setGeometry(QRect(10, 180, 351, 111));
        xPositionClock = new QSpinBox(ClockInterface);
        xPositionClock->setObjectName(QStringLiteral("xPositionClock"));
        xPositionClock->setGeometry(QRect(140, 40, 81, 30));
        xPositionClock->setMaximum(10000);
        yPositionClock = new QSpinBox(ClockInterface);
        yPositionClock->setObjectName(QStringLiteral("yPositionClock"));
        yPositionClock->setGeometry(QRect(140, 70, 81, 30));
        yPositionClock->setMaximum(10000);
        xPositionClockLabel = new QLabel(ClockInterface);
        xPositionClockLabel->setObjectName(QStringLiteral("xPositionClockLabel"));
        xPositionClockLabel->setGeometry(QRect(20, 40, 81, 21));
        yPositionClockLabel = new QLabel(ClockInterface);
        yPositionClockLabel->setObjectName(QStringLiteral("yPositionClockLabel"));
        yPositionClockLabel->setGeometry(QRect(20, 70, 81, 21));
        xPositionClockMaximum = new QLabel(ClockInterface);
        xPositionClockMaximum->setObjectName(QStringLiteral("xPositionClockMaximum"));
        xPositionClockMaximum->setGeometry(QRect(270, 40, 67, 21));
        yPositionClockMaximum = new QLabel(ClockInterface);
        yPositionClockMaximum->setObjectName(QStringLiteral("yPositionClockMaximum"));
        yPositionClockMaximum->setGeometry(QRect(270, 70, 67, 21));
        MaxLabelYposition_2 = new QLabel(ClockInterface);
        MaxLabelYposition_2->setObjectName(QStringLiteral("MaxLabelYposition_2"));
        MaxLabelYposition_2->setGeometry(QRect(230, 70, 31, 21));
        MaxLabelXposition_2 = new QLabel(ClockInterface);
        MaxLabelXposition_2->setObjectName(QStringLiteral("MaxLabelXposition_2"));
        MaxLabelXposition_2->setGeometry(QRect(230, 40, 31, 21));
        HadithPosition = new QGroupBox(Interface);
        HadithPosition->setObjectName(QStringLiteral("HadithPosition"));
        HadithPosition->setGeometry(QRect(370, 20, 211, 151));
        HadithYPositionLabel = new QLabel(HadithPosition);
        HadithYPositionLabel->setObjectName(QStringLiteral("HadithYPositionLabel"));
        HadithYPositionLabel->setGeometry(QRect(10, 40, 71, 21));
        HadithXpositionLabel = new QLabel(HadithPosition);
        HadithXpositionLabel->setObjectName(QStringLiteral("HadithXpositionLabel"));
        HadithXpositionLabel->setGeometry(QRect(10, 70, 71, 21));
        spinBoxHadithXPosition = new QSpinBox(HadithPosition);
        spinBoxHadithXPosition->setObjectName(QStringLiteral("spinBoxHadithXPosition"));
        spinBoxHadithXPosition->setGeometry(QRect(90, 40, 81, 30));
        spinBoxHadithYPosition = new QSpinBox(HadithPosition);
        spinBoxHadithYPosition->setObjectName(QStringLiteral("spinBoxHadithYPosition"));
        spinBoxHadithYPosition->setGeometry(QRect(90, 70, 81, 30));
        spinBoxHadithWidth = new QSpinBox(HadithPosition);
        spinBoxHadithWidth->setObjectName(QStringLiteral("spinBoxHadithWidth"));
        spinBoxHadithWidth->setGeometry(QRect(90, 100, 81, 30));
        HadithWidthLabel = new QLabel(HadithPosition);
        HadithWidthLabel->setObjectName(QStringLiteral("HadithWidthLabel"));
        HadithWidthLabel->setGeometry(QRect(10, 100, 71, 21));
        tabWidget->addTab(Interface, QString());
        save_push = new QPushButton(Settings);
        save_push->setObjectName(QStringLiteral("save_push"));
        save_push->setGeometry(QRect(510, 380, 91, 29));

        retranslateUi(Settings);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Settings", Q_NULLPTR));
        Grabbing_GBox->setTitle(QApplication::translate("Settings", "Grabbing Data", Q_NULLPTR));
        Grabbing_PButton->setText(QApplication::translate("Settings", "Grabbing Month", Q_NULLPTR));
        Grabbing_Day_PButton->setText(QApplication::translate("Settings", "Grabbing Day", Q_NULLPTR));
        BackupSettings->setTitle(QApplication::translate("Settings", "Backup Settings", Q_NULLPTR));
        BackupButton->setText(QApplication::translate("Settings", "BackUp", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(General), QApplication::translate("Settings", "Gerenal", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Settings", "Specific Time for Isha", Q_NULLPTR));
        checkBox->setText(QApplication::translate("Settings", "Active ", Q_NULLPTR));
        label->setText(QApplication::translate("Settings", "Minutes", Q_NULLPTR));
        AqamahGroup->setTitle(QApplication::translate("Settings", "Aqamah Settings", Q_NULLPTR));
        AqamahLabelFajer->setText(QApplication::translate("Settings", "Fajer", Q_NULLPTR));
        AqamahLabelDhuhr->setText(QApplication::translate("Settings", "Dhuhr", Q_NULLPTR));
        AqamahLabelAsr->setText(QApplication::translate("Settings", "Asr", Q_NULLPTR));
        AqamahLabelMagrib->setText(QApplication::translate("Settings", "Magrib", Q_NULLPTR));
        AqamahLabelIshaa->setText(QApplication::translate("Settings", "Ishaa", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Prayer), QApplication::translate("Settings", "Prayer", Q_NULLPTR));
        Hijri_Adjustment->setTitle(QApplication::translate("Settings", "Hijri Adjustment", Q_NULLPTR));
        AddingDayLable->setText(QApplication::translate("Settings", "Adding Days", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Date), QApplication::translate("Settings", "Date", Q_NULLPTR));
        PrayerLabelsPosition->setTitle(QApplication::translate("Settings", "Prayer Labels Position", Q_NULLPTR));
        xPosition->setText(QApplication::translate("Settings", "X Position", Q_NULLPTR));
        yPosition->setText(QApplication::translate("Settings", "Y Position", Q_NULLPTR));
        Spacelabel->setText(QApplication::translate("Settings", "Space Vertical", Q_NULLPTR));
        MaximumValueX->setText(QApplication::translate("Settings", "TextLabel", Q_NULLPTR));
        MaximumValueY->setText(QApplication::translate("Settings", "TextLabel", Q_NULLPTR));
        MaximumValueS->setText(QApplication::translate("Settings", "500", Q_NULLPTR));
        MaxLabelXposition->setText(QApplication::translate("Settings", "Max.", Q_NULLPTR));
        MaxLabelYposition->setText(QApplication::translate("Settings", "Max.", Q_NULLPTR));
        MaxLabelSpace->setText(QApplication::translate("Settings", "Max.", Q_NULLPTR));
        ClockInterface->setTitle(QApplication::translate("Settings", "Clock And Date Position", Q_NULLPTR));
        xPositionClockLabel->setText(QApplication::translate("Settings", "X Position", Q_NULLPTR));
        yPositionClockLabel->setText(QApplication::translate("Settings", "Y Position", Q_NULLPTR));
        xPositionClockMaximum->setText(QApplication::translate("Settings", "TextLabel", Q_NULLPTR));
        yPositionClockMaximum->setText(QApplication::translate("Settings", "TextLabel", Q_NULLPTR));
        MaxLabelYposition_2->setText(QApplication::translate("Settings", "Max.", Q_NULLPTR));
        MaxLabelXposition_2->setText(QApplication::translate("Settings", "Max.", Q_NULLPTR));
        HadithPosition->setTitle(QApplication::translate("Settings", "Hadith Position", Q_NULLPTR));
        HadithYPositionLabel->setText(QApplication::translate("Settings", "X Position", Q_NULLPTR));
        HadithXpositionLabel->setText(QApplication::translate("Settings", "Y Position", Q_NULLPTR));
        HadithWidthLabel->setText(QApplication::translate("Settings", "Width", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(Interface), QApplication::translate("Settings", "Interface", Q_NULLPTR));
        save_push->setText(QApplication::translate("Settings", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
