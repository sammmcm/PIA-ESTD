#include <iostream>
#include <string>
#include "alta.h"
#include "listas.h"
#include "pilas.h"
#include "validaciones.h"

alumno busquedaPorMatricula(alumno &estructura, long &bajaMat) {
    int tam = obtenerTamaño(estructura);
    alumno encontrado = busquedaBinaria(estructura, 0, tam - 1, bajaMat);

    return encontrado;
}

alumno busquedaPorNombre(alumno &estructura, string &elimNom) {
    if (estructura->nombre == elimNom) return estructura;
    
    alumno aux = estructura;
    while (aux != nullptr) {
        if (aux->nombre == elimNom) return aux;
        aux = aux->sig;
    }

    return nullptr;
}

void bajaParcial(alumno &listaAltas, alumno &listaBajas, alumno &pila) {
    if (listaVacia(listaAltas)) {
        cout << "No hay alumnos para dar de baja." << endl << endl;
        return;
    }

    int opBusc;
    cout << endl << "Buscar por:" << endl
        << "1. Matricula." << endl
        << "2. Nombre." << endl
        << "3. Salir." << endl;
    do {
        cout << "Elija una opcion: ";
    } while (!validarInt(opBusc) && cout << "Error: La opcion debe ser entero y contener solo numeros." << endl << endl);

    switch (opBusc) {
        case 1: {
            long bajaMat;
            do {
                cout << endl << "Ingrese la matricula del alumno a dar de baja: ";
            } while (!validarLong(bajaMat) && cout << "Error: La matricula debe ser positiva y contener solo numeros." << endl);
        
            alumno encontrado = busquedaPorMatricula(listaAltas, bajaMat);
            if (encontrado == nullptr) {
                cout << endl << "No se encontro el alumno con la matricula " << bajaMat << "." << endl << endl;
                return;
            }
        
            alumno alumBaja = new nodo;
            alumBaja->matricula = encontrado->matricula;
            alumBaja->nombre = encontrado->nombre;
            alumBaja->edad = encontrado->edad;
            alumBaja->promedio = encontrado->promedio;
            alumBaja->situacion = baja;
            alumBaja->address.calle = encontrado->address.calle;
            alumBaja->address.colonia = encontrado->address.colonia;
            alumBaja->address.municipio = encontrado->address.municipio;
            alumBaja->address.numero = encontrado->address.numero;
            alumBaja->address.cp = encontrado->address.cp;
            alumBaja->inscripcion = inactivo;

            insertarEnLista(listaBajas, alumBaja);
            insertarEnPila(pila, alumBaja);
            eliminarAlumDeLista(listaAltas, encontrado);

            cout << endl << "Alumno eliminado." << endl << endl;
            break;
        }
        case 2: {
            string elimNom;
            do {
                cout << endl << "Ingrese el nombre del alumno a dar de baja: "; getline(cin, elimNom);
            } while (!validarString(elimNom) && cout << "Error: El nombre debe estar conformado solo por letras." << endl);

            alumno encontrado = busquedaPorNombre(listaAltas, elimNom);
            if (encontrado == nullptr) {
                cout << endl << "No se encontro el alumno con el nombre " << elimNom << "." << endl << endl;
                return;
            }

            alumno alumBaja = new nodo;
            alumBaja->matricula = encontrado->matricula;
            alumBaja->nombre = encontrado->nombre;
            alumBaja->edad = encontrado->edad;
            alumBaja->promedio = encontrado->promedio;
            alumBaja->situacion = baja;
            alumBaja->address.calle = encontrado->address.calle;
            alumBaja->address.colonia = encontrado->address.colonia;
            alumBaja->address.municipio = encontrado->address.municipio;
            alumBaja->address.numero = encontrado->address.numero;
            alumBaja->address.cp = encontrado->address.cp;
            alumBaja->inscripcion = inactivo;

            insertarEnLista(listaBajas, alumBaja);
            insertarEnPila(pila, alumBaja);
            eliminarAlumDeLista(listaAltas, encontrado);
            
            cout << endl << "Alumno eliminado." << endl << endl;
            break;
        }
        case 3: 
            cout << endl << "Saliendo del submenu..." << endl << endl;
            break;
        default: 
            cout << "Error: Opcion incorrecta." << endl << endl;
            break;
    }
}

void deshacerBajaParcial(alumno &pila, alumno &listaAltas, alumno &listaBajas) {
    if (pilaVacia(pila)) return;

    long matricula = pila->matricula;
    int tam = obtenerTamaño(listaBajas);
    alumno encontrado = busquedaBinaria(listaBajas, 0, tam - 1, matricula);
    if (encontrado == nullptr) {
        cout << endl << "Algo salió mal..." << endl << endl;
        return;
    }

    eliminarAlumDeLista(listaBajas, encontrado);
    alumno aux = pila;
    pila = pila->sig;
    aux->situacion = alta;
    aux->inscripcion = esperando;

    insertarEnLista(listaAltas, aux);
    
    cout << endl << "Se recupero el alumno con la matricula " << matricula << "." << endl << endl;
}

void bajaTotal(alumno &listaBajas, alumno &pila) {
    if (listaVacia(listaBajas)) {
        cout << "No hay alumnos para dar de baja." << endl << endl;
        return;
    }

    int opBusc;
    cout << endl << "Buscar por:" << endl
        << "1. Matricula." << endl
        << "2. Nombre." << endl
        << "3. Salir." << endl;
    do {
        cout << "Elija una opcion: ";
    } while (!validarInt(opBusc) && cout << "Error: La opcion debe ser entero y contener solo numeros." << endl << endl);

    alumno listaAlum;
    alumno pilaAlum;
    switch (opBusc) {
        case 1: {
            long bajaMat;
            do {
                cout << endl << "Ingrese la matricula del alumno a dar de baja: ";
            } while (!validarLong(bajaMat) && cout << "Error: La matricula debe ser positiva y contener solo numeros." << endl);
            
            listaAlum = busquedaPorMatricula(listaBajas, bajaMat);
            if (listaAlum == nullptr) {
                cout << endl << "No se encontro el alumno con la matricula " << bajaMat << "." << endl << endl;
                return;
            }
            
            eliminarAlumDeLista(listaBajas, listaAlum);
            pilaAlum = busquedaPorMatricula(pila, bajaMat);
            eliminarAlumDePila(pila, pilaAlum);

            cout << endl << "Alumno eliminado." << endl << endl;
            break;
        }
        case 2: {
            string elimNom;
            do {
                cout << endl << "Ingrese el nombre del alumno a dar de baja: "; getline(cin, elimNom);
            } while (!validarString(elimNom) && cout << "Error: El nombre debe estar conformado solo por letras." << endl);

            listaAlum = busquedaPorNombre(listaBajas, elimNom);
            if (listaAlum == nullptr) {
                cout << endl << "No se encontro el alumno con el nombre " << elimNom << "." << endl << endl;
                return;
            }

            eliminarAlumDeLista(listaBajas, listaAlum);
            pilaAlum = busquedaPorNombre(pila, elimNom);
            eliminarAlumDePila(pila, pilaAlum);
            
            cout << endl << "Alumno eliminado." << endl << endl;
            break;
        }
        case 3: 
            cout << endl << "Saliendo del submenu..." << endl << endl;
            break;
        default: 
            cout << "Error: Opcion incorrecta." << endl << endl;
            break;
    }
}
