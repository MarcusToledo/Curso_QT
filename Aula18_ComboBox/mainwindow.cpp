#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    QString cursos[5] = {"C++","Qt","PHP","Unity","Javascript"};
//    QString icones[5] = {":/icons/icons/cpp.png",":/icons/icons/qt",":/icons/icons/php.png",":/icons/icons/unity",":/icons/icons/js"};
//    for(int i = 0; i < 5; i++){
//        ui->comboBox->addItem(QIcon(icones[i]), cursos[i]);
//    }

//    ui->comboBox->insertItem(3,"HTML"); // Insere em um index específico


    //Outro método para incluir valores na combo box atráves de uma lista

    QStringList cursos = {"C++","Qt","PHP","Unity","Javascript"};
    ui->comboBox->addItems(cursos);



//    ui->comboBox->addItem("C++");
//    ui->comboBox->addItem("Qt");
//    ui->comboBox->addItem("PHP");
//    ui->comboBox->addItem("Unity");
//    ui->comboBox->addItem("Javascript");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QMessageBox::about(this,"Cursos", ui->comboBox->currentText());
}
