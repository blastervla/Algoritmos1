#include "solucion.h"
#include "toroidUtils.h"

/********************************** EJERCICIO esValido **********************************/
bool esValido(toroide t) {
    return true;
}

/****************************** EJERCICIO posicionesVivas *******************************/
vector<posicion> posicionesVivas(toroide t) {
    vector<posicion> res;

    if (!esValido(t))
        return res;

    for (int f = 0; f < filas(t); f++) {
        for (int c = 0; c < columnas(t); c++) {
            if (t[f][c])
                res.push_back(posicion(f, c));
        }
    }

    return res;
}

/***************************** EJERCICIO densidadPoblacion ******************************/
float densidadPoblacion(toroide t) {
    float densidad = 0.0;
    return densidad;
}

/**************************** EJERCICIO evolucionDePosicion *****************************/
bool evolucionDePosicion(toroide t, posicion p) {
    return true;
}

/****************************** EJERCICIO evolucionToroide ******************************/
void evolucionToroide(toroide &t) {
    if (!esValido(t))
        return;

    for (int f = 0; f < filas(t); f++) {
        for (int c = 0; c < columnas(t); c++) {
            t[f][c] = evolucionDePosicion(t, posicion(f, c));
        }
    }
}

/***************************** EJERCICIO evolucionMultiple ******************************/
toroide evolucionMultiple(toroide t, int k) {
    toroide result;
    return result;
}

/******************************** EJERCICIO esPeriodico *********************************/
bool esPeriodico(toroide t, int &p) {
    if (!esValido(t))
        return false;

    toroide te = t;
    evolucionToroide(te);
    int count = 1;
    while (te != t && !estaMuerto(te)) {
        evolucionToroide(te);
        count++;
    }

    if (estaMuerto(te)) {
        return false;
    } else {
        p = count;
        return true;
    }
}

/******************************* EJERCICIO primosLejanos ********************************/
bool primosLejanos(toroide t1, toroide t2) {
    return false;
}

/****************************** EJERCICIO seleccionNatural ******************************/
int seleccionNatural(vector<toroide> ts) {
    bool toroidesValidos = true;
    for (toroide t : ts) {
        toroidesValidos = toroidesValidos && esValido(t);
    }
    if (!toroidesValidos || ts.size() == 0)
        return -1;

    int indice = 0;
    int ticksHastaMuerte = ticksHastaMuerte(t[0]);
    for (int i = 0; i < ts.size(); i++) {
        int ticksHastaMuerteActual = ticksHastaMuerte(t[i]);
        if (ticksHastaMuerte != -1 && (ticksHastaMuerteActual == -1 || (ticksHastaMuerte(t[i]) > ticksHastaMuerte(t[indice])))) {
            indice = i;
            ticksHastaMuerte = ticksHastaMuerteActual;
        }
    }

    return indice;
}

/********************************** EJERCICIO fusionar **********************************/
toroide fusionar(toroide t1, toroide t2) {
    toroide t;
    return t;
}

/****************************** EJERCICIO vistaTrasladada *******************************/
bool vistaTrasladada(toroide t1, toroide t2) {
    bool res = false;
    return res;
}

/******************************* EJERCICIO enCrecimiento ********************************/
bool enCrecimiento(toroide t) {
    bool res;
    return res;
}

/******************************* EJERCICIO soloBloques (OPCIONAL) ***********************/
/**
 * Dado un toroide válido, dice si está compuesto puramente por bloques.
 * Un bloque es una estructura formada por cuatro celdas vivas en forma de bloque (2 arriba y 2 abajo),
 * rodeada por celdas muertas. Posee la particularidad de ser una estructura periódica.
 * @param t
 * @return
 */
bool soloBloques(toroide t) {
    bool res;
    return res;
}
