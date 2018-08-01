#include "widget.h"
#include "ui_widget.h"

#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &Widget::showTime);
    connect(ui->startBtn, SIGNAL(clicked(bool)), this, SLOT(playing()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::showTime()
{
    ui->lcdTimer->display(clockCnt);
    clockCnt++;
}

void Widget::playing()
{
    if(isPlaying){
        ui->startBtn->setText("START");
        timer->stop();
    } else {
        ui->startBtn->setText("STOP");
        clockCnt = 0;
        timer->start(1000);
    }
    isPlaying = !isPlaying;
}
