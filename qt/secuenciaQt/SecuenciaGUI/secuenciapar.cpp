#include "secuenciapar.h"
#include <cstdlib>

SecuenciaPar::SecuenciaPar()
{
    generarValores();
}

void SecuenciaPar::generarValores(){
    int semilla = rand() % 100 + 1;
    for (int i = 0; i<4; i++){
        this->valores[i] = (semilla + i)*2;
    }
}
