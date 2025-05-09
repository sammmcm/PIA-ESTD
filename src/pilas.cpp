#include <iostream>
#include "alta.h"

bool pilaVacia(alumno &pila) {
    if (pila == nullptr) {
        cout << endl << "La pila esta vacia. No hay bajas recientes." << endl << endl;
        return true;
    }

    return false;
}

void insertarEnPila(alumno &pila, alumno elem) {
    alumno elemPila = new nodo;
    elemPila->matricula = elem->matricula;
    elemPila->nombre = elem->nombre;
    elemPila->edad = elem->edad;
    elemPila->promedio = elem->promedio;
    elemPila->situacion = baja;
    elemPila->address.calle = elem->address.calle;
    elemPila->address.colonia = elem->address.colonia;
    elemPila->address.municipio = elem->address.municipio;
    elemPila->address.numero = elem->address.numero;
    elemPila->address.cp = elem->address.cp;
    elemPila->sig = pila;
    elemPila->inscripcion = inactivo;
    pila = elemPila;
}

void eliminarAlumDePila(alumno &pila, alumno &elem) {
    if (pila == elem) {
        pila = pila->sig;
        delete elem;
        elem = nullptr;
        return;
    }
    
    alumno aux = pila;
    while (aux->sig != nullptr && aux->sig != elem) {
        aux = aux->sig;
    }
    
    if (aux->sig == elem) {
        aux->sig = elem->sig;
        delete elem;
        elem = nullptr;
        return;
    }
}

void eliminarPila(alumno &pila) {
    if (pila == nullptr) return;
    
    alumno aux;
    while (pila != nullptr) {
        aux = pila;
        pila = pila->sig;
        delete aux;
    }
}

void mostrarPila(alumno &pila) {
    if (pila == nullptr) {
        cout << "La pila esta vacia." << endl;
        return;
    }

    alumno aux = pila;
    while (aux != nullptr) {
        cout << aux->matricula << " -> ";
        aux = aux->sig;
    }
    cout << "nullptr\n";
}
