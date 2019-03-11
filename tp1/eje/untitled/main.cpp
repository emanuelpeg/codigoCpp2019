#include <iostream>
#include <tgmath.h>

using namespace std;

//Repaso de Tipos, compiladores, nivel.
//El entorno de desarrollo, proceso de compilación, ejecución y debugging.
//Problemas para revisión de lógica de control. Parte 1.


//---------------- eje 1 --------------
int divisionEntera(int numerador, int denominador, int &resto) {
    resto = numerador % denominador;
    return numerador / denominador;
}

// Factorial de n
int facto(int n) {
    return (n == 0) ? 1 : n * facto(n - 1);
}

// Intercambia el valor de 2 variables
int intercambiar(char &a, char &b) {
    char aux = a;
    a = b;
    b = aux;
}

int intercambiar(int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

int intercambiar(float a[], float b[], int count) {
    float * aux = new float(count);
    for (int i = 0; i<count; i++) {
        aux[i] = a[i];
    }
    for (int i = 0; i<count; i++) {
        a[i] = b[i];
    }
    for (int i = 0; i<count; i++) {
        b[i] = aux[i];
    }
}

//------------------ Eje 2
double calcularIva(double monto) {
    return monto * 0,13;
}

double calcularMontoTotal(double monto) {
    monto = monto + calcularIva(monto);
    double descuento = 0;
    if (monto > 50) {
        descuento = monto * 0.05;
    }
    return monto - descuento;
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

    cout << facto(5);

    char a = 'A';
    char b = 'B';
    intercambiar(a,b);
    cout << a;
    cout << b << endl;
    cout << calcularMontoTotal(40.5)<< endl;

    float * aa = new float[5];
    float * ba = new float[5];
    ba[0] = 999;
    aa[0] = 0;
    aa[1] = 1;

    intercambiar(aa, ba, 5);
    cout<< ba[0]<< endl;
    cout<< ba[1]<< endl;
    return 0;
}

