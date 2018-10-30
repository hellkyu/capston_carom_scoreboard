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

	setStyleSheet("background-color: #262626");
	//setStyleSheet("background-color: #2626AD");
	
	QPalette p;
	// label color
	p.setColor(QPalette::WindowText, QColor(0xA4A9B3));
	ui->label->setPalette(p);
	ui->label_2->setPalette(p);

	// lcdTimer settings
	p.setColor(QPalette::WindowText, QColor(0xea3808));
	ui->lcdTimer->setPalette(p);
	ui->lcdTimer->setStyleSheet("border: 2px solid white; border-radius: 10px;");

	// lcdScore color
	p.setColor(QPalette::WindowText, QColor(0xffcc05));
	ui->lcdYellowScore->setPalette(p);
	ui->lcdYellowScore->setStyleSheet("border: 2px solid white; border-radius: 10px;");

	p.setColor(QPalette::WindowText, QColor(0xffffff));
	ui->lcdWhiteScore->setPalette(p);
	ui->lcdWhiteScore->setStyleSheet("border: 2px solid white; border-radius: 10px;");

	// pushbutton settings
	ui->startBtn->setStyleSheet("border: 2px solid white; border-radius: 10px; color: #ea3808;");

	// ball images init
	QImage ball_img;

	ball_img.load("images/yellow_off.png");
	yellow_off_label->setPixmap(QPixmap::fromImage(ball_img));
	ball_img.load("images/yellow_on.png");
	yellow_on_label->setPixmap(QPixmap::fromImage(ball_img));
	ball_img.load("images/white_off.png");
	white_off_label->setPixmap(QPixmap::fromImage(ball_img));
	ball_img.load("images/white_on.png");
	white_on_label->setPixmap(QPixmap::fromImage(ball_img));

	ui->gridLayout->addWidget(yellow_off_label, 2, 0, Qt::AlignCenter);
	ui->gridLayout->addWidget(yellow_on_label, 2, 0, Qt::AlignCenter);
	ui->gridLayout->addWidget(white_off_label, 2, 4, Qt::AlignCenter);
	ui->gridLayout->addWidget(white_on_label, 2, 4, Qt::AlignCenter);

	yellow_on_label->setVisible(false);
	white_on_label->setVisible(false);

    connect(timer, &QTimer::timeout, this, &Widget::showTime);
    connect(ui->startBtn, SIGNAL(clicked(bool)), this, SLOT(playing()));

	Server* server = new Server();
	connect(server, &Server::good, this, &Widget::good);
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
		
		yellow_on_label->setVisible(false);
		ui->lcdYellowScore->display(0);
		ui->lcdWhiteScore->display(0);
    } else {
        ui->startBtn->setText("STOP");
        clockCnt = 0;
        timer->start(1000);

		yellow_on_label->setVisible(true);
    }
    isPlaying = !isPlaying;
}

void Widget::good()
{
	if (isPlaying) {
		if (isYellowTurn) {
			qint32 temp = ui->lcdYellowScore->value();
			ui->lcdYellowScore->display(temp + 1);
		}
		else {
			qint32 temp = ui->lcdWhiteScore->value();
			ui->lcdWhiteScore->display(temp + 1);
		}
	}
}

void Widget::fail()
{

	if (isPlaying) {
		if (isYellowTurn) {
			yellow_on_label->setVisible(false);
			white_on_label->setVisible(true);
		}
		else {
			yellow_on_label->setVisible(true);
			white_on_label->setVisible(false);
		}
		isYellowTurn = !isYellowTurn;
	}
}