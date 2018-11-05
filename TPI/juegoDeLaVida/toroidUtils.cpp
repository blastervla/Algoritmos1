//
// Created by vladimir pomsztein on 30/10/2018.
//

#include "toroidUtils.h"
#include "vectorUtils.h"

int filas(toroide &t) {
    return t.size();
}

int columnas(toroide &t) {
    if (filas(t) == 0)
        return 0;
    return t[0].size();
}

int area(toroide &t) {
    return filas(t) * columnas(t);
}

bool mismaDimension(toroide &t1, toroide &t2) {
    return filas(t1) == filas(t2) && columnas(t1) == columnas(t2);
}

int cantidadVivas(toroide &t) {
    int count = 0;
    for (vector<bool> fila : t) {
        for (bool celda : fila) {
            count += celda ? 1 : 0;
        }
    }

    return count;
}

bool estaMuerto(toroide &t) {
    bool estaMuerto = true;

    for (vector<bool> fila : t) {
        for (bool celda : fila) {
            estaMuerto = estaMuerto && !celda;
        }
    }

    return estaMuerto;
}

posicion normalizarPosicion(toroide &t, posicion p) {
    return posicion(get<0>(p) % filas(t), get<1>(p) % columnas(t));
}

void rotarADerecha(toroide &t) {
    for (int f = 0; f < filas(t); f++) {
        bool valToRotate = t[f].back();
        t[f].pop_back();
        insert(t[f], 0, valToRotate);
    }
}

void rotarHaciaAbajo(toroide &t) {
    vector<bool> valToRotate = t.back();
    t.pop_back();
    insert(t, 0, valToRotate);
}

bool todasMuertasEnFila(vector<bool> &fila) {
    bool todasMuertas = true;
    for (bool celda : fila) {
        todasMuertas = todasMuertas && !celda;
    }
    return todasMuertas;
}

bool todasMuertasEnColumna(toroide &t, int c) {
    bool todasMuertas = true;
    for (vector<bool> fila : t) {
        todasMuertas = todasMuertas && !fila[c];
    }
    return todasMuertas;
}