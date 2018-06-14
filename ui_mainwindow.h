/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <dynamicfontsizelabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *GregorianDate;
    QLabel *ClockLabel;
    QLabel *HijriDate;
    DynamicFontSizeLabel *ArabicHadithLabel;
    DynamicFontSizeLabel *EnglishHadithLabel;
    QLabel *AqamaLabelCounter;
    DynamicFontSizeLabel *event;
    QLabel *TimeLabelFajer;
    QLabel *EnglishLabelTimeFajer;
    QLabel *ArabicLabelTimeFajer;
    QLabel *TimeLabelShrouq;
    QLabel *EnglishLabelTimeShrouq;
    QLabel *ArabicLabelTimeShrouq;
    QLabel *TimeLabelDhuhr;
    QLabel *EnglishLabelTimeDhuhr;
    QLabel *ArabicLabelTimeDhuhr;
    QLabel *TimeLabelAsr;
    QLabel *EnglishLabelTimeAsr;
    QLabel *ArabicLabelTimeAsr;
    QLabel *TimeLabelMagrib;
    QLabel *EnglishLabelTimeMagrib;
    QLabel *ArabicLabelTimemagrib;
    QLabel *TimeLabelIshaa;
    QLabel *EnglishLabelTimeIshaa;
    QLabel *ArabicLabelTimeIshaa;
    QLabel *TabHadith;
    QLabel *PopMessageBackground;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1204, 684);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setCursor(QCursor(Qt::PointingHandCursor));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QStringLiteral("QMainWindow{border-image: url(./home/pi/Documents/build-datebase-Qt_5_7_1_in_PATH_qt5_temporary-Debug/New/Background2.jpg) 0 0 0 0 stretch stretch;border-width: 0px}"));
        MainWindow->setDocumentMode(false);
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 660, 41, 21));
        pushButton->setStyleSheet(QStringLiteral(""));
        GregorianDate = new QLabel(centralWidget);
        GregorianDate->setObjectName(QStringLiteral("GregorianDate"));
        GregorianDate->setGeometry(QRect(170, 130, 301, 61));
        GregorianDate->setStyleSheet(QStringLiteral(""));
        GregorianDate->setAlignment(Qt::AlignCenter);
        ClockLabel = new QLabel(centralWidget);
        ClockLabel->setObjectName(QStringLiteral("ClockLabel"));
        ClockLabel->setGeometry(QRect(190, 10, 341, 121));
        QFont font;
        font.setFamily(QStringLiteral("Al-Jazeera-Arabic"));
        font.setPointSize(85);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        ClockLabel->setFont(font);
        ClockLabel->setStyleSheet(QStringLiteral(""));
        HijriDate = new QLabel(centralWidget);
        HijriDate->setObjectName(QStringLiteral("HijriDate"));
        HijriDate->setGeometry(QRect(150, 180, 361, 61));
        HijriDate->setLayoutDirection(Qt::LeftToRight);
        HijriDate->setStyleSheet(QStringLiteral(""));
        HijriDate->setTextFormat(Qt::AutoText);
        HijriDate->setAlignment(Qt::AlignCenter);
        ArabicHadithLabel = new DynamicFontSizeLabel(centralWidget);
        ArabicHadithLabel->setObjectName(QStringLiteral("ArabicHadithLabel"));
        ArabicHadithLabel->setGeometry(QRect(100, 440, 881, 101));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(ArabicHadithLabel->sizePolicy().hasHeightForWidth());
        ArabicHadithLabel->setSizePolicy(sizePolicy1);
        ArabicHadithLabel->setMinimumSize(QSize(400, 50));
        QFont font1;
        font1.setFamily(QStringLiteral("Al-Jazeera-Arabic"));
        ArabicHadithLabel->setFont(font1);
        ArabicHadithLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        ArabicHadithLabel->setFrameShape(QFrame::NoFrame);
        ArabicHadithLabel->setTextFormat(Qt::PlainText);
        ArabicHadithLabel->setWordWrap(true);
        EnglishHadithLabel = new DynamicFontSizeLabel(centralWidget);
        EnglishHadithLabel->setObjectName(QStringLiteral("EnglishHadithLabel"));
        EnglishHadithLabel->setGeometry(QRect(290, 530, 871, 91));
        sizePolicy1.setHeightForWidth(EnglishHadithLabel->sizePolicy().hasHeightForWidth());
        EnglishHadithLabel->setSizePolicy(sizePolicy1);
        EnglishHadithLabel->setMinimumSize(QSize(400, 50));
        EnglishHadithLabel->setFont(font1);
        EnglishHadithLabel->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        EnglishHadithLabel->setFrameShape(QFrame::NoFrame);
        EnglishHadithLabel->setTextFormat(Qt::PlainText);
        EnglishHadithLabel->setWordWrap(true);
        AqamaLabelCounter = new QLabel(centralWidget);
        AqamaLabelCounter->setObjectName(QStringLiteral("AqamaLabelCounter"));
        AqamaLabelCounter->setGeometry(QRect(810, 260, 361, 221));
        AqamaLabelCounter->setStyleSheet(QStringLiteral("font: 75 125pt \"Al-Jazeera-Arabic\";"));
        AqamaLabelCounter->setAlignment(Qt::AlignCenter);
        event = new DynamicFontSizeLabel(centralWidget);
        event->setObjectName(QStringLiteral("event"));
        event->setGeometry(QRect(70, 320, 501, 111));
        event->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        TimeLabelFajer = new QLabel(centralWidget);
        TimeLabelFajer->setObjectName(QStringLiteral("TimeLabelFajer"));
        TimeLabelFajer->setGeometry(QRect(230, 340, 67, 21));
        EnglishLabelTimeFajer = new QLabel(centralWidget);
        EnglishLabelTimeFajer->setObjectName(QStringLiteral("EnglishLabelTimeFajer"));
        EnglishLabelTimeFajer->setGeometry(QRect(220, 380, 67, 21));
        ArabicLabelTimeFajer = new QLabel(centralWidget);
        ArabicLabelTimeFajer->setObjectName(QStringLiteral("ArabicLabelTimeFajer"));
        ArabicLabelTimeFajer->setGeometry(QRect(220, 430, 67, 21));
        TimeLabelShrouq = new QLabel(centralWidget);
        TimeLabelShrouq->setObjectName(QStringLiteral("TimeLabelShrouq"));
        TimeLabelShrouq->setGeometry(QRect(360, 470, 67, 21));
        EnglishLabelTimeShrouq = new QLabel(centralWidget);
        EnglishLabelTimeShrouq->setObjectName(QStringLiteral("EnglishLabelTimeShrouq"));
        EnglishLabelTimeShrouq->setGeometry(QRect(360, 420, 67, 21));
        ArabicLabelTimeShrouq = new QLabel(centralWidget);
        ArabicLabelTimeShrouq->setObjectName(QStringLiteral("ArabicLabelTimeShrouq"));
        ArabicLabelTimeShrouq->setGeometry(QRect(370, 370, 67, 21));
        TimeLabelDhuhr = new QLabel(centralWidget);
        TimeLabelDhuhr->setObjectName(QStringLiteral("TimeLabelDhuhr"));
        TimeLabelDhuhr->setGeometry(QRect(360, 320, 67, 21));
        EnglishLabelTimeDhuhr = new QLabel(centralWidget);
        EnglishLabelTimeDhuhr->setObjectName(QStringLiteral("EnglishLabelTimeDhuhr"));
        EnglishLabelTimeDhuhr->setGeometry(QRect(360, 280, 67, 21));
        ArabicLabelTimeDhuhr = new QLabel(centralWidget);
        ArabicLabelTimeDhuhr->setObjectName(QStringLiteral("ArabicLabelTimeDhuhr"));
        ArabicLabelTimeDhuhr->setGeometry(QRect(230, 290, 67, 21));
        TimeLabelAsr = new QLabel(centralWidget);
        TimeLabelAsr->setObjectName(QStringLiteral("TimeLabelAsr"));
        TimeLabelAsr->setGeometry(QRect(80, 290, 67, 21));
        EnglishLabelTimeAsr = new QLabel(centralWidget);
        EnglishLabelTimeAsr->setObjectName(QStringLiteral("EnglishLabelTimeAsr"));
        EnglishLabelTimeAsr->setGeometry(QRect(80, 320, 67, 21));
        ArabicLabelTimeAsr = new QLabel(centralWidget);
        ArabicLabelTimeAsr->setObjectName(QStringLiteral("ArabicLabelTimeAsr"));
        ArabicLabelTimeAsr->setGeometry(QRect(70, 370, 67, 21));
        TimeLabelMagrib = new QLabel(centralWidget);
        TimeLabelMagrib->setObjectName(QStringLiteral("TimeLabelMagrib"));
        TimeLabelMagrib->setGeometry(QRect(70, 410, 67, 21));
        EnglishLabelTimeMagrib = new QLabel(centralWidget);
        EnglishLabelTimeMagrib->setObjectName(QStringLiteral("EnglishLabelTimeMagrib"));
        EnglishLabelTimeMagrib->setGeometry(QRect(70, 450, 67, 21));
        ArabicLabelTimemagrib = new QLabel(centralWidget);
        ArabicLabelTimemagrib->setObjectName(QStringLiteral("ArabicLabelTimemagrib"));
        ArabicLabelTimemagrib->setGeometry(QRect(70, 490, 67, 21));
        TimeLabelIshaa = new QLabel(centralWidget);
        TimeLabelIshaa->setObjectName(QStringLiteral("TimeLabelIshaa"));
        TimeLabelIshaa->setGeometry(QRect(470, 290, 67, 21));
        EnglishLabelTimeIshaa = new QLabel(centralWidget);
        EnglishLabelTimeIshaa->setObjectName(QStringLiteral("EnglishLabelTimeIshaa"));
        EnglishLabelTimeIshaa->setGeometry(QRect(470, 330, 67, 21));
        ArabicLabelTimeIshaa = new QLabel(centralWidget);
        ArabicLabelTimeIshaa->setObjectName(QStringLiteral("ArabicLabelTimeIshaa"));
        ArabicLabelTimeIshaa->setGeometry(QRect(460, 370, 67, 21));
        TabHadith = new QLabel(centralWidget);
        TabHadith->setObjectName(QStringLiteral("TabHadith"));
        TabHadith->setGeometry(QRect(530, 640, 67, 21));
        PopMessageBackground = new QLabel(centralWidget);
        PopMessageBackground->setObjectName(QStringLiteral("PopMessageBackground"));
        PopMessageBackground->setGeometry(QRect(260, 620, 67, 21));
        MainWindow->setCentralWidget(centralWidget);
        ClockLabel->raise();
        ArabicHadithLabel->raise();
        pushButton->raise();
        AqamaLabelCounter->raise();
        GregorianDate->raise();
        HijriDate->raise();
        event->raise();
        EnglishHadithLabel->raise();
        TimeLabelFajer->raise();
        EnglishLabelTimeFajer->raise();
        ArabicLabelTimeFajer->raise();
        TimeLabelShrouq->raise();
        EnglishLabelTimeShrouq->raise();
        ArabicLabelTimeShrouq->raise();
        TimeLabelDhuhr->raise();
        EnglishLabelTimeDhuhr->raise();
        ArabicLabelTimeDhuhr->raise();
        TimeLabelAsr->raise();
        EnglishLabelTimeAsr->raise();
        ArabicLabelTimeAsr->raise();
        TimeLabelMagrib->raise();
        EnglishLabelTimeMagrib->raise();
        ArabicLabelTimemagrib->raise();
        TimeLabelIshaa->raise();
        EnglishLabelTimeIshaa->raise();
        ArabicLabelTimeIshaa->raise();
        TabHadith->raise();
        PopMessageBackground->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        GregorianDate->setText(QApplication::translate("MainWindow", "Date", Q_NULLPTR));
        ClockLabel->setText(QApplication::translate("MainWindow", "00:00", Q_NULLPTR));
        HijriDate->setText(QApplication::translate("MainWindow", "\330\247\331\204\330\252\330\247\330\261\331\212\330\256 \330\247\331\204\331\207\330\254\330\261\331\212 ", Q_NULLPTR));
        ArabicHadithLabel->setText(QApplication::translate("MainWindow", "\330\255\330\257\331\212\330\253 \330\247\331\204\331\212\331\210\331\205 \330\250\330\247\331\204\331\204\330\272\330\251 \330\247\331\204\330\271\330\261\330\250\331\212\330\251 jvp[dlkjskldjldskjklfsjf", Q_NULLPTR));
        EnglishHadithLabel->setText(QApplication::translate("MainWindow", "Hadith Englishklsfkljsfnjkskdfjkjf", Q_NULLPTR));
        AqamaLabelCounter->setText(QApplication::translate("MainWindow", "00", Q_NULLPTR));
        event->setText(QString());
        TimeLabelFajer->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        EnglishLabelTimeFajer->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        ArabicLabelTimeFajer->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        TimeLabelShrouq->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        EnglishLabelTimeShrouq->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        ArabicLabelTimeShrouq->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        TimeLabelDhuhr->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        EnglishLabelTimeDhuhr->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        ArabicLabelTimeDhuhr->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        TimeLabelAsr->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        EnglishLabelTimeAsr->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        ArabicLabelTimeAsr->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        TimeLabelMagrib->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        EnglishLabelTimeMagrib->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        ArabicLabelTimemagrib->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        TimeLabelIshaa->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        EnglishLabelTimeIshaa->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        ArabicLabelTimeIshaa->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        TabHadith->setText(QApplication::translate("MainWindow", "Hallo World", Q_NULLPTR));
        PopMessageBackground->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
