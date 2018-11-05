//
// Created by vladimir pomsztein on 30/10/2018.
//

// TODO: Mover a la carpeta utils
#include "definiciones.h"

int filas(toroide &t);

int columnas(toroide &t);

int area(toroide &t);

bool mismaDimension(toroide &t1, toroide &t2);

bool posicionValida(toroide t, int f, int c);

int cantidadVivas(toroide &t);

bool estaMuerto(toroide &t);

posicion normalizarPosicion(toroide &t, posicion p);

bool valorPosicionNormalizada(toroide &t, posicion p);

void rotarADerecha(toroide &t);

void rotarHaciaAbajo(toroide &t);

bool todasMuertasEnFila(vector<bool> &fila);

bool todasMuertasEnColumna(toroide &t, int c);