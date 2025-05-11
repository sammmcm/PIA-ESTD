#include <iostream>
#include "alta.h"
#include "grupos.h"

using namespace std;

int contarAlumnosActivos(alumno lista) {
    int contador = 0;
    while (lista != nullptr) {
        if (lista->situacion == alta) {
            contador++;
        }
        lista = lista->sig;
    }
    return contador;
}

void crearGrupos(alumno lista) {
    int numGrupos;
    cout << "\nCantidad de grupos a crear: ";
    cin >> numGrupos;

    int totalAlumnos = contarAlumnosActivos(lista);

    if (numGrupos <= 0 || totalAlumnos == 0) {
        cout << "\n - Debe haber al menos 1 alumno para crear un grupo -\n" << endl;
        return;
    }

    int base = totalAlumnos / numGrupos;
    int extra = totalAlumnos % numGrupos;

    alumno alumnos[totalAlumnos];
    int i = 0;

    alumno actual = lista;
    while (actual != nullptr) {
        if (actual->situacion == alta) {
            alumnos[i++] = actual;
        }
        actual = actual->sig;
    }

    int index = 0;

    for (int g = 0; g < numGrupos; g++) {
        int cantidadGrupo = base + (extra > 0 ? 1 : 0);
        cout << "\nGrupo " << (g + 1) << ":" << endl;
        for (int j = 0; j < cantidadGrupo; j++) {
            cout << "Matricula: " << alumnos[index]->matricula
                 << ", Nombre: " << alumnos[index]->nombre << endl;
            index++;
        }
        if (extra > 0) extra--;
    }
}
