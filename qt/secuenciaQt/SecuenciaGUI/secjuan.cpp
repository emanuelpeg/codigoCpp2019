#include "secjuan.h"
#include <stdlib.h>
#include <time.h>
/*
 * autor: JUAN CARLOS DAGNA
 * DNI 14981828
 */
secjuan::secjuan()
{

}
void secjuan::generarValores(){
    srand(time(NULL));
    int valor = (rand() % 10);
    int salto = (rand() % 5)+1;
    for(int i = 0; i<4; i++){
        valores[i] = valor + ((salto*3)*(i+1));
    }
}
