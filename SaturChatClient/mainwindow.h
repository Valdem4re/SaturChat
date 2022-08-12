#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>

const int PORT = 5454;

struct Client{
    QString address;
    QString userName;
    QTcpSocket* socket;
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    QByteArray Data;
    quint16 blockSize;
    Client* userClient;

    void sendToServerMsg(QString str);

    void sendToServerUserName(Client);

public slots:
    void on_pushButton_clicked();

    void readyRead();

private slots:
    void on_returnButton_clicked();

    void on_sendMsgButton_clicked();

    void on_msgLineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
