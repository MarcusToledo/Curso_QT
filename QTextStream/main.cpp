#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextStream io; // Input e outputQDat
    QFile file;
    file.setFileName("/home/marcustoledo/Curso QT/QTextStream/teste.txt");
    file.open(QIODevice::ReadWrite | QIODevice::Text);

    if(!file.isOpen()){
        qDebug() << "Erro: arquivo não aberto";
        return 1;
    }

    io.setDevice(&file);
    io << "Alguma coisa";

    file.flush();
    file.close();
    return a.exec();
}
