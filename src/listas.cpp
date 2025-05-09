#include <iostream>
#include "alta.h"

using namespace std;

bool listaVacia(alumno &lista) {
    if (lista == nullptr) {
        cout << endl << "La lista esta vacia. No hay alumnos para dar de baja." << endl << endl;
        return true;
    }

    return false;
}

void insertarEnLista(alumno &lista, alumno &nuevo) {
    if (lista == nullptr) {
        lista = nuevo;
        nuevo->sig = nullptr;
        return;
    } else {
        alumno aux = lista;
        while (aux->sig != nullptr) {
            aux = aux->sig;
        }
        aux->sig = nuevo;
        nuevo->sig = nullptr;
    }
}

void eliminarAlumDeLista(alumno &lista, alumno &elem) {
    if (lista == elem) {
        lista = lista->sig;
        delete elem;
        elem = nullptr;
        return;
    }
    
    alumno aux = lista;
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

void eliminarLista(alumno &lista) {
    if (lista == nullptr) return;
    
    alumno aux;
    while (lista != nullptr) {
        aux = lista;
        lista = lista->sig;
        delete aux;
    }
}

void mostrarLista(alumno &lista) {
    if (lista == nullptr) {
        cout << "La lista esta vacia." << endl;
        return;
    }

    alumno aux = lista;
    while (aux != nullptr) {
        cout << aux->matricula << " -> ";
        aux = aux->sig;
    }
    cout << "nullptr\n";
}

void dividirLista(alumno fuente, alumno &front, alumno &back) {
    if (!fuente || !fuente->sig) {
        front = fuente;
        back = nullptr;
        return;
    }

    alumno atras = fuente;
    alumno adelante = fuente->sig;

    while (adelante) {
        adelante = adelante->sig;
        if (adelante) {
            atras = atras->sig;
            adelante = adelante->sig;
        }
    }
    
    front = fuente;
    back = atras->sig;
    atras->sig = nullptr;
}

alumno merge(alumno a, alumno b) {
    if (!a) return b;
    if (!b) return a;

    alumno resultado = nullptr;

    if (a->matricula <= b->matricula) {
        resultado = a;
        resultado->sig = merge(a->sig, b);
    } else {
        resultado = b;
        resultado->sig = merge(a, b->sig);
    }

    return resultado;
}

void mergeSort(alumno &lista) {
    if (!lista || !lista->sig) return;

    alumno a = nullptr, b = nullptr;
    dividirLista(lista, a, b);
    
    mergeSort(a);
    mergeSort(b);

    lista = merge(a, b);
}

int obtenerTamaño(alumno lista) {
    int tam = 0;
    while (lista) {
        tam++;
        lista = lista->sig;
    }
    return tam;
}

alumno obtenerEnPosicion(alumno lista, int pos) {
    int i = 0;
    while (lista && i < pos) {
        lista = lista->sig;
        i++;
    }
    return lista;
}

alumno busquedaBinaria(alumno lista, int inicio, int fin, long matriculaBuscada) {
    if (inicio > fin) return nullptr;

    int medio = (inicio + fin) / 2;
    alumno nodoMedio = obtenerEnPosicion(lista, medio);

    if (!nodoMedio) return nullptr;

    if (nodoMedio->matricula == matriculaBuscada) {
        return nodoMedio;
    } else if (matriculaBuscada < nodoMedio->matricula) {
        return busquedaBinaria(lista, inicio, medio - 1, matriculaBuscada);
    } else {
        return busquedaBinaria(lista, medio + 1, fin, matriculaBuscada);
    }
}
