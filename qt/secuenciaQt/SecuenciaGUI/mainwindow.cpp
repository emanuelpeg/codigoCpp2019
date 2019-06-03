#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "juego.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //construir juego.
    this->juego = Juego();
    this->juego.regenerar();
    this->cargarLabels();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cargarLabels(){
    this->ui->label_2->setText(QString::number(this->juego.getValor0()));
    this->ui->label->setText(QString::number(this->juego.getValor1()));
    this->ui->label_3->setText(QString::number(this->juego.getValor3()));
    this->ui->spinBox->setValue(0);
    this->ui->lcdNumber->display(this->juego.getPuntos());

}

void MainWindow::on_pushButton_clicked()
{
    if(this->juego.validar(this->ui->spinBox->value())){
        QMessageBox::about(
                this,
                tr("Ganaste!!"),
                QString::number(this->juego.getPuntos()) );
    } else {
        QMessageBox::about(
                this,
                tr("Perdiste!!"),
                QString::number(this->juego.getPuntos()) );
    }
    this->cargarLabels();
}
