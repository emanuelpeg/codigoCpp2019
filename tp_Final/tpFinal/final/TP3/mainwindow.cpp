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
    game=new Juego(dim, cast);

    this->labels = new QLabel**[dim];
    for (int i = 0; i < dim; i++) {
        this->labels[i] = new QLabel*[dim];
        for (int j = 0; j < dim; j++) {

                this->labels[i][j] = new QLabel();
                this->labels[i][j]->setBackgroundRole(QPalette::Dark);
                this->labels[i][j]->setScaledContents(true);

                this->labels[i][j]->setFixedSize(17,17);
                this->labels[i][j]->setText(" ");
                this->ui->gridLayout->addWidget(labels[i][j] ,i,j);
        }

    }

    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            if ((game->getMapa())->getPos(i,j)->getEstado() != 0) {
                QPixmap pix("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/pared.png");

                // set a scaled pixmap to a w x h window keeping its aspect ratio
                pix = pix.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(pix);

            } else {
                QPixmap pix("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/piso.png");

                // set a scaled pixmap to a w x h window keeping its aspect ratio
                pix = pix.scaled(17,17,Qt::KeepAspectRatio);
                this->labels[i][j]->setPixmap(pix);
            }
        }
     }

    //this->showFullScreen();
    QLabel *myimage = this->labels[game->getJugador().x][game->getJugador().y];

    QPixmap pix("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/personaje.jpg");
    myimage->setPixmap(pix.scaled(17,17,Qt::KeepAspectRatio));

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(dibujarArtefacto()));
    timer->start(cast*500);
    dibujarArtefacto();
    QTimer *check = new QTimer(this);
    connect(check, SIGNAL(timeout()), this, SLOT(checkArtefactos()));
    check->start(500);

    actualizar();

}

MainWindow::~MainWindow()
{
    if (game->getVida()>0) game->guardarPartida();
    delete ui;
}

void MainWindow::dibujarArtefacto() {
    if (this->game->noSuperaElMaximoDeEnemigos()) {
        Coordenada pos=game->crearEnemigo();
        QLabel *myimage = this->labels[pos.x][pos.y];

        QPixmap pix("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/enemigo.png");
        myimage->setPixmap(pix.scaled(17,17,Qt::KeepAspectRatio));
    }

}

void MainWindow::checkArtefactos() {
    Casillero *cas;
    Enemigo *art;
    Coordenada pos;
    pos.x = -1;
    pos.y = -1;
    for (int i=0; i<dim; i++) {
        for (int j=0; j<dim; j++) {
            if (pos.x != i && pos.y != j) {
                cas=game->getMapa()->getPos(i,j);
                if (cas->getTipo()=='A') {

                        QLabel *myimage=labels[i][j];
                        QPixmap pix("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/piso.png");
                        myimage->setPixmap(pix.scaled(17,17,Qt::KeepAspectRatio));
                        pos=game->moverEnemigo(i, j);
                        QLabel *myimage2 = this->labels[pos.x][pos.y];

                        QPixmap pix2("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/enemigo.png");
                        myimage2->setPixmap(pix2.scaled(17,17,Qt::KeepAspectRatio));
                        game->moverJugador(4);

                }
            }

        }
    }
}

void MainWindow::actualizar() {
    this->ui->vidas->setText("Vidas: " + QString::number(game->getVida()));
    this->ui->puntaje->setText("Puntaje: " + QString::number(game->getPuntaje()));
    if (game->getVida()==0) endOfGame();
}

void MainWindow::endOfGame() {
    QMessageBox msgBox;
    msgBox.setText("El juego ha terminado. Puntaje: " + QString::number(game->getPuntaje()));
    msgBox.exec();
    QApplication::quit();
}

void MainWindow::keyPressEvent(QKeyEvent *e) {
    bool flag;
    if(e->key() == Qt::Key_Left ) {
        flag=game->moverJugador(2);
        if (flag==true) {
            QPixmap ant("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/piso.png");
            QLabel *myimage = this->labels[game->getJugador().x][game->getJugador().y+1];
            myimage->setPixmap(ant.scaled(17,17,Qt::KeepAspectRatio));
            myimage = this->labels[game->getJugador().x][game->getJugador().y];
            QPixmap pix("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/personaje.jpg");
            myimage->setPixmap(pix.scaled(17,17,Qt::KeepAspectRatio));
        }
    }
    if(e->key() == Qt::Key_Right) {
        flag=game->moverJugador(3);
        if (flag==true) {
            QPixmap ant("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/piso.png");
            QLabel *myimage = this->labels[game->getJugador().x][game->getJugador().y-1];
            myimage->setPixmap(ant.scaled(17,17,Qt::KeepAspectRatio));
            myimage = this->labels[game->getJugador().x][game->getJugador().y];
            QPixmap pix("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/personaje.jpg");
            myimage->setPixmap(pix.scaled(17,17,Qt::KeepAspectRatio));
        }
    }
    if(e->key() == Qt::Key_Up ) {
        flag=game->moverJugador(0);
        if (flag==true) {
            QPixmap ant("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/piso.png");
            QLabel *myimage = this->labels[game->getJugador().x+1][game->getJugador().y];
            myimage->setPixmap(ant.scaled(17,17,Qt::KeepAspectRatio));
            myimage = this->labels[game->getJugador().x][game->getJugador().y];
            QPixmap pix("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/personaje.jpg");
            myimage->setPixmap(pix.scaled(17,17,Qt::KeepAspectRatio));
        }
    }
    if(e->key() == Qt::Key_Down) {
        flag=game->moverJugador(1);
        if (flag==true) {
            QPixmap ant("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/piso.png");
            QLabel *myimage = this->labels[game->getJugador().x-1][game->getJugador().y];
            myimage->setPixmap(ant.scaled(17,17,Qt::KeepAspectRatio));
            myimage = this->labels[game->getJugador().x][game->getJugador().y];
            QPixmap pix("/home/emanuel/Facultad/programacion_orientada_objeto/2019/tp_Final/tpFinal/final/personaje.jpg");
            myimage->setPixmap(pix.scaled(17,17,Qt::KeepAspectRatio));
        }
    }

//    // for testing purposes //

    if(e->key() == Qt::Key_A) {
        game->setVida(true);
    }
    if(e->key() == Qt::Key_S) {
        game->setPuntaje(true);
    }
    if(e->key() == Qt::Key_Z) {
        game->setVida(false);
    }
    if(e->key() == Qt::Key_X) {
        game->setPuntaje(false);
    }

    actualizar();
}
