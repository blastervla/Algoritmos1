#include "ejercicios.h"


vector<int> naipesFaltantes(vector<int>& naipes){
    vector<int> naipesFaltantes;
    vector<int> count(12, 0);

    for (int i = 0; i < naipes.size(); i++) {
        int naipe = naipes[i] - 1;
        count[naipe]++;
    }

    for (int i = 0; i < count.size(); i++) {
        if (count[i] == 0)
            naipesFaltantes.push_back(i + 1);
    }

    return naipesFaltantes;
}


[3,4,5,1,2]
     ^
int maximoRotadas(vector<int> s){
    int low = 0;
    int high = s.size() - 1;

    while (low + 1 < high) {
        int mid = (low + high) / 2;
        if (s[mid] > s[mid] + 1)
            return s[mid];
        else if (s[mid])
    }
    return 0;
}

bool perteneceRotadas(vector<int> s, int elem){
    //cout << "Implementame" << endl;
    return false;
}

bool contieneElementos(vector<int>& a, vector<int>& b){
    //cout << "Implementame" << endl;
    return false;
}

int dameBache(vector<int>& s){
    //cout << "Implementame" << endl;
    return 0;
}

int dameBache1(vector<int>& s){
    //cout << "Implementame" << endl;
    return 0;
}

