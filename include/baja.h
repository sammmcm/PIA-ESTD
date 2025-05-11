#ifndef BAJA_H_INCLUDED
#define BAJA_H_INCLUDED

#include "alta.h"

alumno busquedaPorMatricula(alumno &estructura, long &bajaMat);
alumno busquedaPorNombre(alumno &estructura, string &elimNom);
void bajaParcial(alumno &listaAltas, alumno &listaBajas, alumno &pila);
void deshacerBajaParcial(alumno &pila, alumno &listaAltas, alumno &listaBajas);
void bajaTotal(alumno &listaBajas, alumno &pila);

#endif // BAJA_H_INCLUDED
