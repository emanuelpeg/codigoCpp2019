#include <QCoreApplication>

#include <iostream>
#include <iomanip>
using namespace std;

const int tamaniotablero=8;
int nSolucion=0;
int tablero[tamaniotablero*tamaniotablero];

int dfila[8]={-1,-2,-1,-2,1,2,1,2};
int dcol[8] ={-2,-1,2,1,-2,-1,2,1};


void inicializar(int tab[])
{ for (int i=0;i<tamaniotablero*tamaniotablero;i++)
    tab[i]=0;}

void MostrarSolucion(int t[])
{ //int i;
    nSolucion++;
    cout << "SOLUCION PARA EL PROBLEMA DE SALTO DEL CABALLO: " << nSolucion << endl;
    for (int fila=0;fila<tamaniotablero;fila++)
    {for (int col=0;col<tamaniotablero;col++)
        cout << setw(4) << t[fila*tamaniotablero+col];
    cout << endl;}
    //cin >> i;
}


void salta(int xinic, int yinic, int nsalto)
{ if (nsalto==(tamaniotablero*tamaniotablero))
    { MostrarSolucion(tablero);
        }
else
    { int nuevax, nuevay;
      for (int i=0;(i<8) ;i++){
          nuevax=xinic+dcol[i];
          nuevay=yinic+dfila[i];
          if ((nuevax>=0) && (nuevay>=0) && (nuevax<tamaniotablero) && (nuevay<tamaniotablero) &&
                  (tablero[nuevay*tamaniotablero+nuevax]==0))
          { nsalto=nsalto+1;
             //cout << nsalto << "  ";
              tablero[nuevay*tamaniotablero+nuevax]=nsalto;
              salta(nuevax,nuevay,nsalto);
              nsalto=nsalto-1;
              tablero[nuevay*tamaniotablero+nuevax]=0;
          }
      }
    }
}

void desplazaCaballo(int x, int y)
{ //Posicion inicial del caballo
    tablero[y*tamaniotablero+x]=1;
    salta(x,y,1);
}

/*int main(int argc, char *argv[]) {

    return 0;
}*/

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Programa recursivo para generar el trayecto de un caballo por todos los cuadros de un tablero de ajedrez
inicializar(tablero);

desplazaCaballo(0,0);
cout << "Finalizaron las pruebas ....";
    return a.exec();
}
