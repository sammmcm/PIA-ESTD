#include <iostream>
#include <string>
#include "modificacion.h"
#include "validaciones.h"
#include "alta.h"
#include "inscripcion.h"

using namespace std;
ostream& operator<<(ostream& os, const insc& estado) {
    switch(estado) {
        case esperando: os << "esperando"; break;
        case inactivo: os << "inactivo"; break;
        case inscrito: os << "inscrito"; break;
        default: os << "desconocido"; break;
    }
    return os;
}

void modificarAlumno(alumno encontrado) {
    cout << "\nAlumno encontrado:" << endl;
    cout << "Nombre: " << encontrado->nombre << endl;
    cout << "Edad: " << encontrado->edad << endl;
    cout << "Promedio: " << encontrado->promedio << endl;
    cout << "Direccion: " << encontrado->address.calle << ", "
         << encontrado->address.colonia << ", "
         << encontrado->address.municipio << ", #"
         << encontrado->address.numero << ", CP "
         << encontrado->address.cp << endl;
    cout << "Estatus de inscripcion: " << encontrado->inscripcion << endl;

    int opcionMod;
    do {
        cout << "\nASPECTO A MODIFICAR: " << endl;
        cout << "1. Nombre" << endl;
        cout << "2. Edad" << endl;
        cout << "3. Promedio" << endl;
        cout << "4. Calle" << endl;
        cout << "5. Colonia" << endl;
        cout << "6. Municipio" << endl;
        cout << "7. Número de domicilio" << endl;
        cout << "8. Código postal" << endl;
        cout << "9. Salir" << endl;

        do {
            cout << "Opcion: ";
        } while (!validarInt(opcionMod) && cout << "Error: debe ingresar un numero válido.\n");

        switch (opcionMod) {
            case 1: {
                do {
                    cout << "Nuevo nombre: "; getline(cin, encontrado->nombre);
                } while (!validarString(encontrado->nombre) && cout << "Error: El nombre debe ser solo letras." << endl);
                cout << "El nombre ha sido cambiado a "<< encontrado->nombre << endl;
                break;
            }
            case 2: {
                do {
                    cout << "Nueva edad: ";
                } while (!validarInt(encontrado->edad) && cout << "Error: edad invalida.\n");
                cout << "La edad a sido cambiada a "<< encontrado->edad << endl;
                break;
            }
            case 3: {
                do {
                    cout << "Nuevo promedio: ";
                } while (!validarDouble(encontrado->promedio) && cout << "Error: promedio invalido.\n");
                cout << "El promedio ha sido cambiado a "<< encontrado->promedio << endl;
                break;
            }
            case 4: {
                do {
                    cout << "Nueva calle: "; getline(cin, encontrado->address.calle);
                } while (!validarString(encontrado->address.calle) && cout << "Error: La calle debe ser solo letras." << endl);
                cout << "La calle ha sido cambiada a "<< encontrado->address.calle << endl;
                break;
            }
            case 5: {
                do {
                    cout << "Nueva colonia: "; getline(cin, encontrado->address.colonia);
                } while (!validarString(encontrado->address.colonia) && cout << "Error: La colonia debe ser solo letras." << endl);
                cout << "La colonia ha sida cambiado a "<< encontrado->address.colonia << endl;
                break;
            }
            case 6: {
                do {
                cout << "Nuevo municipio: "; getline(cin, encontrado->address.municipio);
                } while (!validarString(encontrado->address.municipio) && cout << "Error: El municipio debe ser solo letras." << endl);
                cout << "El municipio ha sido cambiado a "<< encontrado->address.municipio << endl;
                break;
            }
            case 7: {
                do {
                    cout << "Nuevo numero de domicilio: ";
                } while (!validarInt(encontrado->address.numero) && cout << "Error: numero invalido.\n");
                cout << "El numero de domiciliio ha sido cambiado a "<< encontrado->address.numero << endl;
                break;
            }
            case 8: {
                do {
                    cout << "Nuevo codigo postal: ";
                } while (!validarInt(encontrado->address.cp) && cout << "Error: CP invalido.\n");
                cout << "El codigo postal ha sido cambiado a "<< encontrado->address.cp << endl;
                break;
            }
            case 9:
                cout << "Saliendo del menu de modificacion." << endl;
                break;
            default:
                cout << "Opcion invalida." << endl;
        }
    } while (opcionMod != 9);
}
