#include "../../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

//
// Created by vladimir pomsztein on 15/11/2018.
//

TEST(vistaTrasladadaTEST, rotacionAmbosEjes) {
    toroide t1 = {
            {false, false,  true, false, false},
            {false, false, true,  false, false},
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, true, true, true, false}};
    toroide t2 = {
            {false, false,  false, false, false},
            {true, false, false,  false, false},
            {true, true, false, false, true},
            {true, false, false, false, false},
            {true, false, false, false, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, mismoToroide) {
    toroide t1 = {
            {false, false,  false, false, false},
            {false, false, true,  false, false},
            {false, true, false, true, false},
            {false, false, true, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false,  false, false, false},
            {false, false, true,  false, false},
            {false, true, false, true, false},
            {false, false, true, false, false},
            {false, false, false, false, false}};
    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}