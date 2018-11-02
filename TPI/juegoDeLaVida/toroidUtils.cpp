//
// Created by vladimir pomsztein on 30/10/2018.
//

#include "toroidUtils.h"

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

bool posicionValida(toroide t, int f, int c) {
    // Ver si vale la pena aclarar que el toroide sea válido, ya que de no serlo saldría del if directamente (hablando de evolucionDePosicion)
    return 0 <= f < filas(t) && 0 <= c < columnas(t);
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

bool valorPosicionNormalizada(toroide &t, posicion p) {
    posicion pn = normalizarPosicion(t, p);
    return t[get<0>(pn)][get<1>(pn)];
}

void rotarADerecha(toroide &t) {
    for (int f = 0; f < filas(t); f++) {
        bool valToRotate = t[f].back();
        t[f].pop_back();
        t[f].insert(t[f].begin(), valToRotate);
    }
}

void rotarHaciaAbajo(toroide &t) {
    vector<bool> valToRotate = t.back();
    t.pop_back();
    t.insert(t.begin(), valToRotate);
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