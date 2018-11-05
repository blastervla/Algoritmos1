#include "../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(enCrecimientoTEST, toroideDiagonalSeHaceTodoTrue) {
    toroide t1 = {
            {true,  false, false},
            {false, true,  false},
            {false, false, true}};
    bool res = enCrecimiento(t1);
    EXPECT_TRUE(res);
}

TEST(enCrecimientoTEST, todoFalsoNoCrece) {
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};
    bool res = enCrecimiento(t1);
    EXPECT_FALSE(res);
}

TEST(enCrecimientoTEST, periodicoMantieneArea) {
    toroide t1 = {
            {false, false, false},
            {true,  true,  true},
            {false, false, false}};
    EXPECT_FALSE(enCrecimiento(t1));
}