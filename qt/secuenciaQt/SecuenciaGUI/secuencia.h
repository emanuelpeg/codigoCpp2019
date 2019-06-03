#ifndef SECUENCIA_H
#define SECUENCIA_H

class Secuencia
{
protected:
    int valores [4];
public:
    Secuencia();
    virtual void generarValores()=0;
    int getFirstValue();
    int getSecondValue();
    int getThirdValue();
    int getFourthValue();
};

#endif // SECUENCIA_H
