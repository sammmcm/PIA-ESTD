#ifndef INSCRIPCION_H_INCLUDED
#define INSCRIPCION_H_INCLUDED

#include <string>
#include <queue>

using namespace std;

struct Alumno {
    string nombre;
    double promedio;

    Alumno(string n, double p);

    bool operator<(const Alumno& otro) const;
};

using ColaInscripciones = priority_queue<Alumno>;
void agregarAColaDeInscripciones(alumno &listaAltas, ColaInscripciones &cola);
void inscribirAlumno(ColaInscripciones &cola, alumno &listaAltas);
void mostrarCola(const ColaInscripciones &cola);
void mostrarListaInscritos(alumno &listaAltas);

#endif // INSCRIPCION_H_INCLUDED
