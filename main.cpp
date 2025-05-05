#include <iostream>
#include "validaciones.h"
#include "alta.h"
#include "baja.h"
#include "listas.h"
#include "pilas.h"
#include "modificacion.h"

using namespace std;

int main() {
    int op, opsubmenu;
    alumno listaAltas = nullptr;
    alumno listaBajas = nullptr;
    alumno pilaBajas = nullptr;

    do {
        cout << "\tMENU" << endl
             << "1. Alta de alumnos." << endl
             << "2. Baja de estudiantes." << endl
             << "3. Recuperar alumno." << endl
             << "4. Reportes." << endl
             << "5. Modificacion de datos en alumnos activos." << endl
             << "6. Control de inscripciones." << endl
             << "7. Creacion de grupos." << endl
             << "8. Salir." << endl;

        do {
            cout << "Elija una opcion: ";
        } while (!validarInt(op) && cout << "Error: La opcion debe ser un numero." << endl << endl);

        switch (op) {
            case 1: {
                alumno nuevo = altaAlum(listaAltas);
                insertarEnLista(listaAltas, nuevo);
                mergeSort(listaAltas);
                break;
            }
            case 2:
                cout << endl;
                do {
                    cout << "\tSUBMENU" << endl
                         << "1. Baja parcial." << endl
                         << "2. Deshacer baja parcial." << endl
                         << "3. Baja total." << endl
                         << "4. Salir." << endl;

                    do {
                        cout << "Elija una opcion: ";
                    } while (!validarInt(opsubmenu) && cout << "Error: La opcion debe ser un numero." << endl << endl);

                    switch (opsubmenu) {
                        case 1: {
                            bajaParcial(listaAltas, listaBajas, pilaBajas);
                            mergeSort(listaBajas);
                            system("pause"); system("cls");
                            break;
                        }
                        case 2:
                            deshacerBajaParcial(pilaBajas, listaAltas, listaBajas);
                            mergeSort(listaAltas);
                            system("pause"); system("cls");
                            break;
                        case 3:
                            bajaTotal(listaBajas, pilaBajas);
                            system("pause"); system("cls");
                            break;
                        case 4:
                            cout << endl << "Saliendo del submenu..." << endl << endl;
                            break;
                        default:
                            cout << "Error: Opcion incorrecta." << endl << endl;
                            system("pause"); system("cls");
                            break;
                    }
                } while (opsubmenu != 4);
                break;
            case 3:
                break;
            case 4:
                do {
                    cout << "\n\tSUBMENU" << endl
                         << "1. Alumnos aprobados." << endl
                         << "2. Porcentajes." << endl
                         << "3. Datos generales." << endl
                         << "4. Alumnos inactivos." << endl
                         << "5. Salir." << endl;
                    do {
                        cout << "Elija una opcion: ";
                    } while (!validarInt(opsubmenu) && cout << "Error: La opcion debe ser un numero." << endl << endl);

                    switch (opsubmenu) {
                        case 1:
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        case 4:
                            break;
                        case 5:
                            cout << "Saliendo del submenu..." << endl;
                            break;
                        default: cout << "Error: Opcion incorrecta." << endl; break;
                    }
                    system("pause"); system("cls");
                } while (opsubmenu != 5);
                break;
            case 5: {
                int opcionBusqueda;
                alumno encontrado = nullptr;

                cout << "\nMODIFICACION DE DATOS DE ALUMNO" << endl;
                cout << "1. Buscar por matricula" << endl;
                cout << "2. Buscar por nombre" << endl;

                do {
                    cout << "Seleccione una opcion: ";
                } while (!validarInt(opcionBusqueda) && cout << "Error: opcion invalida.\n");

                if (opcionBusqueda == 1) {
                    long mat;
                    do {
                        cout << "Ingrese matricula: ";
                    } while (!validarLong(mat) && cout << "Error: matricula invalida.\n");
                    encontrado = busquedaPorMatricula(listaAltas, mat);
                } else if (opcionBusqueda == 2) {
                    string nombre;
                    do {
                        cout << "Ingrese nombre: "; getline(cin, nombre);
                    } while (!validarString(nombre) && cout << "Error: El nombre debe ser solo letras." << endl);
                    encontrado = busquedaPorNombre(listaAltas, nombre);
                }

                if (!encontrado) {
                    cout << "Alumno no encontrado." << endl;
                } else {
                    modificarAlumno(encontrado);
                }

                system("pause");
                system("cls");
                break;
            }
            case 6:
                break;
            case 7:
                break;
            case 8:
                eliminarLista(listaAltas);
                eliminarLista(listaBajas);
                eliminarPila(pilaBajas);
                cout << endl << "Saliendo del programa..." << endl << endl;
                break;
            default:
                cout << "Error: Opcion incorrecta." << endl << endl;
                break;
        }
        system("pause"); system("cls");
    } while (op != 8);

    return 0;
}
