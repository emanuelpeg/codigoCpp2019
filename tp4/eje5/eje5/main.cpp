#include <iostream>
#include "curso.h"
#include "alumno.h"

using namespace std;

int main()
{
    Alumno juan(295200);
    juan.setNota(0,60);
    juan.setNota(1,60);
    juan.setNota(2,40);
    juan.setNota(2,80);
    juan.setNombre("Juan");
    Alumno jorge(3952000);
    jorge.setNota(0,40);
    jorge.setNota(1,70);
    jorge.setNota(2,70);
    jorge.setNota(2,80);
    jorge.setNombre("jorge");
    Alumno marcos(595200);
    marcos.setNota(0,60);
    marcos.setNota(1,60);
    marcos.setNota(2,20);
    marcos.setNota(2,80);
    marcos.setNombre("marcos");
    Alumno pedro(795200);
    pedro.setNota(0,100);
    pedro.setNota(1,60);
    pedro.setNota(2,40);
    pedro.setNota(2,100);
    pedro.setNombre("Pedro");

    Curso curso("poo");
    curso.agregarAlumno(juan);
    curso.agregarAlumno(jorge);
    curso.agregarAlumno(marcos);
    curso.agregarAlumno(pedro);

    curso.mostrarAlumnos();
    return 0;
}
