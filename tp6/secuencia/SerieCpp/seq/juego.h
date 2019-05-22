#ifndef JUEGO_H
#define JUEGO_H
#include "secuencia.h"

class Juego
{
private:
    int puntos;
    Secuencia * secuencia;
    void regenerar();
public:
    Juego();
    int getValor0();
    int getValor1();
    int getValor3();
    bool validar(int numero);
    int getPuntos();
};

#endif // JUEGO_H
