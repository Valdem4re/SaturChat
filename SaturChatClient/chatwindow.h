#ifndef CHATWINDOW_H
#define CHATWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTime>

const int PORT = 5454;

namespace Ui {
class ChatWindow;
}

class ChatWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChatWindow(QWidget *parent = nullptr);
    explicit ChatWindow(QWidget *parent = nullptr, QString address = nullptr, QString name = nullptr);
    ~ChatWindow();

private:
    Ui::ChatWindow *ui;
    QString Address;
    QByteArray Data;
    QTcpSocket* Socket;
    quint16 blockSize;
    QString userName;

    void sendToServer(QString str);

signals:
    void return_to_main_window();

private slots:
     void on_returnButton_clicked();

     void on_sendMsgButton_clicked();

     void on_msgLineEdit_returnPressed();

public slots:

    void readyRead();

};

#endif // CHATWINDOW_H
