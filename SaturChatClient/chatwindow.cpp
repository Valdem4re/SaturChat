#include "chatwindow.h"
#include "ui_chatwindow.h"

ChatWindow::ChatWindow(QWidget *parent, QString address, QString name) :
    QMainWindow(parent),
    ui(new Ui::ChatWindow)
{
    ui->setupUi(this);
    blockSize = 0;
    userName = name;
    Address = address;
    Socket = new QTcpSocket(this);
    connect(Socket, &QTcpSocket::readyRead, this, &ChatWindow::readyRead);
    connect(Socket, &QTcpSocket::disconnected, Socket, &QTcpSocket::deleteLater);
    Socket->connectToHost(Address, PORT);
}

ChatWindow::~ChatWindow()
{
    delete ui;
}

void ChatWindow::sendToServer(QString str)
{
    Data.clear();
    QDataStream output(&Data, QIODevice::WriteOnly);
    output << quint16(0) << QTime::currentTime() << str;
    output.device()->seek(0);
    output << quint16(Data.size() - sizeof(quint16));
    Socket->write(Data);
    ui->msgLineEdit->clear();
}


void ChatWindow::on_returnButton_clicked()
{
    emit return_to_main_window();
    this->close();
}

void ChatWindow::readyRead()
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

void ChatWindow::on_sendMsgButton_clicked()
{
    sendToServer(ui->msgLineEdit->text());
}


void ChatWindow::on_msgLineEdit_returnPressed()
{
    sendToServer(ui->msgLineEdit->text());
}

