#include <iostream>
#include "bien.h"
#include "mueble.h"
#include "rodado.h"
#include "terreno.h"
#include "gestorcontable.h"

using namespace std;

int main()
{
    GestorContable gestorContable = GestorContable();

    Bien * unTerreno = new Terreno();
    unTerreno->setValor(12000.0);
    gestorContable.imprimir(unTerreno);

    Bien * unRodado = new Rodado();
    Rodado * o = 0;
    if (o = reinterpret_cast<Rodado*> (unRodado)) {
        o->setKm(2450);
    }


    unRodado->setValor(400000.00);
    gestorContable.imprimir(unRodado);

    Bien * unMueble = new Mueble(2000);
    unMueble->setValor(47000.00);
    gestorContable.imprimir(unMueble);

    return 0;
}

