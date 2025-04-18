#ifndef BAJA_H_INCLUDED
#define BAJA_H_INCLUDED

void bajaParcial(alumno &listaAltas, alumno &listaBajas, alumno &pila);
void deshacerBajaParcial(alumno &pila, alumno &listaAltas, alumno &listaBajas);
alumno bajaPorMatricula(alumno &listaBajas, long &bajaMat);
alumno bajaPorNombre(alumno &listaBajas, string &elimNom);
void bajaTotal(alumno &listaBajas, alumno &pila);

#endif // BAJA_H_INCLUDED