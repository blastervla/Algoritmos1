#include "solucion.h"
#include "utils/toroidUtils.h"
#include "utils/vectorUtils.h"

/********************************** EJERCICIO esValido **********************************/
bool esValido(toroide t) {
    bool esValido = filas(t) > 0 && columnas(t) > 0;

    for (int f = 0; f < filas(t); f++) {
        esValido = esValido && t[f].size() == columnas(t);
    }

    return esValido;
}

/****************************** EJERCICIO posicionesVivas *******************************/
vector<posicion> posicionesVivas(toroide t) {
    vector<posicion> vivas;

    for (int f = 0; f < filas(t); f++) {
        for (int c = 0; c < columnas(t); c++) {
            if (t[f][c])
                vivas.push_back(posicion(f, c));
        }
    }

    return vivas;
}

/***************************** EJERCICIO densidadPoblacion ******************************/
float densidadPoblacion(toroide t) {
    float cantVivas = posicionesVivas(t).size();
    float cantTotal = filas(t) * columnas(t);

    return cantVivas / cantTotal;
}


/**************************** EJERCICIO evolucionDePosicion *****************************/
int vivasAdyacentes(toroide t, int f, int c) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if ((i != 0 || j != 0) && valorPosicionNormalizada(t, posicion(f + i, c + j)))
                count++;
        }
    }

    return count;
}

bool valorLuegoDeEvolucion(toroide t, int f, int c) {
    return (t[f][c] && (2 <= vivasAdyacentes(t, f, c) && vivasAdyacentes(t, f, c) <= 3))
           || (!t[f][c] && vivasAdyacentes(t, f, c) == 3);
}

bool evolucionDePosicion(toroide t, posicion p) {
    int f = get<0>(p);
    int c = get<1>(p);

    return valorLuegoDeEvolucion(t, f, c);
}

/****************************** EJERCICIO evolucionToroide ******************************/
void evolucionToroide(toroide &t) {
    toroide te = t;
    for (int f = 0; f < filas(t); f++) {
        for (int c = 0; c < columnas(t); c++) {
            te[f][c] = evolucionDePosicion(t, posicion(f, c));
        }
    }

    t = te;
}

/***************************** EJERCICIO evolucionMultiple ******************************/
toroide evolucionMultiple(toroide t, int k) {
    for (int i = 0; i < k; i++) {
        evolucionToroide(t);
    }
    return t;
}

/******************************** EJERCICIO esPeriodico *********************************/
bool esPeriodico(toroide t, int &p) {
    toroide te = t;

    int count = 1;
    vector<toroide> tAnts = {te};
    evolucionToroide(te);
    // Checkeamos te != tAnt porque si el anterior es igual al siguiente, estamos en un caso infinito
    while (!contains(tAnts, te) && !estaMuerto(te)) {
        tAnts.push_back(te);
        evolucionToroide(te);
        count++;
    }

    if (te != t) {
        return false;
    } else {
        p = count;
        return true;
    }
}

/******************************* EJERCICIO primosLejanos ********************************/
bool primosLejanos(toroide t1, toroide t2) {
    bool primos = false;
    int ticks = -1;

    if (esPeriodico(t1, ticks)) {
        for (int k = 1; k <= ticks; k++) {
            primos = primos || t2 == evolucionMultiple(t1, k);
        }
    } else {
        primos = t1 == t2;

        while (!estaMuerto(t1)) {
            evolucionToroide(t1);
            primos = primos || t1 == t2;
        }
    }
    return primos;
}

/****************************** EJERCICIO seleccionNatural ******************************/
int ticksHastaMuerte(toroide &t) {
    int ticks = -1;
    if (esPeriodico(t, ticks))
        return -1;

    ticks = 0;
    toroide te = t;
    while (!estaMuerto(te)) {
        ticks++;
        evolucionToroide(te);
    }

    return ticks;
}

int seleccionNatural(vector<toroide> ts) {
    int indice = 0;
    int mayorTicksHastaMuerte = ticksHastaMuerte(ts[0]);
    for (int i = 0; i < ts.size(); i++) {
        int ticksHastaMuerteActual = ticksHastaMuerte(ts[i]);
        if (mayorTicksHastaMuerte != -1 &&
            (ticksHastaMuerteActual == -1 || (ticksHastaMuerteActual > mayorTicksHastaMuerte))) {
            indice = i;
            mayorTicksHastaMuerte = ticksHastaMuerteActual;
        }
    }

    return indice;
}

/********************************** EJERCICIO fusionar **********************************/
toroide fusionar(toroide t1, toroide t2) {
    toroide fusion = t1;
    for (int f = 0; f < filas(t1); f++) {
        for (int c = 0; c < columnas(t1); c++) {
            fusion[f][c] = t1[f][c] && t2[f][c];
        }
    }
    return fusion;
}

/****************************** EJERCICIO vistaTrasladada *******************************/
bool vistaTrasladada(toroide t1, toroide t2) {
    bool esVistaTrasladada = false;

    // TODO: Check, quizás hay que hacerlo filas + 1 y columnas + 1 veces para dar toda la vuelta, not sure.
    // Debería estar bien welp.
    for (int f = 0; f < filas(t1); f++) {
        rotarHaciaAbajo(t1);
        for (int c = 0; c < columnas(t1); c++) {
            rotarADerecha(t1);
            esVistaTrasladada = esVistaTrasladada || t1 == t2;
        }
    }
    return esVistaTrasladada;
}

/******************************* EJERCICIO enCrecimiento ********************************/
void cercarCelulasVivas(toroide &t) {
    toroide tCercado = t;
    int deleted = 0;
    for (int f = 0; f < filas(t); f++) {
        if (todasMuertasEnFila(t[f])) {
            remove(tCercado, f - deleted);
            deleted++;
        }
    }

    deleted = 0;
    for (int c = 0; c < columnas(t); c++) {
        if (todasMuertasEnColumna(t, c)) {
            for (int f = 0; f < tCercado.size(); f++) {
                remove(tCercado[f], c - deleted);
            }
            deleted++;
        }
    }

    t = tCercado;
}

int menorSuperficie(toroide &t) {
    toroide tTrasladado = t;
    int sup = area(tTrasladado);

    // Para cada vista trasladada, cerca la superficie (para conseguir la menor)
    for (int f = 0; f < filas(tTrasladado); f++) {
        rotarHaciaAbajo(tTrasladado);
        for (int c = 0; c < columnas(tTrasladado); c++) {
            rotarADerecha(tTrasladado);
            toroide tPodado = tTrasladado;
            cercarCelulasVivas(tPodado);
            int supActual = area(tPodado);
            sup = sup < supActual ? sup : supActual;
        }
    }

    return sup;
}

bool enCrecimiento(toroide t) {
    toroide te = t;
    evolucionToroide(te);

    return menorSuperficie(t) < menorSuperficie(te);
}

/******************************* EJERCICIO soloBloques (OPCIONAL) ***********************/

bool esCuadradoDeVivas(toroide &t, int x, int y) {
    return valorPosicionNormalizada(t, posicion(x, y))
           && valorPosicionNormalizada(t, posicion(x + 1, y))
           && valorPosicionNormalizada(t, posicion(x, y + 1))
           && valorPosicionNormalizada(t, posicion(x + 1, y + 1));
}

bool estaRodeadoDeMuertas(toroide &t, int x, int y) {
    return !valorPosicionNormalizada(t, posicion(x - 1, y - 1))
           && !valorPosicionNormalizada(t, posicion(x - 1, y))
           && !valorPosicionNormalizada(t, posicion(x - 1, y + 1))
           && !valorPosicionNormalizada(t, posicion(x - 1, y + 2))
           && !valorPosicionNormalizada(t, posicion(x, y - 1))
           && !valorPosicionNormalizada(t, posicion(x, y + 2))
           && !valorPosicionNormalizada(t, posicion(x + 1, y - 1))
           && !valorPosicionNormalizada(t, posicion(x + 1, y + 2))
           && !valorPosicionNormalizada(t, posicion(x + 2, y - 1))
           && !valorPosicionNormalizada(t, posicion(x + 2, y))
           && !valorPosicionNormalizada(t, posicion(x + 2, y + 1))
           && !valorPosicionNormalizada(t, posicion(x + 2, y + 2));
}

bool esBloqueSupIzq(toroide &t, int x, int y) {
    return esCuadradoDeVivas(t, x, y) && estaRodeadoDeMuertas(t, x, y);
}

bool esBloque(toroide &t, int x, int y) {
    return esBloqueSupIzq(t, x, y)
           || esBloqueSupIzq(t, x - 1, y)
           || esBloqueSupIzq(t, x, y - 1)
           || esBloqueSupIzq(t, x - 1, y - 1);
}

/**
 * Dado un toroide válido, dice si está compuesto puramente por bloques.
 * Un bloque es una estructura formada por cuatro celdas vivas en forma de bloque (2 arriba y 2 abajo),
 * rodeada por celdas muertas. Posee la particularidad de ser una estructura periódica de período p = 1.
 * @param t
 * @return
 */
bool soloBloques(toroide t) {
    bool res = cantidadVivas(t) >= 4;

    for (int f = 0; f < filas(t); f++) {
        for (int c = 0; c < columnas(t); c++) {
            if (t[f][c])
                res = res && esBloque(t, f, c);
        }
    }

    return res;
}
