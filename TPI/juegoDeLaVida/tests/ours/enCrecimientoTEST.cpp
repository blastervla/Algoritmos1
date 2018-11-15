#include "../../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

//
// Created by vladimir pomsztein on 15/11/2018.
//

TEST(enCrecimientoTEST, periodicoMantieneArea) {
toroide t1 = {
        {false, false, false, false, false},
        {false, true,  true,  true,  false},
        {false, false, false, false, false}};
EXPECT_FALSE(enCrecimiento(t1));
}

TEST(enCrecimientoTEST, creceArea) {
toroide t1 = {
        {false, false, false},
        {true,  true,  true},
        {false, false, false}};
EXPECT_TRUE(enCrecimiento(t1));
}

TEST(enCrecimientoTEST, periodicoMantieneAreaBorder) {
toroide t1 = {
        {false, true,  true,  true, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false},
        {false, false, false, false, false}};
EXPECT_FALSE(enCrecimiento(t1));
}

TEST(enCrecimientoTEST, reduceAreaBorder) {
toroide t1 = {
        {false, true,  true, false},
        {true,  false, false, false},
        {false, false, false, false}};
EXPECT_FALSE(enCrecimiento(t1));
}

TEST(enCrecimientoTEST, explosionCrece) {
toroide t1 = {
        {false, false, false, false, false},
        {false, true,  true,  true,  false},
        {false, true,  false, true,  false},
        {false, true,  false, true,  false},
        {false, false, true,  false, false},
        {false, false, false, false, false}};
EXPECT_TRUE(enCrecimiento(t1));
}

TEST(enCrecimientoTEST, muyPodableCrece) {
toroide t1 = {
        {false, false, false, false, true, false, false, false, false},
        {false, false, false, false, true, false, false, false, false},
        {false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false},
        {false, false, false, true,  true,  true,  false, false, false},
        {false, false, false, true,  false, true,  false, false, false},
        {false, false, false, true,  false, true,  false, false, false},
        {false, false, false, false, true,  false, false, false, false},
        {false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false},
        {false, false, false, false, false, false, false, false, false},
        {false, false, false, false, true, false, false, false, false}};
EXPECT_TRUE(enCrecimiento(t1));
}