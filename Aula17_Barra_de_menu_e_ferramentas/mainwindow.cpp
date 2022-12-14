#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "f_novo.h"
#include <QMessageBox>

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


void MainWindow::on_actionNovo_triggered()
{
    F_Novo form2;
    form2.exec();
}

void MainWindow::on_actionSalvar_triggered()
{
    QMessageBox::information(this,"Salvar", "Salvar");
}

void MainWindow::on_actionSair_triggered()
{
    //Close(); or
    QApplication::quit();
}
