#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED

bool listaVacia(alumno &lista);
void insertarEnLista(alumno &lista, alumno &nuevo);
void eliminarAlumDeLista(alumno &lista, alumno &elem);
void eliminarLista(alumno &lista);
void mostrarLista(alumno &lista);
void dividirLista(alumno fuente, alumno &front, alumno &back);
alumno merge(alumno a, alumno b);
void mergeSort(alumno &lista);
int obtenerTamaño(alumno lista);
alumno obtenerEnPosicion(alumno lista, int pos);
alumno busquedaBinaria(alumno lista, int inicio, int fin, long matriculaBuscada);

#endif // LISTAS_H_INCLUDED