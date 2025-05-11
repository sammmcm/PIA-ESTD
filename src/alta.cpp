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
    } while (!validarLong(nuevo->matricula) && cout << "Error: La matricula debe ser positiva y contener solo numeros." << endl);
    do {
        cout << endl << "Ingrese el nombre: "; getline(cin, nuevo->nombre);
    } while (!validarString(nuevo->nombre) && cout << "Error: El nombre debe estar conformado solo por letras." << endl);
    do {
        cout << endl << "Ingrese la edad: ";
    } while (!validarInt(nuevo->edad) && cout << "Error: La edad debe ser positiva y contener solo numeros." << endl);
    do {
        cout << endl << "Ingrese el promedio general: ";
    } while (!validarDouble(nuevo->promedio) && cout << "Error: El promedio debe ser positiva y contener solo numeros." << endl);
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
    } while (!validarInt(nuevo->address.numero) && cout << "Error: El numero debe ser positivo y contener solo numeros." << endl << endl);
    do {
        cout << "CP: ";
    } while (!validarInt(nuevo->address.cp) && cout << "Error: El CP debe ser positivo y contener solo numeros." << endl << endl);
    nuevo->inscripcion = esperando;

    return nuevo;
}
