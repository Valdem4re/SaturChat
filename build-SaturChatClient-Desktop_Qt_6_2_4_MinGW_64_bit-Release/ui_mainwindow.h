/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_5;
    QStackedWidget *stackedWidget;
    QWidget *connectPage;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *nameTextEdit;
    QPushButton *pushButton;
    QLineEdit *addressLineEdit;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QWidget *chatWindow;
    QGridLayout *gridLayout_3;
    QPushButton *returnButton;
    QTextBrowser *chatBrowser;
    QLineEdit *msgLineEdit;
    QPushButton *sendMsgButton;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(453, 250);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout_5 = new QGridLayout(centralwidget);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        connectPage = new QWidget();
        connectPage->setObjectName(QString::fromUtf8("connectPage"));
        gridLayout_4 = new QGridLayout(connectPage);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(connectPage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShape(QFrame::Panel);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        nameTextEdit = new QLineEdit(connectPage);
        nameTextEdit->setObjectName(QString::fromUtf8("nameTextEdit"));
        nameTextEdit->setMaxLength(32767);
        nameTextEdit->setFrame(true);
        nameTextEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(nameTextEdit, 0, 1, 1, 1);

        pushButton = new QPushButton(connectPage);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        addressLineEdit = new QLineEdit(connectPage);
        addressLineEdit->setObjectName(QString::fromUtf8("addressLineEdit"));
        addressLineEdit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(addressLineEdit, 1, 1, 1, 1);


        gridLayout_4->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer = new QSpacerItem(186, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 0, 1, 1);

        label_2 = new QLabel(connectPage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_2, 0, 1, 2, 1);

        verticalSpacer = new QSpacerItem(20, 105, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer, 1, 0, 1, 1);

        stackedWidget->addWidget(connectPage);
        chatWindow = new QWidget();
        chatWindow->setObjectName(QString::fromUtf8("chatWindow"));
        gridLayout_3 = new QGridLayout(chatWindow);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        returnButton = new QPushButton(chatWindow);
        returnButton->setObjectName(QString::fromUtf8("returnButton"));

        gridLayout_3->addWidget(returnButton, 0, 0, 1, 2);

        chatBrowser = new QTextBrowser(chatWindow);
        chatBrowser->setObjectName(QString::fromUtf8("chatBrowser"));

        gridLayout_3->addWidget(chatBrowser, 1, 0, 1, 2);

        msgLineEdit = new QLineEdit(chatWindow);
        msgLineEdit->setObjectName(QString::fromUtf8("msgLineEdit"));

        gridLayout_3->addWidget(msgLineEdit, 2, 0, 1, 1);

        sendMsgButton = new QPushButton(chatWindow);
        sendMsgButton->setObjectName(QString::fromUtf8("sendMsgButton"));

        gridLayout_3->addWidget(sendMsgButton, 2, 1, 1, 1);

        stackedWidget->addWidget(chatWindow);

        gridLayout_5->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "SaturChat - main", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "User name:", nullptr));
        nameTextEdit->setInputMask(QString());
        nameTextEdit->setText(QCoreApplication::translate("MainWindow", "user", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        addressLineEdit->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\302\251Valdemare | </span>alpha_build</p></body></html>", nullptr));
        returnButton->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        sendMsgButton->setText(QCoreApplication::translate("MainWindow", "->", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
