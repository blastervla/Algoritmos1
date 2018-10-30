#include "../src/ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(naipesFaltantesTest, sinNaipes){

    vector<int> naipes;
    vector<int> faltantesEsperado = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    vector<int> faltantes = naipesFaltantes(naipes);

    ASSERT_EQ(faltantesEsperado, naipesFaltantes(naipes));
}

TEST(naipesFaltantesTest, naipesConFaltantes){

    vector<int> naipes = {12, 11, 8, 6, 5, 1, 2, 7};
    vector<int> faltantesEsperado = {3, 4, 9, 10};
    vector<int> faltantes = naipesFaltantes(naipes);

    ASSERT_EQ(faltantesEsperado, naipesFaltantes(naipes));
}

TEST(naipesFaltantesTest, naipesSinFaltantes){

    vector<int> naipes = {12, 11, 8, 6, 9, 3, 5, 1, 2, 10, 7, 4};
    vector<int> faltantesEsperado;
    vector<int> faltantes = naipesFaltantes(naipes);

    ASSERT_EQ(faltantesEsperado, naipesFaltantes(naipes));
}
