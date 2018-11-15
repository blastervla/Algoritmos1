#include "../../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

//
// Created by vladimir pomsztein on 15/11/2018.
//

TEST(esValidoTEST, toroideVacio1Fila){
    toroide t = {{}};
    EXPECT_FALSE(esValido(t));
}

TEST(esValidoTEST, tresPorTres){
    toroide t = {
            {true, false, false},
            {false, false, true},
            {false, true, false}};
    EXPECT_TRUE(esValido(t));
}