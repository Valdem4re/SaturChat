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

void MainWindow::sendToServer(QString str)
{
    Data.clear();
    QDataStream output(&Data, QIODevice::WriteOnly);
    output << quint16(0) << QTime::currentTime() << str;
    output.device()->seek(0);
    output << quint16(Data.size() - sizeof(quint16));
    Socket->write(Data);
    ui->msgLineEdit->clear();
}


void MainWindow::on_pushButton_clicked()
{
    blockSize = 0;
    userName = ui->nameTextEdit->text();
    Address = ui->addressLineEdit->text();

    Socket = new QTcpSocket(this);
    connect(Socket, &QTcpSocket::readyRead, this, &MainWindow::readyRead);
    connect(Socket, &QTcpSocket::disconnected, Socket, &QTcpSocket::deleteLater);
    Socket->connectToHost(Address, PORT);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::readyRead()
{
    QDataStream input (Socket);
    if(input.status() == QDataStream::Ok){

        while(true){

            if(blockSize == 0){
                if(Socket->bytesAvailable() < 2)
                    break;
                input >> blockSize;
            }
            if(Socket->bytesAvailable() < blockSize)
                break;
            QString msg;
            QTime time;
            QString str_time = time.toString();
            input >> time >> msg;
            blockSize = 0;
            ui->chatBrowser->append(userName + " (" + time.toString() + ") \n" + msg);
        }
    }
    else{
        ui->chatBrowser->append("Reading error");
    }
}


void MainWindow::on_returnButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    delete Socket;

}

void MainWindow::on_sendMsgButton_clicked()
{
    sendToServer(ui->msgLineEdit->text());
}


void MainWindow::on_msgLineEdit_returnPressed()
{
    sendToServer(ui->msgLineEdit->text());
}

