#include <iostream>
#include "alta.h"
#include "baja.h"
#include "grupos.h"
#include "listas.h"
#include "inscripcion.h"
#include "modificacion.h"
#include "pilas.h"
#include "recuperar.h"
#include "reportes.h"
#include "validaciones.h"

using namespace std;

int main() {
    int op, opsubmenu;
    alumno listaAltas = nullptr;
    alumno listaBajas = nullptr;
    alumno pilaBajas = nullptr;
    ColaInscripciones colaInscripciones;

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
        } while (!validarInt(op) && cout << "Error: La opcion debe ser entero y contener solo numeros." << endl << endl);

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
                    } while (!validarInt(opsubmenu) && cout << "Error: La opcion debe ser entero y contener solo numeros." << endl << endl);

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
                recuperarAlumno(listaAltas, listaBajas, pilaBajas);
                break;
            case 4:
                cout << endl;
                do {
                    cout << "\tSUBMENU" << endl
                         << "1. Alumnos aprobados." << endl
                         << "2. Porcentajes." << endl
                         << "3. Datos generales." << endl
                         << "4. Alumnos inactivos." << endl
                         << "5. Salir." << endl;
                    do {
                        cout << "Elija una opcion: ";
                    } while (!validarInt(opsubmenu) && cout << "Error: La opcion debe ser entero y contener solo numeros." << endl << endl);

                    switch (opsubmenu) {
                        case 1:
                            imprimirAlumnosAprobados(listaAltas);
                            system("pause"); system("cls");
                            break;
                        case 2:
                            imprimirPorcentajes(listaAltas);
                            system("pause"); system("cls");
                            break;
                        case 3:
                            imprimirDatosGenerales(listaAltas);
                            system("pause"); system("cls");
                            break;
                        case 4:
                            imprimirAlumnosInactivos(listaBajas);
                            system("pause"); system("cls");
                            break;
                        case 5:
                            cout << endl << "Saliendo del submenu..." << endl << endl;
                            break;
                        default:
                            cout << "Error: Opcion incorrecta." << endl << endl;
                            system("pause"); system("cls");
                            break;
                    }
                } while (opsubmenu != 5);
                break;
            case 5: {
                if (listaVacia(listaAltas)) {
                    cout << "No hay alumnos para modificar sus datos." << endl << endl;
                    break;
                }

                int opcionBusqueda;
                alumno encontrado = nullptr;
                cout << endl;
                do {
                    cout << "\tBuscar por:\n"
                            << "1. Matricula.\n"
                            << "2. Nombre.\n"
                            << "3. Salir.\n";
                    do {
                        cout << "Elija una opcion: ";
                    } while (!validarInt(opcionBusqueda) && cout << "Error: La opcion debe ser entero y contener solo numeros." << endl << endl);

                    cout << endl;
                    switch (opcionBusqueda) {
                        case 1: {
                            long mat;
                            do {
                                cout << "Ingrese la matricula: ";
                            } while (!validarLong(mat) && cout << "Error: La matricula debe ser un numero positivo de 7 digitos." << endl << endl);
                            encontrado = busquedaPorMatricula(listaAltas, mat);
                            break;
                        }
                        case 2: {
                            string nombre;
                            do {
                                cout << "Ingrese el nombre: "; getline(cin, nombre);
                            } while (!validarString(nombre) && cout << "Error: El nombre debe estar conformado solo por letras." << endl << endl);
                            encontrado = busquedaPorNombre(listaAltas, nombre);
                            break;
                        }
                        case 3:
                            cout << "Saliendo del submenu..." << endl << endl;
                            break;
                        default:
                            cout << "Error: Opcion incorrecta." << endl << endl;
                            system("pause"); system("cls");
                            break;
                    }
                    if (opcionBusqueda == 1 || opcionBusqueda == 2) {
                        if (!encontrado) {
                            cout << endl << "Alumno no encontrado." << endl << endl;
                        } else {
                            modificarAlumno(encontrado, listaAltas);
                        }
                        system("pause"); system("cls");
                    }
                } while (opcionBusqueda != 3);
                break;
            }
            case 6: {
                int opcionInscripcion;
                cout << endl;
                do {
                    cout << "\tSUBMENU" << endl
                         << "1. Mostrar alumnos en espera." << endl
                         << "2. Procesar siguiente inscripcion." << endl
                         << "3. Mostrar alumnos inscritos." << endl
                         << "4. Salir." << endl;
                    do {
                        cout << "Elija una opcion: ";
                    } while (!validarInt(opcionInscripcion) && cout << "Error: La opcion debe ser entero y contener solo numeros." << endl);

                    switch(opcionInscripcion) {
                        case 1: {
                            while(!colaInscripciones.empty()) {
                                colaInscripciones.pop();
                            }
                            agregarAColaDeInscripciones(listaAltas, colaInscripciones);
                            if(!colaInscripciones.empty()) {
                                mostrarCola(colaInscripciones);
                            } else {
                                cout << endl << "Cola vacia. No hay alumnos esperando inscripcion." << endl << endl;
                            }
                            system("pause"); system("cls");
                            break;
                        }
                        case 2:
                            if(!colaInscripciones.empty()) {
                                inscribirAlumno(colaInscripciones, listaAltas);
                            } else {
                                cout << endl << "Cola vacia. No hay alumnos en la cola para inscribirse." << endl << endl;
                            }
                            system("pause"); system("cls");
                            break;
                        case 3:
                            mostrarListaInscritos(listaAltas);
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
                } while (opcionInscripcion != 4);
                break;
            }
            case 7:
                crearGrupos(listaAltas);
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
