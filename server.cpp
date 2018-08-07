#include "server.h"
#include "scoretype.h"

#include <QDebug>
#include <QTcpSocket>

Server::Server(QObject *parent)
	: QObject(parent)
{
	tcpServer = new QTcpServer(this);
	connect(tcpServer, &QTcpServer::newConnection, this, &Server::onConnect);
	if (tcpServer->listen(QHostAddress::Any, 8888)) {
		qDebug() << "Listening...";
	}
}

Server::~Server()
{
	socket->close();
	delete socket;
}

void Server::onConnect()
{
	qDebug() << "connected";

	socket = tcpServer->nextPendingConnection();
	connect(socket, &QTcpSocket::readyRead, this, &Server::onMessageComing);
	socket->write("hello");
}

void Server::onMessageComing()
{
	QString request = socket->readAll();
	if (request.contains(QString::number(static_cast<qint32>(ScoreType::good)))) {
		emit good();
	}
	else if (request.contains(QString::number(static_cast<qint32>(ScoreType::miss)))) {
		emit miss();
	}
	else if (request.contains(QString::number(static_cast<qint32>(ScoreType::fail)))) {
		emit fail();
	}

	const char* response = "I got it!";
	

	qDebug() << socket->write(response);
}
