#include <iostream>
#include "arbol.h"

using namespace std;

int main(int argc, char *argv[])
{
    Arbol a(8);
    a.agregar(3);
    a.agregar(10);
    a.agregar(1);
    a.agregar(6);
    a.agregar(4);
    a.agregar(7);
    a.agregar(14);
    a.agregar(17);

    cout << "Imprimir Arbol" << endl;
    cout << a << endl;
    return 0;
}
