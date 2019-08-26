#include "conjunto.h"
#include <iostream>
using namespace std;

template <class T>
Conjunto<T>::Conjunto():Lista() {

}

template <class T>
Conjunto<T>::Conjunto(int valor):Lista(valor) {

}

Conjunto<T>::~Conjunto() {

}

template <class T>
bool Conjunto<T>::alta(T valor) {
    nodo *aux=acceso;
    nodo *ant=NULL;
    while(aux!=NULL) {
       if (aux->dato==valor) return false;
       ant=aux;
       aux=aux->sig;
    }
    aux=new nodo;
    aux->dato=valor;
    aux->sig=NULL;
    if (ant!=NULL) ant->sig=aux;
    else acceso=aux;
    cantidad++;
    return true;
}
