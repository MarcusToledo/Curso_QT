#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QVector>

QString msg {""};
QString m1,m2,m3;

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
    bool cb1,cb2,cb3;

    cb1 = ui->checkBox->isChecked();
    cb2 = ui->checkBox_2->isChecked();
    cb3 = ui->checkBox_3->isChecked();

    if (cb1) {
        msg+="Cb1 marcado";
    }
    if (cb2) {
        msg+=" Cb2 marcado";
    }
    if (cb3) {
        msg+=" Cb3 marcado";
    }
    QMessageBox::information(this,"Checkboxes", msg);
}

void MainWindow::on_pushButton_2_clicked()
{
    QVector<bool> cb(3);

    cb[0] = ui->checkBox->isChecked();
    cb[1] = ui->checkBox_2->isChecked();
    cb[2] = ui->checkBox_3->isChecked();
    msg = "";
    for (int i = 0; i < 3;i++) {
        if(cb[i]){
            msg+= "CB" + QString::number(i + 1) + "marcado ";
        }
    }
    QMessageBox::information(this,"Checkboxes", msg);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    msg.clear();
    if(arg1){
        m1 = "CB1 Marcado";
    }else {
        m1.clear();
    }
}
void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    msg.clear();
    if(arg1){
        m2 = " CB2 Marcado";
    }else {
        m2.clear();
    }
}

void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    msg.clear();
    if(arg1){
        m3 = " CB3 Marcado";
    }else {
        m3.clear();
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    msg= m1 + m2 + m3;
    QMessageBox::information(this,"Checkboxes", msg);
}
