//
// Created by vladimir pomsztein on 05/11/2018.
//

// TODO: Mover a la carpeta utils
#include <vector>

using namespace std;

template<typename T>
void insert(vector<T> &v, int pos, T value) {
    vector<T> modified(v.size() + 1);

    for (int i = 0; i < modified.size(); i++) {
        if (i == pos)
            modified[i] = value;
        else if (i < pos)
            modified[i] = v[i];
        else
            modified[i] = v[i - 1];
    }

    v = modified;
}

template<typename T>
void remove(vector<T> &v, int pos) {
    vector<T> modified(v.size() - 1);

    for (int i = 0; i < v.size(); i++) {
        if (i < pos)
            modified[i] = v[i];
        else if (i > pos)
            modified[i - 1] = v[i];
    }

    v = modified;
}

template<typename T>
bool contains(vector<T> &v, T elem) {
    bool contains = false;
    for (T e : v) contains = contains || e == elem;

    return contains;
}