#include "solucion.h"
#include "toroidUtils.h"

/********************************** EJERCICIO esValido **********************************/
bool esValido(toroide t) {
    bool res = false;

    if (filas(t) > 0 && columnas(t) > 0) {
        res = true;
        for (int f = 1; f < filas(t) && res; f++) {
            if (t[f].size() != columnas(t))
                res = false;
        }
    }
    return res;
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

    if (!esValido(t))
        return 0.0;

    int cantVivas = posicionesVivas(t).size();
    int cantTotal = filas(t) * columnas(t);

    return cantVivas / cantTotal;
}


/**************************** EJERCICIO evolucionDePosicion *****************************/
bool estaViva(toroide t, int f, int c){
    return t[f][c];
}

int vivasAdyacentes(toroide t, int f, int c){
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++){
            posicion p = make_tuple(f + i, c + j);
            if (valorPosicionNormalizada(t, p))
                count ++;
        }
    }
    return count;
}
// valorLuegoDeEvolucion esta generada con el unico objetivo de limpiar la función evoluciónDePosicion
bool valorLuegoDeEvloucion (toroide t, int f, int c){
    return ((estaViva(t, f, c) && 2 <= vivasAdyacentes(t, f, c) <= 3) || (!estaViva(t, f, c) && vivasAdyacentes(t, f, c) == 3));
}

bool evolucionDePosicion(toroide t, posicion p) {
    int f = get<0>(p);
    int c = get<1>(p);

    if (!esValido(t) || !posicionValida(t, f, c))
        return false;

    return valorLuegoDeEvloucion(t, f, c);
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
    if (!esValido(t) || k < 1)
        return t;

    for (int i=0; i < k; i++) {
        evolucionToroide(t);
    }
    return t;
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

    if (te != t && estaMuerto(te)) {
        return false;
    } else {
        p = count;
        return true;
    }
}

/******************************* EJERCICIO primosLejanos ********************************/
bool primosLejanos(toroide t1, toroide t2) {
    bool res = false;

    if (!esValido(t1) || !esValido(t2) || !mismaDimension(t1,t2))
        return res;

    return res;
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
    bool toroidesValidos = true;
    for (toroide t : ts) {
        toroidesValidos = toroidesValidos && esValido(t);
    }
    if (!toroidesValidos || ts.size() == 0)
        return -1;

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
    toroide t;
    return t;
}

/****************************** EJERCICIO vistaTrasladada *******************************/
bool vistaTrasladada(toroide t1, toroide t2) {
    bool res = false;
    if (!esValido(t1) || !esValido(t2) || !mismaDimension(t1, t2))
        return res;

    // TODO: Check, quizás hay que hacerlo filas + 1 y columnas + 1 veces para dar toda la vuelta, not sure.
    // Debería estar bien welp.
    for (int f = 0; f < filas(t1); f++) {
        rotarHaciaAbajo(t1);
        for (int c = 0; c < columnas(t1); c++) {
            rotarADerecha(t1);
            res = res || t1 == t2;
        }
    }
    return res;
}

/******************************* EJERCICIO enCrecimiento ********************************/
void cercarCelulasVivas(toroide &t) {
    toroide tCercado = t;
    int deleted = 0;
    for (int f = 0; f < filas(t); f++) {
        if (todasMuertasEnFila(t[f])) {
            tCercado.erase(t.begin() + f - deleted);
            deleted++;
        }
    }

    deleted = 0;
    for (int c = 0; c < columnas(t); c++) {
        if (todasMuertasEnColumna(t, c)) {
            for (vector<bool> fila : t) {
                fila.erase(fila.begin() + c - deleted);
            }
            deleted++;
        }
    }
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
            sup = sup < supActual ? supActual : sup;
        }
    }

    return sup;
}

bool enCrecimiento(toroide t) {
    if (!esValido(t))
        return false;

    toroide te = t;
    evolucionToroide(te);

    return menorSuperficie(t) < menorSuperficie(te);
}

/******************************* EJERCICIO soloBloques (OPCIONAL) ***********************/
/**
 * Dado un toroide válido, dice si está compuesto puramente por bloques.
 * Un bloque es una estructura formada por cuatro celdas vivas en forma de bloque (2 arriba y 2 abajo),
 * rodeada por celdas muertas. Posee la particularidad de ser una estructura periódica de período p = 1.
 * @param t
 * @return
 */
bool soloBloques(toroide t) {
    bool res;
    return res;
}
