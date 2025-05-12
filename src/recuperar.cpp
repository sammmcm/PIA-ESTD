#include <iostream>
#include "baja.h"
#include "listas.h"
#include "pilas.h"
#include "recuperar.h"
#include "validaciones.h"

using namespace std;

void recuperarAlumno(alumno &listaAltas, alumno &listaBajas, alumno &pilaBajas) {
    if (listaVacia(listaBajas)) {
        cout << "No hay alumnos para recuperar." << endl << endl;
        return;
    }

    int opcBusq;
    cout << endl << "Buscar por:" << endl
         << "1. Matricula." << endl
         << "2. Nombre." << endl
         << "3. Salir." << endl;
    do {
        cout << "Elija una opcion: ";
    } while (!validarInt(opcBusq) && cout << "Error: La opcion debe ser entero y contener solo numeros." << endl << endl);

    alumno hallado = nullptr;

    switch (opcBusq) {
        case 1: {
            long mat;
            do {
                cout << endl << "Ingrese la matricula del alumno a recuperar: ";
            } while (!validarLong(mat) && cout << "Error: La matricula debe ser un numero positivo de 7 digitos." << endl);

            int tam = obtenerTamaño(listaBajas);
            hallado = busquedaBinaria(listaBajas, 0, tam - 1, mat);
            break;
        }
        case 2: {
            string nom;
            do {
                cout << endl << "Ingrese el nombre del alumno a recuperar: "; getline(cin, nom);
            } while (!validarString(nom) && cout << "Error: El nombre debe estar conformado solo por letras." << endl);

            hallado = busquedaPorNombre(listaBajas, nom);
            break;
        }
        case 3: 
            cout << endl << "Saliendo del submenu..." << endl << endl;
            break;
        default:
            cout << "Error: Opcion incorrecta." << endl << endl;
            break;;
    }

    if (!hallado) {
        cout << endl << "Alumno no encontrado." << endl << endl;
        return;
    }

    if (listaBajas == hallado) {
        listaBajas = listaBajas->sig;
    } else {
        alumno ant = listaBajas;
        while (ant->sig && ant->sig != hallado) ant = ant->sig;
        if (ant->sig == hallado) ant->sig = hallado->sig;
    }
    hallado->sig = nullptr;

    alumno copiaPila = (opcBusq == 1)
                       ? busquedaPorMatricula(pilaBajas, hallado->matricula)
                       : busquedaPorNombre(pilaBajas, hallado->nombre);

    if (copiaPila) eliminarAlumDePila(pilaBajas, copiaPila);

    hallado->situacion = alta;
    hallado->inscripcion = esperando;
    insertarEnLista(listaAltas, hallado);
    mergeSort(listaAltas);

    cout << endl << "Alumno recuperado con exito." << endl << endl;
}
