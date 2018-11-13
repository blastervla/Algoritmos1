#include "../solucion.h"
#include "gtest/gtest.h"

using namespace std;

// void testeo (vector<bool> &s, vector<bool> &res) {
//     ASSERT_EQ(s.size(), res.size());
//     for (int i = 0; i < s.size(); ++i) {
//         EXPECT_EQ(s[i], res[i]);
//     }
// }

TEST(esValidoTEST, toroideVacio){
    toroide t = {};
    EXPECT_FALSE(esValido(t));
}

TEST(esValidoTEST, toroideVacio1Fila){
    toroide t = {{}};
    EXPECT_FALSE(esValido(t));
}

TEST(esValidoTEST, toroideVacio5Filas){
    vector<bool> vacio;
    toroide t = { vacio, vacio, vacio, vacio, vacio };
    EXPECT_FALSE(esValido(t));
}

TEST(esValidoTEST, distintasFilas){
    vector<bool> a = { };
    vector<bool> b = { true };
    toroide t = { a, b };
    EXPECT_FALSE(esValido(t));
}

TEST(esValidoTEST, distintasFilasPrimeraNoVacia){
    vector<bool> a = { true };
    vector<bool> b = { };
    toroide t = { a, b };
    EXPECT_FALSE(esValido(t));
}

TEST(esValidoTEST, distintasFilasSinVacias){
    vector<bool> a = { false };
    vector<bool> b = { false, true };
    toroide t = { a, b };
    EXPECT_FALSE(esValido(t));
}

TEST(esValidoTEST, unoPorUno){
    vector<bool> a = { false };
    toroide t = { a };
    EXPECT_TRUE(esValido(t));
}

TEST(esValidoTEST, tresPorTres){
    toroide t = {
    {true, false, false},
    {false, false, true},
    {false, true, false}};
    EXPECT_TRUE(esValido(t));
}

TEST(esValidoTEST, diagonalTresPorTres) {
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true}
    };
    EXPECT_TRUE(esValido(t));
}