#include <iostream>
#include <stdlib.h>
#include "juego.h"

using namespace std;

int main()
{
    Juego juego;
    cout << " ========== BIENVENIDO =========== "<<endl;
    cout << endl;
    while (true) {
        cout << " La secuencia es : "<<endl;
        cout << "                    " << juego.getValor0() << "   " ;
        cout << juego.getValor1() << "   ?   " << juego.getValor3()<<endl;
        int valor = 0;
        cout << "    ---------------------->  ";
        cin >> valor;
        if  (juego.validar(valor)) {
            cout << "     Ganaste!!  :D "<< endl;
        } else {
            cout << "     Perdiste   :(  "<< endl;
        }
        cout << endl << "     Sus puntos son :  " << juego.getPuntos() << endl;
        cout << "     Desea continuar jugando ? (y/n)  ";
        char opt;
        cin >> opt;
        if (opt == 'n') return 0;
           else cout << endl << endl;
    }

}

