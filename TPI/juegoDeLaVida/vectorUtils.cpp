//
// Created by vladimir pomsztein on 05/11/2018.
//

#include "vectorUtils.h"

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