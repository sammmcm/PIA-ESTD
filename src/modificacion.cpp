#include <iostream>
#include <string>
#include "alta.h"
#include "inscripcion.h"
#include "modificacion.h"
#include "validaciones.h"

using namespace std;

ostream& operator<<(ostream& os, const insc& estado) {
    switch(estado) {
        case esperando: os << "Esperando"; break;
        case inactivo: os << "Inactivo"; break;
        case inscrito: os << "Inscrito"; break;
        default: os << "Desconocido"; break;
    }
    return os;
}

void modificarAlumno(alumno encontrado) {
    cout << "\nAlumno encontrado" << endl;
    cout << "Nombre: " << encontrado->nombre << endl;
    cout << "Edad: " << encontrado->edad << endl;
    cout << "Promedio: " << encontrado->promedio << endl;
    cout << "Direccion: " << encontrado->address.calle << " #"
         << encontrado->address.numero << ", Col. "
         << encontrado->address.colonia << ", "
         << encontrado->address.municipio << ", CP "
         << encontrado->address.cp << endl;
    cout << "Estatus de inscripcion: " << encontrado->inscripcion << endl;

    int opcionMod;
    cout << endl;
    do {
        cout << "Elija la opcion a modificar:" << endl
             << "1. Matricula." << endl
             << "2. Nombre." << endl
             << "3. Edad " << endl
             << "4. Promedio." << endl
             << "5. Calle." << endl
             << "6. Colonia." << endl
             << "7. Municipio." << endl
             << "8. Numero de domicilio." << endl
             << "9. Codigo postal." << endl
             << "10. Salir." << endl;

        do {
            cout << "Elija una opcion: ";
        } while (!validarInt(opcionMod) && cout << "Error: La opcion debe ser entero y contener solo numeros." << endl << endl);

        switch (opcionMod) {
            case 1:
                do {
                    cout << endl << "Ingrese la nueva matricula: ";
                } while (!validarLong(encontrado->matricula) && cout << "Error: La matricula debe ser un numero positivo de 7 digitos." << endl);
                cout << endl;
                system("pause"); system("cls");
                break;
            case 2:
                do {
                    cout << endl << "Ingrese el nuevo nombre: "; getline(cin, encontrado->nombre);
                } while (!validarString(encontrado->nombre) && cout << "Error: El nombre debe estar conformado solo por letras." << endl);
                cout << endl;
                system("pause"); system("cls");
                break;
            case 3:
                do {
                    cout << endl << "Ingrese la nueva edad: ";
                } while ((!validarInt(encontrado->edad) || encontrado->edad < 5 || encontrado->edad > 100) && cout << "Error: La edad debe ser un numero positivo entre 5 y 100 años." << endl);
                cout << endl;
                system("pause"); system("cls");
                break;
            case 4:
                do {
                    cout << endl << "Ingrese el nuevo promedio: ";
                } while ((!validarDouble(encontrado->promedio) || encontrado->promedio > 100) && cout << "Error: El promedio debe ser un numero positivo entre 0 y 100." << endl);
                cout << endl;
                system("pause"); system("cls");
                break;
            case 5: 
                do {
                    cout << endl << "Ingrese la nueva calle: "; getline(cin, encontrado->address.calle);
                } while (!validarString(encontrado->address.calle) && cout << "Error: La calle debe estar conformado solo por letras." << endl);
                cout << endl;
                system("pause"); system("cls");
                break;
            case 6:
                do {
                    cout << endl << "Ingrese la nueva colonia: "; getline(cin, encontrado->address.colonia);
                } while (!validarString(encontrado->address.colonia) && cout << "Error: La colonia debe estar conformado solo por letras." << endl);
                cout << endl;
                system("pause"); system("cls");
                break;
            case 7:
                do {
                    cout << endl << "Ingrese el nuevo municipio: "; getline(cin, encontrado->address.municipio);
                } while (!validarString(encontrado->address.municipio) && cout << "Error: El municipio debe estar conformado solo por letras." << endl);
                cout << endl;
                system("pause"); system("cls");
                break;
            case 8:
                do {
                    cout << endl << "Ingrese el nuevo numero de domicilio: ";
                } while ((!validarInt(encontrado->address.numero) || encontrado->address.numero < 100 && encontrado->address.numero > 999) && cout << "Error: El numero debe ser un numero positivo de 3 digitos." << endl);
                cout << endl;
                system("pause"); system("cls");
                break;
            case 9:
                do {
                    cout << endl << "Ingrese el nuevo codigo postal: ";
                } while ((!validarInt(encontrado->address.cp) || encontrado->address.cp < 10000 && encontrado->address.cp > 99999)  && cout << "Error: El CP debe ser un numero positivo de 5 digitos." << endl);
                cout << endl;
                system("pause"); system("cls");
                break;
            case 10:
                cout << endl << "Saliendo del submenu..." << endl << endl;
                break;
            default:
                cout << "Error: Opcion incorrecta." << endl << endl;
                system("pause"); system("cls");
                break;
        }
    } while (opcionMod != 10);
}
