#include <iostream>
#include <string>
#include "modificacion.h"
#include "validaciones.h"
#include "alta.h"

using namespace std;

void modificarAlumno(alumno encontrado) {
    cout << "\nAlumno encontrado:" << endl;
    cout << "Nombre: " << encontrado->nombre << endl;
    cout << "Edad: " << encontrado->edad << endl;
    cout << "Promedio: " << encontrado->promedio << endl;
    cout << "Dirección: " << encontrado->address.calle << ", "
         << encontrado->address.colonia << ", "
         << encontrado->address.municipio << ", #"
         << encontrado->address.numero << ", CP "
         << encontrado->address.cp << endl;

    int opcionMod;
    do {
        cout << "\n¿Qué desea modificar?" << endl;
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
            cout << "Opción: ";
        } while (!validarInt(opcionMod) && cout << "Error: debe ingresar un número válido.\n");

        switch (opcionMod) {
            case 1: {
                cout << "Nuevo nombre: ";
                cin.ignore();
                getline(cin, encontrado->nombre);
                break;
            }
            case 2: {
                do {
                    cout << "Nueva edad: ";
                } while (!validarInt(encontrado->edad) && cout << "Error: edad inválida.\n");
                break;
            }
            case 3: {
                do {
                    cout << "Nuevo promedio: ";
                } while (!validarDouble(encontrado->promedio) && cout << "Error: promedio inválido.\n");
                break;
            }
            case 4: {
                cout << "Nueva calle: ";
                cin.ignore();
                getline(cin, encontrado->address.calle);
                break;
            }
            case 5: {
                cout << "Nueva colonia: ";
                cin.ignore();
                getline(cin, encontrado->address.colonia);
                break;
            }
            case 6: {
                cout << "Nuevo municipio: ";
                cin.ignore();
                getline(cin, encontrado->address.municipio);
                break;
            }
            case 7: {
                do {
                    cout << "Nuevo número de domicilio: ";
                } while (!validarInt(encontrado->address.numero) && cout << "Error: número inválido.\n");
                break;
            }
            case 8: {
                do {
                    cout << "Nuevo código postal: ";
                } while (!validarInt(encontrado->address.cp) && cout << "Error: CP inválido.\n");
                break;
            }
            case 9:
                cout << "Saliendo del menú de modificación." << endl;
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcionMod != 9);
}

