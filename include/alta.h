#ifndef ALTA_H_INCLUDED
#define ALTA_H_INCLUDED

using namespace std;

typedef enum {
    baja,
    alta
} status;

typedef enum {
    esperando,
    inactivo,
    inscrito
} insc;

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
    insc inscripcion;
    nodo *sig;
} *alumno;

alumno altaAlum(alumno listaAltas);

#endif // ALTA_H_INCLUDED
