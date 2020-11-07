#include "../ejercicios.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(cantidadVecinosVivosTEST, seisVivos){
    toroide t = {
            {true, false, false, false},
            {false, false, true, true},
            {false, false, false, false},
            {true, false, true, true}};

    EXPECT_EQ(cantidadVecinosVivos(t, 0, 3), 6);
}

TEST(cantidadVecinosVivosTEST, Ninguno){
    toroide t = {
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false}};

    EXPECT_EQ(cantidadVecinosVivos(t, 0, 3), 0);
}

TEST(cantidadVecinosVivosTEST, Caso2){
    toroide t = {
            {false, false, false, false},
            {false, true, false, false},
            {false, false, false, false},
            {false, false, false, true}};

    EXPECT_EQ(cantidadVecinosVivos(t, 0, 0), 2);
}

TEST(cantidadVecinosVivosTEST, TodoRodeado){
    toroide t = {
            {true, false, true, false},
            {true, true,  true, true },
            {false, true, true, false},
            {true, false, true, true}};

    EXPECT_EQ(cantidadVecinosVivos(t, 0, 3), 8);
}


TEST(cantidadVecinosVivosTEST, CincoVivos){
    toroide t = { {true, true, true },
                  {true, true, true},
                  {true, true, true }
    };
    EXPECT_EQ(cantidadVecinosVivos(t, 2, 0), 8);
}

TEST(cantidadVecinosVivosTEST, dsdasdsd){
    toroide t = {
            {true, true, true,  true},
            {true, true,  true, true },
            {false, true, true, false},
            {true, true, true, true}};

    EXPECT_EQ(cantidadVecinosVivos(t, 0, 0), 8);
}