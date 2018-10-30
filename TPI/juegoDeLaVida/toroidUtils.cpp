//
// Created by vladimir pomsztein on 30/10/2018.
//

#include "toroidUtils.h"

int filas(toroide t) {
    return t.size();
}

int columnas(toroide t) {
    return t.size();
}

int cantidadVivas(toroide t) {
    int count = 0;
    for (vector<bool> fila : t) {
        for (bool celda : fila) {
            count += celda ? 1 : 0;
        }
    }

    return count;
}

bool estaMuerto(toroide& t){
    bool estaMuerto = true;

    for (vector<bool> fila : t) {
        for (bool celda : fila) {
            estaMuerto = estaMuerto && !celda;
        }
    }

    return estaMuerto;
}