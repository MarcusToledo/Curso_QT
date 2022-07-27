#include <QCoreApplication>
#include <QDebug>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDate date(2022,07,27);
    QTime time(16,17,00);

    QDateTime clock(date,time);

    qDebug() << clock;

    qDebug() << QDateTime::currentDateTime();

    return a.exec();
}
