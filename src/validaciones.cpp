#include <iostream>
#include <cctype>
#include "validaciones.h"

bool validarEspaciosOVacio(const string &str) {
    if (str.empty()) {
        return false;
    }
    bool soloEspacios = true;
    for (char c : str) {
        if (!isspace(c)) {
            soloEspacios = false;
        }
    }
    if (soloEspacios) {
        return false;
    }
    return true;
}

bool validarString(const string &str) {
    if (!(validarEspaciosOVacio(str))) {
        return false;
    }
    for(char c : str) {
        if (!isalpha(c) && !isspace(c)) {
            return false;
        }
    }
    return true;
}

bool validarInt(int &num) {
    string entrada;
    getline(cin, entrada);
    if (!(validarEspaciosOVacio(entrada))) {
        return false;
    }
    for (char c : entrada) {
        if (!(isdigit(c))) {
            return false;
        }
    }
    num = stoi(entrada);
    return true;
}

bool validarLong(long &num) {
    string entrada;
    getline(cin, entrada);
    if (!(validarEspaciosOVacio(entrada))) {
        return false;
    }
    for (char c : entrada) {
        if (!(isdigit(c))) {
            return false;
        }
    }
    num = stol(entrada);
    return true;
}

bool validarDouble(double &num) {
    string entrada;
    getline(cin, entrada);
    if (!(validarEspaciosOVacio(entrada))) {
        return false;
    }
    bool tienePunto = false;
    bool tieneSigno = false;
    for (size_t i = 0; i < entrada.length(); i++) {
        char c = entrada[i];
        if (isdigit(c)) {
            continue;
        } else if (c == '.' && i != 0 && !tienePunto) {
            tienePunto = true;
        } else if (c == '-' && i == 0 && !tieneSigno) {
            tieneSigno = true;
        } else {
            return false;
        }
    }
    num = stod(entrada);
    return true;
}
