#ifndef SECUENCIA_H
#define SECUENCIA_H

class Secuencia
{
protected:
    int valores[4];
public:
    Secuencia();
    virtual void generarValores()=0;
    int getValor(int index);
};

#endif // SECUENCIA_H
