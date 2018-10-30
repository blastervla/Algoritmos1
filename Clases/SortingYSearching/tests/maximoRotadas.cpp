#include "../src/ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(maximoRotadasTest, maximoListaUnitaria){
    vector<int> l = {3};
    ASSERT_EQ(3, maximoRotadas(l));
}

TEST(maximoRotadasTest, maximoListaDeDos){
    vector<int> l = {3, 1};
    ASSERT_EQ(3, maximoRotadas(l));
}

TEST(maximoRotadasTest, maximoListaDeTres){
    vector<int> l = {7, 8, 1};
    ASSERT_EQ(8, maximoRotadas(l));
}

TEST(maximoRotadasTest, maximoListaRotadaLongImpar){
    vector<int> l = {9, 20, 1, 3, 5};
    ASSERT_EQ(20, maximoRotadas(l));
}

TEST(maximoRotadasTest, maximoListaRotadaLongPar){
    vector<int> l = {9, 20, 1, 3, 5, 6};
    ASSERT_EQ(20, maximoRotadas(l));

}

TEST(maximoRotadasTest, maximoListaRotadaLongPar1){
    vector<int> l = {7, 8, 1, 2, 3, 4, 5, 6};
    ASSERT_EQ(8, maximoRotadas(l));
}

TEST(maximoRotadasTest, maximoListaNoRotadaLongImpar){
    vector<int> l = {1, 3, 5, 9, 20};
    ASSERT_EQ(20, maximoRotadas(l));
}

TEST(maximoRotadasTest, maximoListaNoRotadaLongPar){
    vector<int> l = {1, 3, 5, 6, 9, 20};
    ASSERT_EQ(20, maximoRotadas(l));

}

TEST(maximoRotadasTest, maximoListaNoRotadaLongPar1){
    vector<int> l = {1, 2, 3, 4, 5, 6, 7, 8};
    ASSERT_EQ(8, maximoRotadas(l));

}


