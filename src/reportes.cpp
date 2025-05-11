#include <iostream>
#include <iomanip>
#include "listas.h"
#include "reportes.h"

using namespace std;

const double PROMEDIO_MIN_APROBADO = 70.0;

void imprimirAlumnosAprobados(const alumno &listaAltas) {
    if (listaVacia(listaAltas)) {
        cout << "No hay alumnos activos." << endl << endl;
        return;
    }

    /* contamos primero para saber si existe al menos un aprobado */
    int conta = 0;
    for (alumno a = listaAltas; a; a = a->sig)
        if (a->promedio >= PROMEDIO_MIN_APROBADO) conta++;

    if (conta == 0) {
        cout << endl << "No hay alumnos aprobados." << endl << endl;
        return;
    }

    /* ahora si imprimimos la tabla */
    cout << endl << left << setw(12) << "Matricula"
         << setw(30) << "Nombre" << "Promedio" << endl
         << string(55, '-') << endl;

    for (alumno a = listaAltas; a; a = a->sig)
        if (a->promedio >= PROMEDIO_MIN_APROBADO)
            cout << left << setw(12) << a->matricula
                 << setw(30) << a->nombre
                 << fixed << setprecision(2) << a->promedio << endl;

    cout << endl;
}

void imprimirPorcentajes(const alumno &listaAltas) {
    if (listaVacia(listaAltas)) {
        cout << "No hay alumnos activos." << endl << endl;
        return;
    }

    int total = 0, aprobados = 0;
    for (alumno a = listaAltas; a; a = a->sig) {
        total++;
        if (a->promedio >= PROMEDIO_MIN_APROBADO) aprobados++;
    }

    if (total == 0) {                       // proteccion extra
        cout << endl << "No hay alumnos registrados." << endl << endl;
        return;
    }

    double pAprob = (aprobados * 100.0) / total;
    double pReprob = 100.0 - pAprob;

    cout << fixed << setprecision(2);
    cout << endl
         << "% aprobados : " << pAprob  << "%" << endl
         << "% reprobados: " << pReprob << "%" << endl << endl;
}

void imprimirDatosGenerales(const alumno &listaAltas) {
    if (listaVacia(listaAltas)) {
        cout << "No hay alumnos activos." << endl << endl;
        return;
    }

    cout << endl << left << setw(30) << "Nombre"
         << setw(6)  << "Edad"
         << "Direccion" << endl
         << string(90, '-') << endl;

    for (alumno a = listaAltas; a; a = a->sig)
        cout << left << setw(30) << a->nombre
             << setw(6)  << a->edad
             << a->address.calle << ", "
             << a->address.colonia << ", "
             << a->address.municipio << " #"
             << a->address.numero << ", CP "
             << a->address.cp << endl;
    cout << endl;
}

void imprimirAlumnosInactivos(const alumno &listaBajas) {
    if (listaBajas == nullptr) {
        cout << "No hay alumnos inactivos." << endl << endl;
        return;
    }

    cout << endl << left << setw(12) << "Matricula" << "Nombre" << endl << string(42, '-') << endl;

    for (alumno a = listaBajas; a; a = a->sig)
        cout << left << setw(12) << a->matricula << a->nombre << endl;

    cout << endl;
}
