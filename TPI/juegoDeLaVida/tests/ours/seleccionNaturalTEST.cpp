#include "../../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

//
// Created by vladimir pomsztein on 15/11/2018.
//

TEST(seleccionNaturalTEST, periodicoVsMortal) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true,  true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false},
            {false, true,  false},
            {false, false, true}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}

TEST(seleccionNaturalTEST, desembocaEnPeriodicoVsMortal) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, true,  false, false},
            {false, true,  true,  true,  false},
            {false, true,  false, true,  false},
            {false, false, true,  false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false},
            {false, true,  false},
            {false, false, true}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}