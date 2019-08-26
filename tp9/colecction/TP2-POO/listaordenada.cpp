#include "listaordenada.h"
#include <iostream>
using namespace std;

template <class T>
ListaOrdenada<T>::ListaOrdenada():Lista(){

}

template <class T>
ListaOrdenada<T>::ListaOrdenada(T valor):Lista(valor) {

}

template <class T>
ListaOrdenada<T>::~ListaOrdenada() {

}

template <class T>
bool ListaOrdenada<T>::alta(T valor) {
    nodo *aux=acceso;nodo *ant=NULL;nodo *nuevo;
    while (aux!=NULL)
    {
        if (valor < aux->dato) break;
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

