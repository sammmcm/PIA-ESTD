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

    int conta = 0;
    for (alumno alum = listaAltas; alum; alum = alum->sig)
        if (alum->promedio >= PROMEDIO_MIN_APROBADO) conta++;

    if (conta == 0) {
        cout << endl << "No hay alumnos aprobados." << endl << endl;
        return;
    }

    cout << endl << left << setw(12) << "Matricula"
         << setw(30) << "Nombre" << "Promedio" << endl
         << string(55, '-') << endl;

    for (alumno alum = listaAltas; alum; alum = alum->sig)
        if (alum->promedio >= PROMEDIO_MIN_APROBADO)
            cout << left << setw(12) << alum->matricula
                 << setw(30) << alum->nombre
                 << fixed << setprecision(2) << alum->promedio << endl;

    cout << endl;
}

void imprimirPorcentajes(const alumno &listaAltas) {
    if (listaVacia(listaAltas)) {
        cout << "No hay alumnos activos." << endl << endl;
        return;
    }

    int total = 0, aprobados = 0;
    for (alumno alum = listaAltas; alum; alum = alum->sig) {
        total++;
        if (alum->promedio >= PROMEDIO_MIN_APROBADO) aprobados++;
    }

    if (total == 0) {
        cout << endl << "No hay alumnos registrados." << endl << endl;
        return;
    }

    double pAprob = (aprobados * 100.0) / total;
    double pReprob = 100.0 - pAprob;

    cout << fixed << setprecision(2);
    cout << endl
         << "% Aprobados : " << pAprob  << "%" << endl
         << "% Reprobados: " << pReprob << "%" << endl << endl;
}

void imprimirDatosGenerales(const alumno &listaAltas) {
    if (listaVacia(listaAltas)) {
        cout << "No hay alumnos activos." << endl << endl;
        return;
    }

    cout << endl << left << setw(32) << "Nombre"
         << setw(6) << "Edad"
         << setw(11) << "Matricula"
         << "Direccion" << endl
         << string(98, '-') << endl;

    for (alumno alum = listaAltas; alum; alum = alum->sig)
        cout << left << setw(32) << alum->nombre
             << setw(6) << alum->edad
             << setw(11) << alum->matricula 
             << alum->address.calle << " #"
             << alum->address.numero << ", Col. "
             << alum->address.colonia << ", "
             << alum->address.municipio << " CP "
             << alum->address.cp << endl;
    cout << endl;
}

void imprimirAlumnosInactivos(const alumno &listaBajas) {
    if (listaVacia(listaBajas)) {
        cout << "No hay alumnos inactivos." << endl << endl;
        return;
    }

    cout << endl << left << setw(12) << "Matricula" << "Nombre" << endl << string(45, '-') << endl;
    for (alumno alum = listaBajas; alum; alum = alum->sig)
        cout << left << setw(12) << alum->matricula << alum->nombre << endl;

    cout << endl;
}
