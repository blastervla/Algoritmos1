#include "es.h"
#include "definiciones.h"
#include "toroidUtils.h"
#include <iostream>
#include <fstream>

/******************************** EJERCICIO cargarToroide *******************************/
toroide cargarToroide(string nombreArchivo, bool &status)
{
	toroide t;
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
