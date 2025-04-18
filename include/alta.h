#ifndef ALTA_H_INCLUDED
#define ALTA_H_INCLUDED

using namespace std;

typedef enum {
    baja,
    alta
} status;

typedef struct {
    string calle;
    string colonia;
    string municipio;
    int numero;
    int cp;
} direccion;

typedef struct nodo {
    long matricula;
    string nombre;
    int edad;
    double promedio;
    status situacion;
    direccion address;
    nodo *sig;
} *alumno;

alumno altaAlum(alumno &lista);

#endif // ALTA_H_INCLUDED