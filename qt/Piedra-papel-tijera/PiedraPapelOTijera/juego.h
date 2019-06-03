#ifndef JUEGO_H
#define JUEGO_H

/**
 * @brief The Juego class
 * 0 --> Piedra
 * 1 --> Papel
 * 2 --> tijera
 */

class Juego
{
private:
    int ele;
public:
    Juego();
    int getEle();
    void barajar();

    /**
     * @brief verificar
     * @param eleUsuario
     * @return 0 = empate, 1 = gano maquina, 2 = gano usuario
     */
    int verificar(int eleUsuario);
    char * getEleStr();
};

#endif // JUEGO_H
