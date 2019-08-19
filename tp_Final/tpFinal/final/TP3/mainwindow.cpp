#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <stdlib.h>
//#include <time.h>
#include <QLabel>
#include <QTimer>
#include <QMessageBox>
#include <QKeyEvent>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->inicializarMatriz();
}

void MainWindow::inicializarMatriz() {
    //En el ejemplo voy usando dim = 30
    this->dim = 30;

    this->labels = new QLabel**[dim];
    for (unsigned long i = 0; i < dim; i++) {
        this->labels[i] = new QLabel*[dim];
        for (unsigned long j = 0; j < dim; j++) {

                this->labels[i][j] = new QLabel();
                this->labels[i][j]->setBackgroundRole(QPalette::Dark);
                this->labels[i][j]->setScaledContents(true);

                this->labels[i][j]->setFixedSize(17,17);
                this->labels[i][j]->setText(" ");
                this->ui->gridLayout->addWidget(labels[i][j] ,i,j);
        }

    }

    for (unsigned long i = 0; i < dim; i++) {
        for (unsigned long j = 0; j < dim; j++) {
            if (this->getValorMatriz(i,j)) {
                QPixmap pix("/home/emanuel/Facultad/programacion_orientada_objeto/2019/practica/git/codigoCpp2019/tp_Final/tpFinal/final/TP3/pared.png");

                // set a scaled pixmap to a w x h window keeping its aspect ratio
                pix = pix.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(pix);

            } else {
                QPixmap pix("/home/emanuel/Facultad/programacion_orientada_objeto/2019/practica/git/codigoCpp2019/tp_Final/tpFinal/final/TP3/piso.png");

                // set a scaled pixmap to a w x h window keeping its aspect ratio
                pix = pix.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(pix);
            }
        }
     }

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::keyPressEvent(QKeyEvent *e) {

    if(e->key() == Qt::Key_Left ) {
        //Mover jugador
    }
    if(e->key() == Qt::Key_Right) {
        //Mover jugador
    }
    if(e->key() == Qt::Key_Up ) {
        //Mover jugador
    }
    if(e->key() == Qt::Key_Down) {
        //Mover jugador
    }

}

/**
 * Esta función debe retornar el valor de la matriz de mapas en la posición i , j
 * Yo retorno un valor aleatorio, pero ustedes tienen que usar la función del tp1.
 */
int MainWindow::getValorMatriz(int i, int j) {
    return rand() % 2;
}
