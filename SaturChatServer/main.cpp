#include <QCoreApplication>
#include "saturchatserver.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    SaturChatServer server;
    return a.exec();
}
