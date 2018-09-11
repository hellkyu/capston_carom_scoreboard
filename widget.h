#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>

class QTimer;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;
	qint32 clockCnt = 0;
	qint32 tempScore = 0;
	bool isPlaying = false;
	bool isYellowTurn = true;
	QTimer *timer;

	// ball labels
	QLabel* yellow_off_label = new QLabel();
	QLabel* yellow_on_label = new QLabel();
	QLabel* white_off_label = new QLabel();
	QLabel* white_on_label = new QLabel();

private slots:
    void showTime();
    void playing();
	void good();
	void fail();
};

#endif // WIDGET_H
