#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <functional>  // Para std::greater
#include "alta.h"
#include "listas.h"

using namespace std;

// Definir la estructura del alumno
struct Alumno {
    string nombre;
    double promedio;

    // Constructor
    Alumno(string n, double p) : nombre(n), promedio(p) {}

    // Comparador para la cola de prioridad (primero por promedio, luego por nombre)
    bool operator<(const Alumno& otro) const {
        if (promedio == otro.promedio)
            return nombre > otro.nombre;  // Si promedios son iguales, se ordena por nombre alfab�ticamente
        return promedio < otro.promedio;  // Ordena de mayor a menor promedio
    }
};

// Tipo de cola de prioridad para inscripciones
using ColaInscripciones = priority_queue<Alumno>;

// Funci�n para agregar los alumnos esperando a la cola de inscripciones
void agregarAColaDeInscripciones(alumno &listaAltas, ColaInscripciones &cola) {
    alumno actual = listaAltas;

    while (actual != nullptr) {
        if (actual->inscripcion == esperando) {
            Alumno alumnoEnCola(actual->nombre, actual->promedio);
            cola.push(alumnoEnCola);
        }
        actual = actual->sig;
    }
}

// Funci�n para desencolar un alumno (inscripci�n)
void inscribirAlumno(ColaInscripciones &cola, alumno &listaAltas) {  // Add listaAltas parameter
    if (!cola.empty()) {
        Alumno alumnoInscrito = cola.top();
        cola.pop();

        // Find and update the student's status in the main list
        alumno actual = listaAltas;
        while (actual != nullptr) {
            if (actual->nombre == alumnoInscrito.nombre) {
                actual->inscripcion = inscrito;  // Update status to inscrito
                break;
            }
            actual = actual->sig;
        }

        cout << "Alumno " << alumnoInscrito.nombre << " inscrito. Promedio: "
             << alumnoInscrito.promedio << endl;
    } else {
        cout << "No hay alumnos en la cola para inscribirse." << endl;
    }
}

// Funci�n para imprimir los alumnos en la cola (para verificar el orden)
void mostrarCola(const ColaInscripciones &cola) {
    if(cola.empty()) {
        cout << "No hay alumnos en la cola para inscribirse." << endl;
        return;
    }

    ColaInscripciones copia = cola;
    cout << "Alumnos en la cola para inscribirse (de mayor a menor promedio):\n";
    while (!copia.empty()) {
        Alumno alumno = copia.top();
        cout << alumno.nombre << " - Promedio: " << alumno.promedio << endl;
        copia.pop();
    }
}


// Funci�n para mostrar los alumnos ya inscritos
void mostrarListaInscritos(alumno &listaAltas) {
    alumno aux = listaAltas;
    while (aux != nullptr) {
        if (aux->inscripcion == inscrito) {  // Changed from situacion to inscripcion
            cout << aux->nombre << " - Promedio: " << aux->promedio << endl;
        }
        aux = aux->sig;
    }
}

string estado(insc estado) {
    switch(estado) {
        case esperando: return "esperando";
        case inactivo: return "inactivo";
        case inscrito: return "inscrito";
        default: return "desconocido";
    }
}
