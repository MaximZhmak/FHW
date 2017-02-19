#include "client.h"
#include <QDateTime>
#include <QString>

Client::Client(QObject *parent, int packagesToSend)
    : QObject(parent)
    , m_socket(new QTcpSocket(this)),
      m_count(packagesToSend)
{
    connect(m_socket, SIGNAL(connected()),          this, SLOT(onConnected()));
    connect(m_socket, SIGNAL(disconnected()),       this, SLOT(onDisconnected()));
    connect(m_socket, SIGNAL(readyRead()),          this, SLOT(onReadyRead()));



}

Client::~Client()
{
    delete m_socket;
}

void Client:: onThreadStarted()
{
    Connect();
}

void Client::Connect()
{
    qDebug()<<"trying to connect to server...";
    m_socket->connectToHost("127.0.0.1", 9999);

}




void Client::onConnected()
{/* клиент соединился с сервером*/

    m_start = QTime::currentTime();
    QByteArray package;
    package.setNum(QDateTime::currentMSecsSinceEpoch());
    m_socket->write(package);
    qDebug() << "CLIENT: connected to server";

}

void Client::onDisconnected()
{
    /* клиент отсоединился от сервера*/


    qDebug() << "CLIENT: disconnected";
    QThread::currentThread()->exit();
}


void Client::onReadyRead()
{
    //пришли данные от сервера
    QByteArray data = m_socket->readAll();

    QString s_data(data);
    if (m_count)
    {
        if (s_data.contains("xxx"))   //метка,что сервер обработал пакет
        {
            s_data.remove(0,3);

            size_t delay = QDateTime::currentMSecsSinceEpoch() - s_data.toULongLong();
            m_delays.push_back(delay);

            QByteArray package;

            package.setNum(QDateTime::currentMSecsSinceEpoch());

            m_socket->write(package);
            m_count--;
        }

    }
    else
    {
        qDebug()<<"average round-trip latency: "<< getAverageDelay()<<"milliseconds";
        size_t duration = m_start.elapsed();
               qDebug()<<"packages sent "<<m_delays.size();
        qDebug()<<"duration "<<duration<<"milliseconds";
        qDebug()<<"throughput:  "<<m_delays.size()*1000/duration<<"packs/sec";

        m_socket->disconnect();
    }
}
