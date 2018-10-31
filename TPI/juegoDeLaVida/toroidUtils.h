//
// Created by vladimir pomsztein on 30/10/2018.
//

#include "definiciones.h"

int filas(toroide &t);

int columnas(toroide &t);

bool mismaDimension(toroide &t1, toroide &t2);

int cantidadVivas(toroide &t);

bool estaMuerto(toroide &t);

posicion normalizarPosicion(toroide &t, posicion p);

void rotarADerecha(toroide &t);

void rotarHaciaAbajo(toroide &t);