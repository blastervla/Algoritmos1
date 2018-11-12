//
// Created by vladimir pomsztein on 30/10/2018.
//

#include "toroidUtils.h"
#include "vectorUtils.h"

int filas(toroide &t) {
    return t.size();
}

int columnas(toroide &t) {
    return t[0].size();
}

int area(toroide &t) {
    return filas(t) * columnas(t);
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
    int x = get<0>(p) % filas(t);
    x = x < 0 ? x + filas(t) : x; // Esto esta para manejar valores negativos

    int y = get<1>(p) % columnas(t);
    y = y < 0 ? y + columnas(t) : y; // Esto esta para manejar valores negativos

    return posicion(x, y);
}

bool valorPosicionNormalizada(toroide &t, posicion p) {
    posicion pn = normalizarPosicion(t, p);
    return t[get<0>(pn)][get<1>(pn)];
}

void rotarADerecha(toroide &t) {
    for (int f = 0; f < filas(t); f++) {
        bool valToRotate = t[f].back();
        t[f].pop_back();
        push_front(t[f], valToRotate);
    }
}

void rotarHaciaAbajo(toroide &t) {
    vector<bool> valToRotate = t.back();
    t.pop_back();
    push_front(t, valToRotate);
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