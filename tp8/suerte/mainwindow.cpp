#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdlib.h>
#include <time.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_5->setText(QString::number(this->puntaje));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (!estaFuncionando) {
        srand(time(NULL));
        this->nro = (rand() % 5);
        this->nro1 = (rand() % 5);
        this->nro2 = (rand() % 5);

        t1 = new QTimer(this);
        connect(t1, SIGNAL(timeout()), this, SLOT(l1()));
        t1->start(50*this->nro);

        t2 = new QTimer(this);
        connect(t2, SIGNAL(timeout()), this, SLOT(l2()));
        t2->start(50*this->nro1);

        t3 = new QTimer(this);
        connect(t3, SIGNAL(timeout()), this, SLOT(l3()));
        t3->start(100*this->nro2);

        estaFuncionando = true;
    }

}

void MainWindow::l1(){
    nro--;
    if (nro == -1) nro = 5;
    ui->label->setText(QString::number(nro));
    this->t1->setInterval(this->t1->interval() + 100);
    if (this->t1->interval() > 800) {
        this->t1->stop();
        this->verificar();
    }
}

void MainWindow::l2(){
    nro1++;
    if (nro1 == 6) nro1 = 0;
    ui->label_2->setText(QString::number(nro1));
    this->t2->setInterval(this->t2->interval() + 100);
    if (this->t2->interval() > 900) {
        this->t2->stop();
        this->verificar();
    }
}

void MainWindow::l3(){
    nro2--;
    if (nro2 == -1) nro2 = 5;
    ui->label_3->setText(QString::number(nro2));
    this->t3->setInterval(this->t3->interval() + 100);
    if (this->t3->interval() > 1000) {
        this->t3->stop();
        this->verificar();
    }
}

void MainWindow::verificar(){
    if ((!this->t1->isActive()) &&
            (!this->t2->isActive())&&
            (!this->t3->isActive())) {
        if ((nro == nro1) && (nro == nro2)) {
            this->puntaje++;
        } else {
            this->puntaje--;
        }
        ui->label_5->setText(QString::number(this->puntaje));
        estaFuncionando = false;
    }
}
