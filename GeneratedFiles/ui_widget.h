/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *startBtn;
    QLCDNumber *lcdYellowScore;
    QLCDNumber *lcdWhiteScore;
    QGraphicsView *graphicsView;
    QGraphicsView *graphicsView_2;
    QLCDNumber *lcdTimer;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1308, 684);
        startBtn = new QPushButton(Widget);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setGeometry(QRect(960, 20, 161, 101));
        QFont font;
        font.setFamily(QStringLiteral("Agency FB"));
        font.setPointSize(36);
        font.setBold(true);
        font.setWeight(75);
        startBtn->setFont(font);
        lcdYellowScore = new QLCDNumber(Widget);
        lcdYellowScore->setObjectName(QStringLiteral("lcdYellowScore"));
        lcdYellowScore->setGeometry(QRect(230, 140, 301, 261));
        lcdYellowScore->setSmallDecimalPoint(false);
        lcdYellowScore->setDigitCount(2);
        lcdYellowScore->setSegmentStyle(QLCDNumber::Flat);
        lcdYellowScore->setProperty("value", QVariant(0));
        lcdWhiteScore = new QLCDNumber(Widget);
        lcdWhiteScore->setObjectName(QStringLiteral("lcdWhiteScore"));
        lcdWhiteScore->setGeometry(QRect(230, 410, 301, 261));
        lcdWhiteScore->setSmallDecimalPoint(false);
        lcdWhiteScore->setDigitCount(2);
        lcdWhiteScore->setSegmentStyle(QLCDNumber::Flat);
        lcdWhiteScore->setProperty("value", QVariant(0));
        graphicsView = new QGraphicsView(Widget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(930, 190, 191, 171));
        graphicsView_2 = new QGraphicsView(Widget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(930, 460, 191, 171));
        lcdTimer = new QLCDNumber(Widget);
        lcdTimer->setObjectName(QStringLiteral("lcdTimer"));
        lcdTimer->setGeometry(QRect(540, 20, 201, 111));
        lcdTimer->setDigitCount(3);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        startBtn->setText(QApplication::translate("Widget", "START", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
