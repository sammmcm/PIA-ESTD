#include <iostream>
#include "alta.h"
#include "listas.h"
#include "validaciones.h"

using namespace std;

alumno altaAlum() {
    alumno nuevo = new nodo;
    string entrada;
    do {
        cout << endl << "Ingrese la matricula: ";
    } while (!validarLong(nuevo->matricula) && cout << "Error: La matricula debe ser un numero positivo de 7 digitos" << endl);
    do {
        cout << endl << "Ingrese el nombre: "; getline(cin, nuevo->nombre);
    } while (!validarString(nuevo->nombre) && cout << "Error: El nombre debe estar conformado solo por letras." << endl);
    do {
        cout << endl << "Ingrese la edad: ";
    } while ((!validarInt(nuevo->edad) || nuevo->edad < 5 || nuevo->edad > 100) && cout << "Error: La edad debe ser un numero positivo entre 5 y 100 años." << endl);
    do {
        cout << endl << "Ingrese el promedio general: ";
    } while ((!validarDouble(nuevo->promedio) || nuevo->promedio > 100) && cout << "Error: El promedio debe ser un numero positivo entre 0 y 100." << endl);
    nuevo->situacion = alta;
    cout << endl<< "Ingrese su direccion:" << endl;
    do {
        cout << "Calle: "; getline(cin, nuevo->address.calle);
    } while (!validarString(nuevo->address.calle) && cout << "Error: La calle debe estar conformado solo por letras." << endl << endl);
    do {
        cout << "Colonia: "; getline(cin, nuevo->address.colonia);
    } while (!validarString(nuevo->address.colonia) && cout << "Error: La colonia debe estar conformado solo por letras." << endl << endl);
    do {
        cout << "Municipio: "; getline(cin, nuevo->address.municipio);
    } while (!validarString(nuevo->address.municipio) && cout << "Error: El municipio debe estar conformado solo por letras." << endl << endl);
    do {
        cout << "Numero: ";
    } while ((!validarInt(nuevo->address.numero) || nuevo->address.numero < 100 && nuevo->address.numero > 999) && cout << "Error: El numero debe ser un numero positivo de 3 digitos." << endl << endl);
    do {
        cout << "CP: ";
    } while ((!validarInt(nuevo->address.cp) || nuevo->address.cp < 10000 && nuevo->address.cp > 99999)  && cout << "Error: El CP debe ser un numero positivo de 5 digitos." << endl << endl);
    nuevo->inscripcion = esperando;

    return nuevo;
}
