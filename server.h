#pragma once

#include <QObject>
#include <QTcpServer>

class Server : public QObject
{
	Q_OBJECT

private slots:
	void onConnect();
	void onMessageComing();
public:
	Server(QObject *parent = 0);
	~Server();

	QTcpServer *tcpServer = nullptr;
	QTcpSocket *socket = nullptr;
};
