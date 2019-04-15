#include <iostream>
#include "fraccion.h"

using namespace std;

int main()
{
    Fraccion f = Fraccion(55, 10);
    double d = f.mostrarFraccion();
    cout << d << endl;
    cout << f.suma(Fraccion(3)).mostrarFraccion() << endl;
    cout << f.resta(Fraccion(3)).mostrarFraccion() << endl;
    cout << f.suma(Fraccion(1,2)).mostrarFraccion() << endl;
    return 0;
}

