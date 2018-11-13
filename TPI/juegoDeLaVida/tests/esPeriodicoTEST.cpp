#include "../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(esPeriodicoTEST, toroideHorizontalPeriodico2) {
    toroide t = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true,  true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 2);
}

TEST(esPeriodicoTEST, toroideTodoFalso) {
    toroide t = {{false, false, false},
                 {false, false, false},
                 {false, false, false}};
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_TRUE(res);
    EXPECT_EQ(p, 1);
}

TEST(esPeriodicoTEST, toroideDiagonal) {
    toroide t = {{true,  false, false},
                 {false, true,  false},
                 {false, false, true}};
    int p;
    bool res = esPeriodico(t, p);
    EXPECT_FALSE(res);
}

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
