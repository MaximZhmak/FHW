#include <QCoreApplication>
#include <QThread>
#include <QProcess>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;


    QThread thread;


    client.moveToThread(&thread);
    client.connect(&thread, SIGNAL(started()), &client, SLOT(onThreadStarted()));
    thread.start();




    return a.exec();
}
