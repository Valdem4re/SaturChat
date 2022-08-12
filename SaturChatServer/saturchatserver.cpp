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
    //output << str;
    for(auto client : Clients){
        client->write(Data);
    }
}

void SaturChatServer::incomingConnection(qintptr socketDescr)
{
    Socket = new QTcpSocket;
    Socket->setSocketDescriptor(socketDescr);
    Clients.push_back(Socket);
    qDebug() << tr("Client with descriptor %1 has been connected").arg(socketDescr);

    connect(Socket, &QTcpSocket::readyRead, this, &SaturChatServer::slotReadyRead);
    connect(Socket, &QTcpSocket::disconnected, Socket, &QTcpSocket::deleteLater);
}

void SaturChatServer::slotReadyRead()
{
    //запсиь сокета, с которого пришел запрос
    Socket = (QTcpSocket*)sender();

    QDataStream input (Socket);
    if(input.status() == QDataStream::Ok){
        qDebug() << "Reading...";
        while(true){

            if(blockSize == 0){
                qDebug() << "block size = 0";
                if(Socket->bytesAvailable() < 2){
                    qDebug() << "Data < 2, break";
                    break;
                }
                input >> blockSize;
                qDebug() << "block size = " << blockSize;
            }
            if(Socket->bytesAvailable() < blockSize){
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

