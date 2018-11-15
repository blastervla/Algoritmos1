#include "../../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

//
// Created by vladimir pomsztein on 15/11/2018.
//

TEST(esPeriodicoTEST, bloque) {
    toroide t = {{false, true,  true},
                 {false, true,  true},
                 {false, false, false}};
    int p = 0;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 1);
}

TEST(esPeriodicoTEST, smallExplosion) {
    toroide t = {
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, true,  false, false ,false, false, false},
            {false, false, false, false, true,  true,  true,  false ,false, false, false},
            {false, false, false, false, true,  false, true,  false ,false, false, false},
            {false, false, false, false, false, true,  false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false},
            {false, false, false, false, false, false, false, false ,false, false, false}};
    int p = 0;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p, 0);
}

TEST(esPeriodicoTEST, smallExplosionDesembocaEnPeriodico) {
    toroide t = {
            {false, false, false, false, false},
            {false, false, true,  false, false},
            {false, true,  true,  true,  false},
            {false, true,  false, true,  false},
            {false, false, true,  false, false},
            {false, false, false, false, false}};
    int p = 0;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
    EXPECT_EQ(p, 0);
}