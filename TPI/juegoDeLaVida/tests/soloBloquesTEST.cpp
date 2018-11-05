#include "../solucion.h"
#include "gtest/gtest.h"

using namespace std;

TEST(soloBloquesTEST, toroideMuerto) {
    toroide t = {{false, false, false, false},
                 {false, false, false, false},
                 {false, false, false, false},
                 {false, false, false, false}};
    EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST, toroideUnBloquePuro) {
    toroide t = {{false, false, false, false},
                 {false, true,  true,  false},
                 {false, true,  true,  false},
                 {false, false, false, false}};
    EXPECT_TRUE(soloBloques(t));
}

TEST(soloBloquesTEST, toroideTodoVivo) {
    toroide t = {{true, true},
                 {true, true}};
    EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST, toroideBloqueCortadoPuro) {
    toroide t = {{false, false, false},
                 {false, true,  true},
                 {false, true,  true},
                 {false, false, false}};
    EXPECT_TRUE(soloBloques(t));
}

TEST(soloBloquesTEST, toroideMultiplesBloquesPuro) {
    toroide t = {{false, false, false, false},
                 {false, true,  true,  false},
                 {false, true,  true,  false},
                 {false, false, false, false},
                 {false, false, false, false},
                 {false, false, true,  true},
                 {false, false, true,  true}};
    EXPECT_TRUE(soloBloques(t));
}

TEST(soloBloquesTEST, evolucionEsToroideBloquePuro) {
    toroide t = {{false, false, false, false},
                 {false, false, true,  false},
                 {false, true,  true,  false},
                 {false, false, false, false}};
    EXPECT_FALSE(soloBloques(t));
}

TEST(soloBloquesTEST, toroideMultiplesBloquesImpuro) {
    toroide t = {{false, false, false, false},
                 {false, true,  true,  false},
                 {false, true,  true,  false},
                 {false, false, false, false},
                 {true,  false, false, false},
                 {false, false, true,  true},
                 {false, false, true,  true}};
    EXPECT_FALSE(soloBloques(t));
}