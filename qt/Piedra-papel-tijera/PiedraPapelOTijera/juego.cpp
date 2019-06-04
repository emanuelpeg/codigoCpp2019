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
    if((ele == 0) && (eleUsuario== 1)) {
        return 2;
    }
    if((ele == 0) && (eleUsuario== 2)) {
        return 1;
    }
    if((ele == 1) && (eleUsuario== 0)) {
        return 1;
    }
    if((ele == 1) && (eleUsuario== 2)) {
        return 2;
    }
    if((ele == 2) && (eleUsuario== 0)) {
        return 2;
    }
    if((ele == 2) && (eleUsuario== 1)) {
        return 1;
    }
    return 0;
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
