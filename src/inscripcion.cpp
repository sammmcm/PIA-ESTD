#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <functional>
#include "alta.h"
#include "listas.h"

using namespace std;

struct Alumno {
    string nombre;
    double promedio;

    Alumno(string n, double p) : nombre(n), promedio(p) {}

    bool operator<(const Alumno& otro) const {
        if (promedio == otro.promedio)
            return nombre > otro.nombre;
        return promedio < otro.promedio;
    }
};

using ColaInscripciones = priority_queue<Alumno>;

void agregarAColaDeInscripciones(alumno &listaAltas, ColaInscripciones &cola) {
    if (listaAltas == nullptr) return;

    alumno actual = listaAltas;
    while (actual != nullptr) {
        if (actual->inscripcion == esperando) {
            Alumno alumnoEnCola(actual->nombre, actual->promedio);
            cola.push(alumnoEnCola);
        }
        actual = actual->sig;
    }
}

void inscribirAlumno(ColaInscripciones &cola, alumno &listaAltas) {
    Alumno alumnoInscrito = cola.top();
    cola.pop();

    alumno actual = listaAltas;
    while (actual != nullptr) {
        if (actual->nombre == alumnoInscrito.nombre) {
            actual->inscripcion = inscrito;
            break;
        }
        actual = actual->sig;
    }

    cout << endl << "Alumno " << alumnoInscrito.nombre << " inscrito. Promedio: "
            << alumnoInscrito.promedio << endl << endl;
}

void mostrarCola(const ColaInscripciones &cola) {
    if (cola.empty()) {
        cout << "Cola vacia. No hay alumnos en la cola para inscribirse." << endl;
        return;
    }

    ColaInscripciones copia = cola;
    cout << endl << "Alumnos en la cola para inscribirse:\n";
    while (!copia.empty()) {
        Alumno alumno = copia.top();
        cout << alumno.nombre << " - Promedio: " << alumno.promedio << endl;
        copia.pop();
    }
    cout << endl;
}

void mostrarListaInscritos(alumno &listaAltas) {
    bool inscritos = false;

    alumno aux = listaAltas;
    cout << endl << "Alumnos inscritos: " << endl;
    while (aux != nullptr) {
        if (aux->inscripcion == inscrito) {
            cout << aux->nombre << " - Promedio: " << aux->promedio << endl;
            inscritos = true;
        }
        aux = aux->sig;
    }

    if (inscritos == false) cout << "No hay alumnos inscritos todavia." << endl << endl;
    else cout << endl;
}
