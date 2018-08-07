#include "widget.h"
#include "ui_widget.h"
#include "server.h"

#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &Widget::showTime);
    connect(ui->startBtn, SIGNAL(clicked(bool)), this, SLOT(playing()));

	Server* server = new Server();
	connect(server, &Server::good, this, &Widget::good);
	connect(server, &Server::miss, this, &Widget::miss);
	connect(server, &Server::fail, this, &Widget::fail);
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

void Widget::good()
{
	tempScore++;
}

void Widget::miss()
{
	if (isYellowTurn) {
		qint32 temp = ui->lcdYellowScore->value();
		ui->lcdYellowScore->display(temp + tempScore);
	}
	else {
		qint32 temp = ui->lcdWhiteScore->value();
		ui->lcdWhiteScore->display(temp + tempScore);
	}
	isYellowTurn = !isYellowTurn;
	tempScore = 0;
}

void Widget::fail()
{
	if (isYellowTurn) {
		qint32 temp = ui->lcdYellowScore->value();
		ui->lcdYellowScore->display(temp + tempScore - 1);
	}
	else {
		qint32 temp = ui->lcdWhiteScore->value();
		ui->lcdWhiteScore->display(temp + tempScore - 1);
	}
	isYellowTurn = !isYellowTurn;
	tempScore = 0;
}
