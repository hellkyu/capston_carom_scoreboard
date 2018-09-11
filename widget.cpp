#include "widget.h"
#include "ui_widget.h"
#include "server.h"

#include <QLabel>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);

	setStyleSheet("background-color: #262626");
	
	QPalette p;
	// lcdTimer settings
	p.setColor(QPalette::WindowText, QColor(0xea3808));
	ui->lcdTimer->setPalette(p);
	ui->lcdTimer->setStyleSheet("border: 2px solid white; border-radius: 10px;");

	// pushbutton settings
	ui->startBtn->setStyleSheet("border: 2px solid white; border-radius: 10px; color: #ea3808;");

	// ball images init
	QImage* yellow_off_img = new QImage();
	yellow_off_img->load("images/yellow_off.png");

	QLabel* yellow_off_label = new QLabel();
	yellow_off_label->setPixmap(QPixmap::fromImage(*yellow_off_img));

	ui->gridLayout->addWidget(yellow_off_label, 1, 2);
	//yellow_off_label->show();

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
