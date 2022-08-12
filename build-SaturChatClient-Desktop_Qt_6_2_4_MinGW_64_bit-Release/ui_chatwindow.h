/********************************************************************************
** Form generated from reading UI file 'chatwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWINDOW_H
#define UI_CHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *msgLineEdit;
    QPushButton *sendMsgButton;
    QTextBrowser *chatBrowser;
    QPushButton *returnButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ChatWindow)
    {
        if (ChatWindow->objectName().isEmpty())
            ChatWindow->setObjectName(QString::fromUtf8("ChatWindow"));
        ChatWindow->resize(471, 525);
        centralwidget = new QWidget(ChatWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        msgLineEdit = new QLineEdit(centralwidget);
        msgLineEdit->setObjectName(QString::fromUtf8("msgLineEdit"));

        gridLayout->addWidget(msgLineEdit, 2, 0, 1, 1);

        sendMsgButton = new QPushButton(centralwidget);
        sendMsgButton->setObjectName(QString::fromUtf8("sendMsgButton"));

        gridLayout->addWidget(sendMsgButton, 2, 1, 1, 1);

        chatBrowser = new QTextBrowser(centralwidget);
        chatBrowser->setObjectName(QString::fromUtf8("chatBrowser"));

        gridLayout->addWidget(chatBrowser, 1, 0, 1, 2);

        returnButton = new QPushButton(centralwidget);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));

        gridLayout->addWidget(returnButton, 0, 0, 1, 2);

        ChatWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ChatWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 471, 25));
        ChatWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ChatWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ChatWindow->setStatusBar(statusbar);

        retranslateUi(ChatWindow);

        QMetaObject::connectSlotsByName(ChatWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ChatWindow)
    {
        ChatWindow->setWindowTitle(QCoreApplication::translate("ChatWindow", "SaturChat", nullptr));
        sendMsgButton->setText(QCoreApplication::translate("ChatWindow", "->", nullptr));
        returnButton->setText(QCoreApplication::translate("ChatWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatWindow: public Ui_ChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWINDOW_H
