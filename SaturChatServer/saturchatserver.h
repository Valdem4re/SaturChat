#ifndef SATURCHATSERVER_H
#define SATURCHATSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QDebug>
#include <QTime>

const int PORT = 5454;

class SaturChatServer : public QTcpServer
{
    Q_OBJECT

public:
    SaturChatServer();
    virtual ~SaturChatServer();

    QTcpSocket* Socket;
private:

    QByteArray Data;
    QVector<QTcpSocket*> Clients;
    quint16 blockSize;

    void sendToClient(QString str);

public slots:

    //переопределение слота обработки подключений
    void incomingConnection(qintptr socetDescr);

    //метод обработки сообщений
    void slotReadyRead();

};

#endif // SATURCHATSERVER_H
