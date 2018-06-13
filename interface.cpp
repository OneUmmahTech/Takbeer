#include "interface.h"
#include<QLabel>
#include<QRect>
#include<ui_mainwindow.h>
interface::interface()
{

}
void interface::interfacelayout(int xPosition, int yPosition){

    QLabel EnglishLabelShrouq;
    QLabel EnglishLabelDhuhr;
    QLabel EnglishLabelAsr;
    QLabel EnglishLabelMagrib;
    QLabel EnglishLabelIshaa;

    QLabel *EnglishLabelFajer = new QLabel(this);
    EnglishLabelFajer->setObjectName("EnglishFajer");
    QRect rect= EnglishLabelFajer->geometry();
    rect.setX(500);
    rect.setY(500);
    rect.setWidth(100);
    rect.setHeight(100);
    EnglishLabelFajer->setGeometry(rect);
    EnglishLabelFajer->setText("Fajer Ibrahim Al Naser");
    EnglishLabelFajer->show();

    EnglishLabelShrouq.setText("Shrouq");
    EnglishLabelDhuhr.setText("Dhuhr");
    EnglishLabelAsr.setText("Asr");
    EnglishLabelMagrib.setText("Magrib");
    EnglishLabelIshaa.setText("Ishaa");

}
