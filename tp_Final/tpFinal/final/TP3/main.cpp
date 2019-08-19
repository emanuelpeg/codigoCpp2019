#include <iostream>
#include <QApplication>
#include "juego.h"
#include "mainwindow.h"

/*using namespace std;

int main()
{
    Juego *juego=new Juego(25, 25);
    juego->mostrarMapa();
    return 0;
}
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
