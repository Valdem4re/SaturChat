#include "saturchatserver.h"

SaturChatServer::SaturChatServer()
{
    if(!this->listen(QHostAddress::Any, PORT)){
        qDebug() << tr("The server has not started");
    }
    else{
        qDebug() << tr("The server has started with port %1").arg(PORT);
    }
    blockSize = 0;
}

SaturChatServer::~SaturChatServer()
{

}

void SaturChatServer::sendToClient(QString str)
{
    Data.clear();
    QDataStream output(&Data, QIODevice::WriteOnly);
    output << quint16(0) << QTime::currentTime() << str;
    output.device()->seek(0);
    output << quint16(Data.size() - sizeof(quint16));
    for(auto client : Clients){
        client->socket->write(Data);
    }
}

void SaturChatServer::incomingConnection(qintptr socketDescr)
{
    userClient = new Client;
    userClient->socket = new QTcpSocket;
    userClient->socket->setSocketDescriptor(socketDescr);

    Clients.insert(userClient);
    qDebug() << tr("Client with descriptor %1 has been connected").arg(socketDescr);

    connect(userClient->socket, &QTcpSocket::readyRead, this, &SaturChatServer::slotReadyRead);
    connect(userClient->socket, &QTcpSocket::disconnected, userClient->socket, &QTcpSocket::deleteLater);
}

void SaturChatServer::slotReadyRead()
{
    //запсиь сокета, с которого пришел запрос
    userClient->socket = (QTcpSocket*)sender();

    QDataStream input (userClient->socket);
    if(input.status() == QDataStream::Ok){
        qDebug() << "Reading...";
        while(true){

            if(blockSize == 0){
                qDebug() << "block size = 0";
                if(userClient->socket->bytesAvailable() < 2){
                    qDebug() << "Data < 2, break";
                    break;
                }
                input >> blockSize;
                qDebug() << "block size = " << blockSize;
            }
            if(userClient->socket->bytesAvailable() < blockSize){
                qDebug() <<"The data did not come in full";
                break;
            }
            QString msg;
            QString userName;
            QTime time;
            input >> time >> msg;
            blockSize = 0;
            qDebug() << msg;
            sendToClient(msg);
            break;
        }

    }
    else{
        qDebug() << "DataStream error";
    }
}

