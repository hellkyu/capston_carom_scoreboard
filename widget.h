#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

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

private slots:
    void showTime();
    void playing();
	void good();
	void miss();
	void fail();
};

#endif // WIDGET_H
