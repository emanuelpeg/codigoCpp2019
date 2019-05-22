#include "secuenciaimpar.h"
#include <stdlib.h>
#include <time.h>

SecuenciaImpar::SecuenciaImpar()
{
}

void SecuenciaImpar::generarValores(){
    srand(time(NULL));
    int impar = ((rand() % 100) * 2)+1;
    for(int i = 0; i<4; i++){
        valores[i] = impar + (i * 2);
    }
}
