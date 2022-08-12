#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendToServerMsg(QString str)
{
    Data.clear();
    QDataStream output(&Data, QIODevice::WriteOnly);
    output << quint16(0) << QTime::currentTime() << str;
    output.device()->seek(0);
    output << quint16(Data.size() - sizeof(quint16));
    userClient->socket->write(Data);
    ui->msgLineEdit->clear();
}

//void MainWindow::sendToServerUserName(Client userClient)
//{
//    Data.clear();
//    QDataStream output(&Data, QIODevice::WriteOnly);
//    output << quint16(0) << QTime::currentTime() << userClient.userName;
//}


void MainWindow::on_pushButton_clicked()
{
    blockSize = 0;


    userClient = new Client;

    userClient->userName = ui->nameTextEdit->text();
    userClient->address = ui->addressLineEdit->text();
    userClient->socket = new QTcpSocket(this);

    connect(userClient->socket, &QTcpSocket::readyRead, this, &MainWindow::readyRead);
    connect(userClient->socket, &QTcpSocket::disconnected, userClient->socket, &QTcpSocket::deleteLater);
    userClient->socket->connectToHost(userClient->address, PORT);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::readyRead()
{
    QDataStream input (userClient->socket);
    if(input.status() == QDataStream::Ok){

        while(true){

            if(blockSize == 0){
                if(userClient->socket->bytesAvailable() < 2)
                    break;
                input >> blockSize;
            }
            if(userClient->socket->bytesAvailable() < blockSize)
                break;
            QString msg;
            QTime time;
            QString str_time = time.toString();
            input >> time >> msg;
            blockSize = 0;
            ui->chatBrowser->append(userClient->userName + " (" + time.toString() + ") \n" + msg);
        }
    }
    else{
        ui->chatBrowser->append("Reading error");
    }
}


void MainWindow::on_returnButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    delete userClient->socket;

}

void MainWindow::on_sendMsgButton_clicked()
{
    sendToServerMsg(ui->msgLineEdit->text());
}


void MainWindow::on_msgLineEdit_returnPressed()
{
    sendToServerMsg(ui->msgLineEdit->text());
}

