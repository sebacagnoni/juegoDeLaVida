#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(fusionarTEST, sinInterseccion){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {false, true, true},
                  {true, false, true},
                  {true, true, false}};

    toroide tout = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}
/********************************************************************/

TEST(fusionarTEST, ConInterseccionEnLaDiagonal){
    toroide t1 = {
            {true, false, false},
            {false, true, false},
            {false, false, true}};
    toroide t2 = {
            {true, true, true},
            {true, true, true},
            {true, true, true}};

    toroide tout = {
            {true,  false, false},
            {false, true, false},
            {false, false, true}};

    toroide res = fusionar(t1, t2);
    EXPECT_EQ(res, tout);
}