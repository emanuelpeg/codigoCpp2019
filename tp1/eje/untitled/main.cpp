#include <iostream>
#include <tgmath.h>

using namespace std;

//Repaso de Tipos, compiladores, nivel.
//El entorno de desarrollo, proceso de compilación, ejecución y debugging.
//Problemas para revisión de lógica de control. Parte 1.

int divisionEntera(int numerador, int denominador, int &resto) {
    resto = numerador % denominador;
    return numerador / denominador;
}

// h=sqrt((x^2)+(y^2))
double hipotenusa(double x, double y) {
    return sqrt((x * x)+(y * y));
}

//Función mcd(a,b):
//  Si b=0 entonces:
//  El resultado es a
//  En otro caso:
//     El resultado es mcd(b,a % b)
int mcd(int a, int b) {
    if (b==0) {
        return a;
    } else {
        return mcd(b, a % b);
    }
}



int main(int argc, char *argv[])
{
    int numerador = 5;
    int denominador = 2;
    int resto = 0;

    int resultado = divisionEntera(numerador, denominador, resto);

    cout << "numerador : " << numerador << endl;
    cout << "denominador : " << denominador << endl;
    cout << "resto : " << resto << endl;
    cout << "resultado : " << resultado << endl;

    double a = 2 / 3;

    cout << a;

    return 0;
}

