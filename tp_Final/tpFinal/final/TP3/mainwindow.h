#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "juego.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QLabel *** labels;
    Ui::MainWindow *ui;
    Juego *game;
    int dim, cast;

private slots:
    void dibujarArtefacto();
    void checkArtefactos();
    void actualizar();
    void endOfGame();

public slots:
    void keyPressEvent(QKeyEvent * e);

};

#endif // MAINWINDOW_H
