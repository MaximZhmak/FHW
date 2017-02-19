#include "server.h"
#include <QTcpSocket>
#include <QThread>

Server::Server(QObject *parent)
    : QObject(parent)
    , m_server(new QTcpServer(this)){
}


Server::~Server()
{
    delete m_server;
}

void Server::start()
{
    connect(m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));

    if(!m_server->listen(QHostAddress::Any, 9999))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

void Server::onNewConnection()
{
    qDebug() << "Connected (server)!";

    QTcpSocket *socket = m_server->nextPendingConnection();

    connect(socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void Server::onBytesWritten(qint64 bytes)
{
    //получаем указатель на сокет
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());
    //закрываем сокет
    socket->close();
}


void Server::onReadyRead() //сервер готов читать сообщения клиента
{


    //получаем указатель на сокет
    QTcpSocket* socket = static_cast<QTcpSocket*>(sender());


    //читаем данные от клиента
    QByteArray data = socket->readAll();


    //метка,что сервер получил и обработал данные
    data.prepend("xxx");

    //отправляем данные клиенту
    socket->write(data);


}
