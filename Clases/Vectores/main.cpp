#include <iostream>
#include <vector>
#include "ejercicios.h"
#include "common_utils.h"

using namespace std;

int main() {
    cout << "A probar se ha dicho!" << endl;
    cout << "DIVIDE" << endl;

    vector<int> v;
    v.push_back(-20);
    v.push_back(30);
    v.push_back(40);
    vector<int> v2 = v;
    v2.push_back(3);
    v2.push_back(41);

    vector<int> v3(3);
    v3[0] = 1;
    v3[1] = 2;
    v3[2] = 3;

    vector<int> v3Copy = v3;
    v3Copy.push_back(1);
    v3Copy.push_back(2);
    v3Copy.push_back(3);

    cout << "Test 1.1.1 " << testStatus(divide(v, 10)) << endl;
    cout << "Test 1.1.2 " << testStatus(!divide(v2, 10)) << endl;

    cout << "Test 1.2.1 " << testStatus(divideRec(v, 10)) << endl;
    cout << "Test 1.2.2 " << testStatus(!divideRec(v2, 10)) << endl;

    cout << "Test 2.1.1 " << testStatus(maximo(v) == 40) << endl;
    cout << "Test 2.1.2 " << testStatus(maximo(v2) == 41) << endl;

    cout << "Test 2.2.1 " << testStatus(maximoRec(v) == 40) << endl;
    cout << "Test 2.2.2 " << testStatus(maximoRec(v2) == 41) << endl;

    cout << "Test 3.1.1 " << testStatus(pertenece(40, v)) << endl;
    cout << "Test 3.1.2 " << testStatus(!pertenece(-1, v2)) << endl;

    cout << "Test 3.2.1 " << testStatus(perteneceRec(40, v)) << endl;
    cout << "Test 3.2.2 " << testStatus(!perteneceRec(-1, v2)) << endl;

    cout << "Vector 1: ";
    mostrarVector(v);

    cout << "Vector 2: ";
    mostrarVector(v2);

    cout << "Test 4.1 " << testStatus(limpiarDuplicados(v3Copy) == v3) << endl;
    cout << "Test 4.2 " << testStatus(limpiarDuplicados(vector<int>(10, 1)) == vector<int>(1, 1)) << endl;

    vector<int> test4_1Answer(3);
    test4_1Answer[0] = 2;
    test4_1Answer[1] = 3;
    test4_1Answer[2] = 1;
    cout << "Test 5.1 " << testStatus(rotar(v3, 1) == test4_1Answer) << endl;
    cout << "Test 5.2 " << testStatus(rotar(v2, v2.size()) == v2) << endl;

    vector<int> test5_1Answer(3);
    test5_1Answer[0] = 3;
    test5_1Answer[1] = 2;
    test5_1Answer[2] = 1;

    vector<int> test5_2Answer(5);
    test5_2Answer[0] = 41;
    test5_2Answer[1] = 3;
    test5_2Answer[2] = 40;
    test5_2Answer[3] = 30;
    test5_2Answer[4] = -20;

    cout << "Test 6.1.1 " << testStatus(reverso(v3) == test5_1Answer) << endl;
    cout << "Test 6.1.2 " << testStatus(reverso(v2) == test5_2Answer) << endl;

    cout << "Test 6.2.1 " << testStatus(reversoRec(v3) == test5_1Answer) << endl;
    cout << "Test 6.2.2 " << testStatus(reversoRec(v2) == test5_2Answer) << endl;

    vector<int> test7_1Answer(4);
    test7_1Answer[0] = 7;
    test7_1Answer[1] = 5;
    test7_1Answer[2] = 3;
    test7_1Answer[3] = 2;

    cout << "Test 7.1 " << testStatus(factoresPrimos(210) == test7_1Answer) << endl;
    cout << "Test 7.2 " << testStatus(factoresPrimos(7) == vector<int>(1, 7)) << endl;

    cout << "Test 8.1 " << testStatus(estaOrdenado(test7_1Answer)) << endl;
    cout << "Test 8.2 " << testStatus(estaOrdenado(v3)) << endl;
    cout << "Test 8.3 " << testStatus(!estaOrdenado(v2)) << endl;

    vector<bool> v4(4, true);
    vector<bool> v5 = v4;
    v5[1] = false;
    negadorDeBooleanos(v4);
    negadorDeBooleanos(v5);
    vector<bool> test9_2Answer(4, false);
    test9_2Answer[1] = true;
    cout << "Test 9.1 " << testStatus(v4 == vector<bool>(4, false)) << endl;
    cout << "Test 9.2 " << testStatus(v5 == test9_2Answer) << endl;

    vector<int> v6(4, 1);
    vector<int> v7 = v6;
    v7[2] = 2;
    sinImpares(v6);
    sinImpares(v7);
    vector<int> test10_2Answer(4, 0);
    test10_2Answer[2] = 2;
    cout << "Test 10.1 " << testStatus(v6 == vector<int>(4, 0)) << endl;
    cout << "Test 10.2 " << testStatus(v7 == test10_2Answer) << endl;

    vector<pair<int, int>> test11_2Answer(3);
    test11_2Answer[0] = pair<int, int>(1, 1);
    test11_2Answer[1] = pair<int, int>(2, 1);
    test11_2Answer[2] = pair<int, int>(3, 1);

    vector<int> v8(3);
    v8[0] = 1;
    v8[1] = 2;
    v8[2] = 3;

    vector<int> v9 = v8;
    v9.push_back(1);
    vector<pair<int, int>> test11_3Answer = test11_2Answer;
    test11_3Answer[0] = pair<int, int>(1, 2);

    cout << "Test 11.1 " << testStatus(cantidadApariciones(vector<int>(4, 1)) == vector<pair<int, int>>(1, pair<int, int>(1, 4))) << endl;
    cout << "Test 11.2 " << testStatus(cantidadApariciones(v8) == test11_2Answer) << endl;
    cout << "Test 11.3 " << testStatus(cantidadApariciones(v9) == test11_3Answer) << endl;

    return 0;
}