#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->juego.barajar();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::verificar(int i) {
    QString msg;
    switch (this->juego.verificar(i)) {
    case 0:
        msg = QString("Empate");
        break;
    case 1:
        msg = QString("Perdiste");
        break;
    case 2:
        msg = QString("Ganaste");
        break;
    }

    QMessageBox::about(
            this,
            msg,
            QString(this->juego.getEleStr()) );
    this->juego.barajar();

}

void MainWindow::on_toolButton_clicked()
{
    this->verificar(0);
}

void MainWindow::on_toolButton_2_clicked()
{
    this->verificar(1);
}

void MainWindow::on_toolButton_3_clicked()
{
    this->verificar(2);
}
