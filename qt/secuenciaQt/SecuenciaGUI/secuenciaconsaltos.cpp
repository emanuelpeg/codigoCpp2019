#include "secuenciaconsaltos.h"
#include <stdlib.h>
#include <time.h>

SecuenciaConSaltos::SecuenciaConSaltos()
{

}

void SecuenciaConSaltos::generarValores(){
    srand(time(NULL));
    int valor = (rand() % 100);
    int salto = (rand() % 10);
    for(int i = 0; i<4; i++){
        valores[i] = valor + (i * salto);
    }
}
