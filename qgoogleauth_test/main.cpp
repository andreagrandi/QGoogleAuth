#include <QtCore/QCoreApplication>
#include <QDebug>
#include "qgoogleauth.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << QGoogleAuth::generatePin("yalbxtsy65brdxoy");
    return a.exec();
}
