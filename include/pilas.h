#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED

bool pilaVacia(alumno &pila);
void insertarEnPila(alumno &pila, alumno elem);
void eliminarAlumDePila(alumno &pila, alumno &elem);
void eliminarPila(alumno &pila);
void mostrarPila(alumno &pila);

#endif // PILAS_H_INCLUDED