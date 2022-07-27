#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDataStream io;
    QFile file;
    file.setFileName("/home/marcustoledo/Curso QT/QDataStream/texto.txt"); // QDataStream no path buga na hora de buildar.
    file.open(QIODevice::WriteOnly);
    io.setDevice(&file);
    io << 5;

    file.flush();
    file.close();
    qDebug() << "Sei la";


    return a.exec();
}
