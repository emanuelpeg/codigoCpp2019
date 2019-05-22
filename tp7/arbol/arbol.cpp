#include "arbol.h"


Arbol::Arbol(int dato)
{
    this->dato = dato;
}

void Arbol::agregar(int otroDato){
    if (this->dato > otroDato) {
        if (this->izq != 0) {
            this->izq->agregar(otroDato);
        } else {
            this->izq = new Arbol(otroDato);
        }
    } else {
        if (this->der != 0) {
            this->der->agregar(otroDato);
        } else {
            this->der = new Arbol(otroDato);
        }
    }
}

ostream& operator<<(std::ostream& out, const Arbol& a){
    if (a.izq !=0) {
        out << *(a.izq);
    }
    out << a.dato << "  ";
    if (a.der !=0) {
        out << *(a.der);
    }
    return out;
}

bool Arbol::existe(int otroDato) {
    if (this->dato == otroDato)
        return true;
    if (this->dato > otroDato) {
        if (this->izq != 0) {
            return this->izq->existe(otroDato);
        } else {
            return false;
        }
    } else {
        if (this->der != 0) {
            return this->der->existe(otroDato);
        } else {
            return false;
        }
    }
}
