#ifndef INSCRIPCION_H_INCLUDED
#define INSCRIPCION_H_INCLUDED

#include <string>
#include <queue>  // Necesario para usar priority_queue

using namespace std;

// Estructura que representa a un alumno
struct Alumno {
    string nombre;
    double promedio;

    // Constructor
    Alumno(string n, double p);

    // Comparador para la cola de prioridad
    bool operator<(const Alumno& otro) const;
};

// Tipo de cola de prioridad para inscripciones
using ColaInscripciones = priority_queue<Alumno>;

// Funci�n para agregar los alumnos esperando a la cola de inscripciones
void agregarAColaDeInscripciones(alumno &listaAltas, ColaInscripciones &cola);

// Funci�n para desencolar un alumno (inscripci�n)
void inscribirAlumno(ColaInscripciones &cola, alumno &listaAltas);


// Funci�n para imprimir los alumnos en la cola (para verificar el orden)
void mostrarCola(const ColaInscripciones &cola);

// Funci�n para mostrar los alumnos ya inscritos (en listaAltas con situaci�n inscrito)
void mostrarListaInscritos(alumno &listaAltas);

string estado(insc estado);

#endif // INSCRIPCION_H_INCLUDED
