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
    qint32 clockCnt = 0;
    bool isPlaying = false;
    QTimer *timer;

    explicit Widget(QWidget *parent = 0);
    ~Widget();

private:
    Ui::Widget *ui;


private slots:
    void showTime();

    void playing();
};

#endif // WIDGET_H
