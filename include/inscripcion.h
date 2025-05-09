#ifndef INSCRIPCIONES_H
#define INSCRIPCIONES_H

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

// Función para agregar los alumnos esperando a la cola de inscripciones
void agregarAColaDeInscripciones(alumno &listaAltas, ColaInscripciones &cola);

// Función para desencolar un alumno (inscripción)
void inscribirAlumno(ColaInscripciones &cola, alumno &listaAltas);


// Función para imprimir los alumnos en la cola (para verificar el orden)
void mostrarCola(const ColaInscripciones &cola);

// Función para mostrar los alumnos ya inscritos (en listaAltas con situación inscrito)
void mostrarListaInscritos(alumno &listaAltas);

string estado(insc estado);

#endif // INSCRIPCIONES_H