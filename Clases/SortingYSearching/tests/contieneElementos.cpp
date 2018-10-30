#include "../src/ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(contieneElementosTest, secAVacia){
    vector<int> a;
    vector<int> b = {1, 2, 3};

    ASSERT_FALSE(contieneElementos(a, b));
}

TEST(contieneElementosTest, secBVacia){
    vector<int> a = {1, 2, 3};
    vector<int> b;

    ASSERT_TRUE(contieneElementos(a, b));
}

TEST(contieneElementosTest, secASinRepetidos){

    vector<int> a = {1, 2, 3};
    vector<int> b = {2, 3, 4};

    ASSERT_FALSE(contieneElementos(a, b));
}

TEST(contieneElementosTest, secAConRepetidos){
    vector<int> a = {1, 1, 2, 3};
    vector<int> b = {1, 2, 3};

    ASSERT_TRUE(contieneElementos(a, b));
}

TEST(contieneElementosTest, secBConRepetidos){
    vector<int> a = {1, 1, 2, 3};
    vector<int> b = {1, 2, 2, 3};

    ASSERT_TRUE(contieneElementos(a, b));
}


