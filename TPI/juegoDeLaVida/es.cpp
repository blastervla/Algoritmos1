#include "es.h"
#include "definiciones.h"
#include "toroidUtils.h"
#include <iostream>
#include <fstream>

/******************************** EJERCICIO cargarToroide *******************************/
toroide cargarToroide(string nombreArchivo, bool &status)
{
	ifstream fin;
	fin.open(nombreArchivo, ifstream::in);
	if (!fin.is_open()) {
	    status = false;
	    return toroide();
	}

	int filas, columnas = 0;
	fin >> filas;
    fin >> columnas;
    toroide t(filas, vector<bool>(columnas));
    int f = 0;
    int c = 0;
    while (f < filas && !fin.eof()) {
        int posValue;
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

    if (!fin.eof())
        status = false;

	fin.close();
	if ((f != filas && c != 0) || checksum != cantidadVivas(t) || fin.is_open())
	    status = false;

	return t;
}


/******************************** EJERCICIO escribirToroide *****************************/
bool escribirToroide(string nombreArchivo, toroide &t)
{
	if (nombreArchivo.size() == 0)
		return false;

	ofstream fout;
	fout.open(nombreArchivo);
	if (!fout.is_open())
	    return false;

	fout << filas(t) << endl;
    fout << columnas(t) << endl;

    for (vector<bool> fila : t) {
        for (bool celda : fila) {
            fout << celda ? 1 : 0;
        }
        fout << endl;
    }

    fout << cantidadVivas(t) << endl;
    fout.close();

    return !fout.is_open();
}
