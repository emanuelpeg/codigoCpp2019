#include "juego.h"
#include <stdlib.h>
#include <time.h>
#include <cmath>

Juego::Juego()
{

}

void Juego::barajar(){
    srand (time(NULL));
    this->ele = (rand() % 3);
}

/**
 *  0 = piedra -> gana 2 tijera, pierde 1 papel
 */
int Juego::verificar(int eleUsuario) {
     return abs(this->ele - eleUsuario);
}

int Juego::getEle() {
    return this->ele;
}

char * Juego::getEleStr() {
    switch (this->ele) {
    case 0:
        return "Piedra";
    case 1:
        return "Papel";
    case 2:
        return "Tijera";
    }
}
