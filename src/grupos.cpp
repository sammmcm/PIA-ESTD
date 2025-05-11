#include <iostream>
#include "alta.h"
#include "grupos.h"
#include "listas.h"
#include "validaciones.h"

using namespace std;

int contarAlumnosActivos(alumno listaAlta) {
    int contador = 0;
    while (listaAlta != nullptr) {
        if (listaAlta->situacion == alta) {
            contador++;
        }
        listaAlta = listaAlta->sig;
    }

    return contador;
}

void crearGrupos(alumno listaAlta) {
    if (listaVacia(listaAlta)) {
        cout << "No hay alumnos para crear grupos." << endl << endl;
        return;
    }

    int numGrupos;
    do {
        cout << "\nIngrese la cantidad de grupos a crear: ";
    } while ((!validarInt(numGrupos) || numGrupos == 0) && cout << "Error: La cantidad debe ser mayor a 0 y contener solo numeros." << endl);

    int totalAlumnos = contarAlumnosActivos(listaAlta);
    if (totalAlumnos < numGrupos) {
        cout << "Error: No se pueden crear " << numGrupos << " grupos con " << totalAlumnos << " alumnos. Intentelo de nuevo." << endl << endl;
        return;
    }

    int base = totalAlumnos / numGrupos;
    int extra = totalAlumnos % numGrupos;
    
    alumno actual = listaAlta;
    for (int g = 0; g < numGrupos; g++) {
        int cantidadGrupo = base + (extra > 0 ? 1 : 0);
        cout << "\nGrupo " << (g + 1) << endl;
        while (actual != nullptr && cantidadGrupo > 0) {
            cout << "" << actual->nombre << " " << actual->matricula << endl;
            actual = actual->sig;
            cantidadGrupo--;
        }
        if (extra > 0) extra--;
    }
    cout << endl;
}
