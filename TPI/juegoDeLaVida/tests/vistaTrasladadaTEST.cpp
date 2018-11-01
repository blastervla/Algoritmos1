#include "../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(vistaTrasladadaTEST, unoInvalido) {
    toroide t1 = {
            {true, false, false},
            {false}};
    toroide t2 = {
            {false, false, true},
            {true,  false, false},
            {false, true,  false}};

    EXPECT_FALSE(vistaTrasladada(t1, t2));
    EXPECT_FALSE(vistaTrasladada(t2, t1));
}

TEST(vistaTrasladadaTEST, distintaDimension) {
    toroide t1 = {
            {true, false, false},
            {false, true, false},
            {false, false, false},
            {false, true, false}};
    toroide t2 = {
            {false, false, true}, // 3
            {true,  false, false}, // 1
            {false, true,  false}};// 2

    EXPECT_FALSE(vistaTrasladada(t1, t2));
    EXPECT_FALSE(vistaTrasladada(t2, t1));
}

TEST(vistaTrasladadaTEST, muevoTerceraFilaParaArriba) {
    toroide t1 = {
            {true,  false, false}, // 1
            {false, true,  false}, // 2
            {false, false, true}};// 3
    toroide t2 = {
            {false, false, true}, // 3
            {true,  false, false}, // 1
            {false, true,  false}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, DiagonalVsTodoTrue) {
    toroide t1 = {
            {true,  false, false},
            {false, true,  false},
            {false, false, true}};
    toroide t2 = {
            {true, true, true},
            {true, true, true},
            {true, true, true}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}
