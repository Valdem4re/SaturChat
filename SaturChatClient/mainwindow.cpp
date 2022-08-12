#include "mainwindow.h"
#include "ui_mainwindow.h"

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


void MainWindow::on_pushButton_clicked()
{
    Chat = new ChatWindow(this, ui->addressLineEdit->text(), ui->nameTextEdit->text());
    connect(Chat, &ChatWindow::return_to_main_window, this, &MainWindow::show);
    this->hide();
    Chat->show();

}

