#include "secuencia.h"


Secuencia::Secuencia()
{
    for(int i=0;i<4; i++){
        valores[i]=0;
    }
}

int Secuencia::getValor(int index){
    return valores[index];
}
