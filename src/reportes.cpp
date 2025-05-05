#include <iostream>
#include <iomanip>
#include "reportes.h"

using namespace std;

const double PROMEDIO_MIN_APROBADO = 70.0;

void imprimirAlumnosAprobados(const alumno &listaAltas)
{
    if (listaAltas == nullptr) {
        cout << endl << "no hay alumnos activos." << endl << endl;
        return;
    }

    /* contamos primero para saber si existe al menos un aprobado */
    int conta = 0;
    for (alumno a = listaAltas; a; a = a->sig)
        if (a->promedio >= PROMEDIO_MIN_APROBADO) conta++;

    if (conta == 0) {
        cout << endl << "no hay alumnos aprobados." << endl << endl;
        return;
    }

    /* ahora si imprimimos la tabla */
    cout << endl << left << setw(12) << "matricula"
         << setw(30) << "nombre" << "promedio" << endl
         << string(55, '-') << endl;

    for (alumno a = listaAltas; a; a = a->sig)
        if (a->promedio >= PROMEDIO_MIN_APROBADO)
            cout << left << setw(12) << a->matricula
                 << setw(30) << a->nombre
                 << fixed << setprecision(2) << a->promedio << endl;

    cout << endl;
}

void imprimirPorcentajes(const alumno &listaAltas)
{
    if (listaAltas == nullptr) {
        cout << endl << "no hay alumnos activos." << endl << endl;
        return;
    }

    int total = 0, aprobados = 0;
    for (alumno a = listaAltas; a; a = a->sig) {
        total++;
        if (a->promedio >= PROMEDIO_MIN_APROBADO) aprobados++;
    }

    if (total == 0) {                       // proteccion extra
        cout << endl << "no hay alumnos registrados." << endl << endl;
        return;
    }

    double pAprob = (aprobados * 100.0) / total;
    double pReprob = 100.0 - pAprob;

    cout << fixed << setprecision(2);
    cout << endl
         << "% aprobados : " << pAprob  << "%" << endl
         << "% reprobados: " << pReprob << "%" << endl << endl;
}

void imprimirDatosGenerales(const alumno &listaAltas)
{
    if (listaAltas == nullptr) {
        cout << endl << "no hay alumnos activos." << endl << endl;
        return;
    }

    cout << endl << left << setw(30) << "nombre"
         << setw(6)  << "edad"
         << "direccion" << endl
         << string(80, '-') << endl;

    for (alumno a = listaAltas; a; a = a->sig)
        cout << left << setw(30) << a->nombre
             << setw(6)  << a->edad
             << a->address.calle << ", "
             << a->address.colonia << ", "
             << a->address.municipio << " #"
             << a->address.numero << ", cp "
             << a->address.cp << endl;
    cout << endl;
}

void imprimirAlumnosInactivos(const alumno &listaBajas)
{
    if (listaBajas == nullptr) {
        cout << endl << "no hay alumnos inactivos." << endl << endl;
        return;
    }

    cout << endl << left << setw(12) << "matricula" << "nombre" << endl << string(42, '-') << endl;

    for (alumno a = listaBajas; a; a = a->sig)
        cout << left << setw(12) << a->matricula << a->nombre << endl;

    cout << endl;
}
