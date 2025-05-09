#include <iostream>
#include <string>
#include "alta.h"
#include "inscripcion.h"
#include "modificacion.h"
#include "validaciones.h"

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
        cout << "\nQue desea modificar?" << endl;
        cout << "1. Nombre." << endl;
        cout << "2. Edad " << endl;
        cout << "3. Promedio." << endl;
        cout << "4. Calle." << endl;
        cout << "5. Colonia." << endl;
        cout << "6. Municipio." << endl;
        cout << "7. Numero de domicilio." << endl;
        cout << "8. Codigo postal." << endl;
        cout << "9. Salir." << endl;

        do {
            cout << "Elija una opcion: ";
        } while (!validarInt(opcionMod) && cout << "Error: La opcion debe ser entero y contener solo numeros.\n");

        switch (opcionMod) {
            case 1: {
                do {
                    cout << endl << "Ingrese el nuevo nombre: "; getline(cin, encontrado->nombre);
                } while (!validarString(encontrado->nombre) && cout << "Error: El nombre debe estar conformado solo por letras." << endl);
                break;
            }
            case 2: {
                do {
                    cout << "Ingrese la nueva edad: ";
                } while (!validarInt(encontrado->edad) && cout << "Error: La edad debe ser positiva y contener solo numeros.\n");
                break;
            }
            case 3: {
                do {
                    cout << "Ingrese el nuevo promedio: ";
                } while (!validarDouble(encontrado->promedio) && cout << "Error: El promedio debe ser positiva y contener solo numeros.\n");
                break;
            }
            case 4: {
                do {
                    cout << "Ingrese la nueva calle: "; getline(cin, encontrado->address.calle);
                } while (!validarString(encontrado->address.calle) && cout << "Error: La calle debe estar conformado solo por letras." << endl << endl);
                break;
            }
            case 5: {
                do {
                    cout << "Ingrese la nueva colonia: "; getline(cin, encontrado->address.colonia);
                } while (!validarString(encontrado->address.colonia) && cout << "Error: La colonia debe estar conformado solo por letras." << endl << endl);
                break;
            }
            case 6: {
                do {
                    cout << "Ingrese el nuevo municipio: "; getline(cin, encontrado->address.municipio);
                } while (!validarString(encontrado->address.municipio) && cout << "Error: El municipio debe estar conformado solo por letras." << endl << endl);
                break;
            }
            case 7: {
                do {
                    cout << "Ingrese el nuevo numero de domicilio: ";
                } while (!validarInt(encontrado->address.numero) && cout << "Error: El numero debe ser positivo y contener solo numeros.\n");
                break;
            }
            case 8: {
                do {
                    cout << "Ingrese el nuevo codigo postal: ";
                } while (!validarInt(encontrado->address.cp) && cout << "Error: El CP debe ser positivo y contener solo numeros.\n");
                break;
            }
            case 9:
                cout << "Saliendo del submenu..." << endl;
                break;
            default:
                cout << "Error: Opcion incorrecta." << endl;
                break;
        }
    } while (opcionMod != 9);
}
