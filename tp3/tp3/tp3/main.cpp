#include <iostream>

using namespace std;

int count(char * palabra) {
    int i = 0;
    while(palabra[i] != '\0') {
        i++;
    }
    i++;
    return i;
}

int count(char * palabra, char caracter) {
    int i = 0;
    int cant = 0;
    while(palabra[i] != '\0') {
        if (palabra[i] == caracter) cant++;
        i++;
    }
    return cant;
}

char * toupper(char * palabra) {
    int cant = count(palabra);
    char * palabraMayuscula = new char[cant];
    for(int i=0; i<cant; i++) {

        if(palabra[i] >= 'a' && palabra[i] <= 'z') {
            palabraMayuscula[i] = palabra[i] - 32;
        } else {
            palabraMayuscula[i] = palabra[i];
        }

    }

    return palabraMayuscula;
}

char * tolower(char * palabra) {
    int cant = count(palabra);
    char * palabraMinuscula = new char[cant];
    for(int i=0; i<cant; i++) {

        if(palabra[i] >= 'A' && palabra[i] <= 'Z') {
            palabraMinuscula[i] = palabra[i] + 32;
        } else {
            palabraMinuscula[i] = palabra[i];
        }

    }

    return palabraMinuscula;
}

char * add(char * palabra, char otro) {
    int cant = count(palabra);
    char * palabraAux = new char[cant+1];

    for(int i = 0; i < cant-1; i++) {
        palabraAux[i] = palabra[i];
    }

    palabraAux[cant - 1] = otro;
    palabraAux[cant] = '\0';
    return palabraAux;
}

bool contiene(char * palabra, char otro) {
    int cant = count(palabra);
    for(int i = 0; i < cant-1; i++) {
        if (palabra[i] == otro) return true;
    }
    return false;
}

char * eliminar(char * palabra, char otro) {
    if (contiene(palabra, otro)) {
        int cant = count(palabra);
        char * palabraAux = new char[cant-1];
        int i = 0;
        for(i = 0; i < cant; i++) {
            if (palabra[i] == otro) {
                break;
            }
            palabraAux[i] = palabra[i];
        }
        for(i = i + 1; i < cant; i++) {
            palabraAux[i-1] = palabra[i];
        }
        return palabraAux;
    }

    return palabra;
}

char * eliminarAll(char * palabra, char otro) {
    if (contiene(palabra, otro)) {
        int cant = count(palabra);
        int cantidadCaracteres = count(palabra, otro);
        char * palabraAux = new char[cant-cantidadCaracteres];
        int cantEliminados = 0;
        for(int i = 0; i < cant; i++) {
            if (palabra[i] != otro) {
                palabraAux[i - cantEliminados] = palabra[i];
            } else {
                cantEliminados++;
            }
        }

        return palabraAux;
    }

    return palabra;
}

char * subString(char * palabra, int index) {
    int cantidad = count(palabra);
    if (cantidad > index) {
        char * sub = new char[cantidad - index];
        for (int i = index; i < cantidad; i++) {
            sub[i - index] = palabra[i];
        }
        return sub;
    }
    return 0;
}

char * subString(char * palabra, int inicio, int final) {
    int cantidad = count(palabra);
    if (cantidad > final && final > inicio) {
        char * sub = new char[final - inicio + 1];
        for (int i = inicio; i < final; i++) {
            sub[i - inicio] = palabra[i];
        }
        sub[final - inicio] = '\0';
        return sub;
    }
    return 0;
}

char * reverso(char * palabra) {
    int cantidad = count(palabra);
    char * rev = new char[cantidad];
    for (int i = 0; i < cantidad -1; i++) {
        rev[cantidad - (i+2)] = palabra[i];
    }
    rev[cantidad - 1] = palabra[cantidad - 1];
    return rev;
}

int main(int argc, char *argv[])
{
    char * palabra =  "Hello World!";
    char * palabra2 =  "AAbaAaAEEACAE";
    cout << toupper(palabra) << endl;
    cout << tolower(palabra) << endl;
    cout << add(palabra, '!') << endl;
    cout << eliminar(palabra, '!') << endl;
    cout << eliminar(palabra, 'e') << endl;
    cout << eliminarAll(palabra2, 'A') << endl;
    cout << subString(palabra, 6) << endl;
    cout << subString(palabra, 6, 11) << endl;
    cout << subString(palabra, 0, 5) << endl;
    cout << reverso(palabra) << endl;
    return 0;
}
