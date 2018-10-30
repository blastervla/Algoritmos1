#include "../src/ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(perteneceRotadasTest, noPerteneceARotada){
    vector<int> l = {9, 20, 1, 3, 5};
    int elem = 45;
    ASSERT_FALSE(perteneceRotadas(l, elem));
}


TEST(perteneceRotadasTest, listaVacia){
    vector<int> l;
    int elem = 3;
    ASSERT_FALSE(perteneceRotadas(l, elem));
}

TEST(perteneceRotadasTest, noPertenece){
    vector<int> l = {3, 1};
    int elem = 0;
    ASSERT_FALSE(perteneceRotadas(l, elem));
}

TEST(perteneceRotadasTest, perteneceARotada){
    vector<int> l = {9, 20, 1, 3, 5};
    int elem = 20;
    ASSERT_TRUE(perteneceRotadas(l, elem));

}

TEST(perteneceRotadasTest, perteneceARotada1){
    vector<int> l = {7, 8, 1, 2, 3, 4, 5, 6};
    int elem = 3;
    ASSERT_TRUE(perteneceRotadas(l, elem));

}


TEST(perteneceRotadasTest, perteneceANoRotada){
    vector<int> l = {1, 2, 3, 4};
    int elem = 2;
    ASSERT_TRUE(perteneceRotadas(l, elem));

}

TEST(perteneceRotadasTest, perteneceANoRotada1){

    vector<int> l = {1, 2, 3, 4, 5, 6, 7, 8};
    int elem = 3;
    ASSERT_TRUE(perteneceRotadas(l, elem));

}


TEST(perteneceRotadasTest, noPerteneceANoRotada){
    vector<int> l = {1, 2, 3, 4};
    int elem = 9;
    ASSERT_FALSE(perteneceRotadas(l, elem));


}

TEST(perteneceRotadasTest, perteneceAElemTodosIguales){
    vector<int> l = {1, 1, 1};
    int elem = 1;
    ASSERT_TRUE(perteneceRotadas(l, elem));
}



