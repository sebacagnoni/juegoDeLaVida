#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(vistaTrasladadaTEST, muevoTerceraFilaParaArriba){
    toroide t1 = { 
                  {true, false, false}, // 1
                  {false, true, false}, // 2
                  {false, false, true}};// 3
    toroide t2 = { 
                  {false, false, true}, // 3
                  {true, false, false}, // 1
                  {false, true, false}};// 2

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}

TEST(vistaTrasladadaTEST, DiagonalVsTodoTrue){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}}; 
    toroide t2 = { 
                  {true, true, true},
                  {true, true, true},
                  {true, true, true}}; 
    bool res = vistaTrasladada(t1, t2);
    EXPECT_FALSE(res);
}

/*********************************************************************/

TEST(vistaTrasladadaTEST, TresMovArribaYDosMovAlaIzquierda){
    toroide t1 = {
            // 0    //1    //2    //3     //4
            {false, true,  true,  false,  false},   // 0
            {false, false, false, false,  false},   // 1
            {false, false, true,  false,  false},   // 2
            {true,  false, true,  true,   true }    // 3
    };
    toroide t2 = {
            //2    //3     //4    //0     //1
            {true,  true,  true,  true,  false},  //3
            {true,  false, false, false, true },  //0
            {false, false, false, false, false},  //1
            {true,  false, false, false, false}   //2
    };

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}


TEST(vistaTrasladadaTEST, TresMovALaDerecha){
    toroide t1 = {
            // 0    //1    //2    //3     //4
            {true,  true,  true,  false,  false},   // 0
            {false, true, false,  false,  false},   // 1
            {false, false, true,  false,  false},   // 2
            {true,  false, true,  true,   true }    // 3
    };
    toroide t2 = {
            // 2    //3    //4    //0     //1
            {true,  false, false, true,   true},    // 0
            {false, false, false, false,  true},    // 1
            {true,  false, false, false,  false},   // 2
            {true,  true, true,   true,   false}    // 3
    };

    bool res = vistaTrasladada(t1, t2);
    EXPECT_TRUE(res);
}