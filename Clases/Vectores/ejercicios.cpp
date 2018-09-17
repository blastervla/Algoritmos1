#include "ejercicios.h"

bool divide(vector<int> v, int n) {
    if (n == 0)
        return false;

    bool divide = true;
    for (int i = 0; i < v.size(); i++) {
        divide = divide && (v[i] % n == 0);
    }

    return divide;
}


bool divideRec(vector<int> v, int n) {
    if (n == 0)
        return false;
    if (v.size() == 0)
        return true;

    int x = v[v.size() - 1];
    v.pop_back();
    return (x % n == 0) && divideRec(v, n);
}

int maximo(vector<int> v) {
    if (v.empty())
        return 0;

    int max = v[0];
    for (int x : v) {
        if (x > max)
            max = x;
    }

    return max;
}

int maximoRec(vector<int> v) {
    if (v.empty())
        return 0;

    if (v.size() == 1)
        return v[0];

    int actual = v[v.size() - 1];
    v.pop_back();
    int othersMax = maximoRec(v);
    return actual > othersMax ? actual : othersMax;
}

bool pertenece(int elem, vector<int> v) {
    bool pertence = false;

    for (int i = 0; i < v.size(); i++) {
        pertence = pertence || v[i] == elem;
    }

    return pertence;
}

bool perteneceRec(int elem, vector<int> v) {
    if (v.empty())
        return false;

    int actual = v[v.size() - 1];
    v.pop_back();
    return actual == elem || perteneceRec(elem, v);
}

void mostrarVector(vector<int> v) {
    cout << "[";

    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
        if (i < v.size() - 1)
            cout << ", ";
    }

    cout << "]" << endl;
}

vector<int> limpiarDuplicados(vector<int> v) {
    vector<int> encontrados;
    vector<int> res;

    for (int x : v) {
        if (!pertenece(x, encontrados)) {
            encontrados.push_back(x);
            res.push_back(x);
        }
    }

    return res;
}

vector<int> rotar(vector<int> v, int k) {
    vector<int> res(v.size());

    for (int i = 0; i < v.size(); i++) {
        int kAux = k;
        int newIndex = i;
        while (kAux > 0) {
            newIndex -= kAux;
            kAux -= v.size();
            if (newIndex < 0)
                newIndex += v.size();
        }
        res[newIndex] = v[i];
    }

    return res;
}

vector<int> reverso(vector<int> v) {
    vector<int> res;

    for (int i = static_cast<int>(v.size() - 1); i >= 0; i--) {
        res.push_back(v[i]);
    }

    return res;
}

int sacarPrimero(vector<int> &v) {
    v = rotar(v, 1);
    int x = v[v.size() - 1];
    v.pop_back();
    return x;
}

vector<int> reversoRec(vector<int> v) {
    if (v.size() <= 1)
        return v;

    // Tomo el primer elemento y lo saco del vector
    int x = sacarPrimero(v);

    vector<int> res = reversoRec(v);
    res.push_back(x);

    return res;
}

bool esPrimo(int n) {
    bool esPrimo = true;

    for (int i = 2; i < n; ++i) {
        esPrimo = esPrimo && (n % i != 0);
    }

    return esPrimo;
}

vector<int> factoresPrimos(int n) {
    vector<int> res;

    int divActual = n;
    while (n > 1) {
        if (n % divActual == 0 && esPrimo(divActual)) {
            res.push_back(divActual);
            n = n / divActual;
            divActual = n + 1;
        }

        divActual--;
    }

    return res;
}


bool estaOrdenado(vector<int> v) {
    bool monotonoDecreciente = true;
    for (int i = 1; i < v.size(); i++) {
        monotonoDecreciente = monotonoDecreciente && (v[i] < v[i - 1]);
    }

    bool monotonoCreciente = true;
    for (int i = 1; i < v.size(); i++) {
        monotonoCreciente = monotonoCreciente && (v[i] > v[i - 1]);
    }

    return monotonoDecreciente || monotonoCreciente;
}

void negadorDeBooleanos(vector<bool> &booleanos) {
    for (int i = 0; i < booleanos.size(); i++) {
        booleanos[i] = !booleanos[i];
    }
}

void sinImpares(vector<int> &v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] % 2 == 1)
            v[i] = 0;
    }
}

int contarApariciones(vector<int> v, int elem) {
    int count = 0;
    for (int x : v) {
        if (x == elem)
            count++;
    }
    return count;
}

void sacarTodos(vector<int> &v, int elem) {
    vector<int> res;
    for (int i = 0; i < v.size(); i++) {
        if (v[i] != elem) {
            res.push_back(v[i]);
        }
    }
    v = res;
}

vector<pair<int, int> > cantidadApariciones(vector<int> v) {
    vector<pair<int, int> > res;

    while (!v.empty()) {
        res.push_back(pair<int, int>(v[0], contarApariciones(v, v[0])));
        sacarTodos(v, v[0]);
    }

    return res;
}



