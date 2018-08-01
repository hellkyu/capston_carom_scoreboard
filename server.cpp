#include "server.h"

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
	/*
	const int MaxLength = 1024;
	char buffer[MaxLength + 1];

	qint64 byteCount = socket->read(buffer, MaxLength);
	buffer[byteCount] = 0;
	*/

	qDebug() << socket->readAll();

	const char* response = "working working!";

	qDebug() << socket->write(response);
}
