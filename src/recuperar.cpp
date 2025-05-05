#include <iostream>
#include "../include/recuperar.h"
#include "../include/baja.h"
using namespace std;

/*
 * mueve un alumno desde la lista de bajas parciales a la lista de activos.
 * se desvincula el nodo sin eliminarlo para reutilizarlo
 */
void recuperarAlumno(alumno &listaAltas, alumno &listaBajas, alumno &pilaBajas)
{
    if (listaVacia(listaBajas)) return;

    int opcBusq;
    cout << endl
         << "buscar por:" << endl
         << "1. matricula" << endl
         << "2. nombre" << endl;

    do {
        cout << "elige una opcion: ";
    } while (!validarInt(opcBusq) &&
             cout << "error: la opcion debe ser un numero." << endl << endl);

    alumno hallado = nullptr;

    switch (opcBusq) {
        case 1: {
            long mat;
            do {
                cout << endl << "ingresa la matricula: ";
            } while (!validarLong(mat) &&
                     cout << "error: la matricula debe ser numerica." << endl);
            int tam = obtenerTamaño(listaBajas);
            hallado = busquedaBinaria(listaBajas, 0, tam - 1, mat);
            break;
        }
        case 2: {
            string nom;
            do {
                cout << endl << "ingresa el nombre: ";
                getline(cin, nom);
            } while (!validarString(nom) &&
                     cout << "error: el nombre debe ser solo letras." << endl);
            hallado = busquedaPorNombre(listaBajas, nom);
            break;
        }
        default:
            cout << "error: opcion incorrecta." << endl;
            return;
    }

    if (!hallado) {
        cout << endl << "alumno no encontrado." << endl << endl;
        return;
    }

    /* -------- desvincular de listaBajas SIN liberar -------- */
    if (listaBajas == hallado) {
        listaBajas = listaBajas->sig;
    } else {
        alumno ant = listaBajas;
        while (ant->sig && ant->sig != hallado) ant = ant->sig;
        if (ant->sig == hallado) ant->sig = hallado->sig;
    }
    hallado->sig = nullptr;   // evitamos referencias colgantes
    /* ------------------------------------------------------- */

    // quitamos la copia del alumno en la pila de bajas
    alumno copiaPila = (opcBusq == 1)
                       ? busquedaPorMatricula(pilaBajas, hallado->matricula)
                       : busquedaPorNombre(pilaBajas, hallado->nombre);

    if (copiaPila) eliminarAlumDePila(pilaBajas, copiaPila);

    // reinsertamos el nodo en la lista de activos
    hallado->situacion = alta;
    insertarEnLista(listaAltas, hallado);
    mergeSort(listaAltas);

    cout << endl << "alumno recuperado con exito." << endl << endl;
}
