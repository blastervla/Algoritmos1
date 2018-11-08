#include "es.h"
#include "definiciones.h"
#include "utils/toroidUtils.h"
#include <iostream>
#include <fstream>

/******************************** EJERCICIO cargarToroide *******************************/
toroide cargarToroide(string nombreArchivo, bool &status) {
    ifstream fin;
    fin.open(nombreArchivo, ifstream::in);
    if (fin.fail()) {
        status = false;
        return toroide();
    }

    int filas = 0;
    int columnas = 0;
    fin >> filas;
    fin >> columnas;
    toroide t(filas, vector<bool>(columnas));
    int f = 0;
    int c = 0;
    while (f < filas && !fin.eof()) {
        int posValue = 0;
        fin >> posValue;
        t[f][c] = posValue == 1;
        c++;
        if (c >= columnas) {
            c = 0;
            f++;
        }
    }

    int checksum;
    fin >> checksum;

    fin.close();

    status = (f == filas && c == 0) && checksum == cantidadVivas(t) && !fin.fail();
    return t;
}


/******************************** EJERCICIO escribirToroide *****************************/
bool escribirToroide(string nombreArchivo, toroide &t) {
    if (nombreArchivo.size() == 0)
        return false;

    ofstream fout;
    fout.open(nombreArchivo);
    if (fout.fail())
        return false;

    fout << filas(t) << " " << columnas(t) << endl;

    for (vector<bool> fila : t) {
        for (int c = 0; c < fila.size(); c++) {
            fout << (fila[c] ? 1 : 0);
            if (c < fila.size() - 1)
                fout << " ";
        }
        fout << endl;
    }

    fout << cantidadVivas(t) << endl;
    fout.close();

    return !fout.fail();
}
