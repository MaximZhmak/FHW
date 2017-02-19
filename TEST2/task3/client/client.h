#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QThread>
#include <vector>
#include <QTimer>
#include <QTime>

class Client: public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject*parent=0, int packagesToSend=20000);
    ~Client();

    void Connect();

    size_t getAverageDelay()
    {
        size_t sumOfDelays=0;
        for (size_t i=0;i<m_delays.size();i++)
                sumOfDelays+=m_delays[i];

        return sumOfDelays/m_delays.size();
    }

signals:


public slots:
    void onConnected();
    void onDisconnected();

    void onReadyRead();
    void onThreadStarted();

private:
    bool m_connected;
    int m_count;
    std::vector<size_t> m_delays;
    QTcpSocket* m_socket;
    QTime m_start;
};

#endif // CLIENT_H
