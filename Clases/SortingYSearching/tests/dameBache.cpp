#include "../src/ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(dameBacheTest, vacio){
    vector<int> s;
    ASSERT_EQ(0, dameBache(s));
}

TEST(dameBacheTest, ordenados){
    vector<int> s={0,1,2};
    ASSERT_EQ(3, dameBache(s));
}

TEST(dameBacheTest, desordenados1){
    vector<int> s={3,-1,1,0};
    ASSERT_EQ(2, dameBache(s));
}

TEST(dameBacheTest, desordenados2){
    vector<int> s={-5,-2,-3};
    ASSERT_EQ(-4, dameBache(s));
}

