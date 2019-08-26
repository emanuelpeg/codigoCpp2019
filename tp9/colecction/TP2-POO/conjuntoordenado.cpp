#include "conjuntoordenado.h"
#include <iostream>
using namespace std;

template <class T>
ConjuntoOrdenado<T>::ConjuntoOrdenado():Conjunto() {

}

template <class T>
ConjuntoOrdenado<T>::ConjuntoOrdenado(int valor):Conjunto(valor) {

}

ConjuntoOrdenado<T>::~ConjuntoOrdenado() {

}

template <class T>
bool ConjuntoOrdenado<T>::alta(T valor) {
    nodo *aux=acceso;
    nodo *ant=NULL;
    nodo *nuevo;
    while (aux!=NULL) {
        if (valor < aux->dato) break;
        if (aux->dato == valor) return false;
        ant=aux;
        aux=aux->sig;
    }
    nuevo = new nodo;
    nuevo->dato=valor;
    nuevo->sig=aux;
    if(ant!=NULL) ant->sig=nuevo;
    else acceso=nuevo;
    cantidad++;
    return true;
}
