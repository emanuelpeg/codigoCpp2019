#ifndef ARBOL_H
#define ARBOL_H
#include <iostream>

using namespace std;

class Arbol
{
private:
    int dato;
    Arbol * izq=0;
    Arbol * der=0;
public:
    Arbol(int dato);
    void agregar(int otroDato);
    bool existe(int otroDato);
    friend ostream& operator<<(std::ostream& out, const Arbol& a);
};

#endif // ARBOL_H
