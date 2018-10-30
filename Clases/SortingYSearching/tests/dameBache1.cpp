#include "../src/ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(dameBache1Test, vacio){
    vector<int> s;
    ASSERT_EQ(0, dameBache1(s));
}

TEST(dameBache1Test, ordenados){
    vector<int> s={0,1,2};
    ASSERT_EQ(3, dameBache1(s));
}

TEST(dameBache1Test, desordenados1){
    vector<int> s={3,-1,1,0};
    ASSERT_EQ(2, dameBache1(s));
}

TEST(dameBache1Test, desordenados2){
    vector<int> s={-5,-2,-3};
    ASSERT_EQ(-4, dameBache1(s));
}

TEST(dameBache1Test, muchosBaches1){
    vector<int> s={1, 2, 3, 100, 101};
    ASSERT_EQ(4, dameBache1(s));
}

TEST(dameBache1Test, muchosBaches2){
    vector<int> s={-5, -2, 1};
    ASSERT_EQ(-4, dameBache1(s));
}
