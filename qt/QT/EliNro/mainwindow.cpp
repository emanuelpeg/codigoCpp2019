#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include "time.h"
#include "math.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    QObject::connect(timer,SIGNAL(timeout()), this, SLOT(refrescar()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->cont = 0;
    srand(time(NULL));
    int r = rand() % 10;
    contIncremento = rand() % 100;
    timer->setInterval(5 * r);
    timer->start();
    this->ui->pushButton->setEnabled(false);
}

void MainWindow::refrescar() {
    this->cont++;
    this->ui->lcdNumber->display(this->cont);
    if (this->cont == 100) this->cont = 0;
    if (contIncremento < this->cont) {
        timer->setInterval(timer->interval()+(this->cont*2));
        if (timer->interval()>1000){
            timer->stop();
            this->ui->pushButton->setEnabled(true);
        }
    }

}
