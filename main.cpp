#include <iostream>
#include "include/alta.h"
#include "include/baja.h"
#include "include/listas.h"
#include "include/modificacion.h"
#include "include/pilas.h"
#include "include/recuperar.h"
#include "include/reportes.h"
#include "include/validaciones.h"
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
                            system("pause");
                            system("cls");
                            break;
                        }
                        case 2:
                            deshacerBajaParcial(pilaBajas, listaAltas, listaBajas);
                            mergeSort(listaAltas);
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            bajaTotal(listaBajas, pilaBajas);
                            system("pause");
                            system("cls");
                            break;
                        case 4:
                            cout << endl << "Saliendo del submenu..." << endl << endl;
                            break;
                        default:
                            cout << "Error: Opcion incorrecta." << endl << endl;
                            system("pause");
                            system("cls");
                            break;
                    }
                } while (opsubmenu != 4);
                break;
            case 3:
                recuperarAlumno(listaAltas, listaBajas, pilaBajas);
                system("pause");
                system("cls");
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
                        case 1:  imprimirAlumnosAprobados(listaAltas);  break;
                        case 2:  imprimirPorcentajes(listaAltas);       break;
                        case 3:  imprimirDatosGenerales(listaAltas);    break;
                        case 4:  imprimirAlumnosInactivos(listaBajas);  break;
                        case 5:  cout << "Saliendo del submenu..." << endl; break;
                        default: cout << "Error: Opcion incorrecta." << endl; break;
                    }
                    system("pause");
                    system("cls");
                } while (opsubmenu != 5);
                break;
            case 5: {
            int opcionBusqueda = 0;
            alumno encontrado = nullptr;
            do {
            cout << "\nMODIFICACION DE DATOS DE ALUMNO\n"
                 << "1. Buscar por matricula\n"
                 << "2. Buscar por nombre\n"
                 << "3. Regresar al menu principal\n";

            do {
                cout << "Seleccione una opcion: ";
            } while (!validarInt(opcionBusqueda) &&
                    cout << "Error: opción invalida. Debe ser un numero.\n");

                switch (opcionBusqueda) {
                    case 1: {
                    long mat = 0;
                    do {
                        cout << "Ingrese matricula: ";
                    } while (!validarLong(mat) &&
                         cout << "Error: matricula inválida.\n");
                    encontrado = busquedaPorMatricula(listaAltas, mat);
                        break;
                    }
                    case 2: {
                    string nombre;
                    do {
                        cout << "Ingrese nombre: "; getline(cin, nombre);
                    } while (!validarString(nombre) && cout << "Error: el nombre debe ser solo letras.\n");
                    encontrado = busquedaPorNombre(listaAltas, nombre);
                        break;
                    }
                    case 3:
                        cout << "Regresando al menu principal...\n";
                        break;
                    default:
                        cout << "Error: opcion no valida.\n";
                        break;
            }
            if (opcionBusqueda == 1 || opcionBusqueda == 2) {
                if (!encontrado) {
                    cout << "Alumno no encontrado." << endl;
                } else {
                    modificarAlumno(encontrado);
                }
            }
                system("pause");
                system("cls");
            } while (opcionBusqueda != 3);
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
        system("pause");
        system("cls");
    } while (op != 8);

    return 0;
}
