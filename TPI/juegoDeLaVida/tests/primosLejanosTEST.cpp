#include "../solucion.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(primosLejanosTEST, toroideHorizontalPeriodico2) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true,  true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, true,  false, false},
            {false, false, true,  false, false},
            {false, false, true,  false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, toroideNoPeriodicoUnoMuerto) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {true,  false, true,  true,  false},
            {true,  false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, toroideNoPeriodicoPrimos) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, true,  false},
            {false, false, false, true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, mismoToroideNoPeriodico) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, false, true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, mismoToroidePeriodico) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, true,  true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, true},
            {false, true,  true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, diferentesDimensiones) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, true,  true,  true,  false},
            {false, false, false, false, false},
            {false, false, false, false, false}};
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, true,  false, false},
            {false, false, true,  false, false},
            {false, false, true,  false, false}};
    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

TEST(primosLejanosTEST, desembocaEnPeriodicoVsToroideEnPartePeriodica) {
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, true,  false, false},
            {false, true,  true,  true,  false},
            {false, true,  false, true,  false},
            {false, false, true,  false, false},
            {false, false, false, false, false}};

    toroide t2 = {
            {false, false, true,  false, false},
            {false, true,  false, true,  false},
            {true,  true,  false, true,  true},
            {false, true,  false, true,  false},
            {false, false, true,  false, false},
            {false, false, false, false, false}};

    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}

