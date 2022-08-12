#ifndef SATURCHATSERVER_H
#define SATURCHATSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVector>
#include <QDebug>
#include <QTime>
#include <QSet>

struct Client{
    QHostAddress address;
    QString userName;
    QTcpSocket* socket;
};

const int PORT = 5454;

class SaturChatServer : public QTcpServer
{
    Q_OBJECT

public:
    SaturChatServer();
    virtual ~SaturChatServer();

    Client* userClient;

private:

    QByteArray Data;

    quint16 blockSize;

    QSet<Client*> Clients;

    void sendToClient(QString str);

public slots:

    //переопределение слота обработки подключений
    void incomingConnection(qintptr socetDescr);

    //метод обработки сообщений
    void slotReadyRead();

};

#endif // SATURCHATSERVER_H
