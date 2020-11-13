#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;


TEST(primosLejanosTEST, toroideHorizontalPeriodico2){
    toroide t1 = { 
                  {false, false, false, false, false}, 
                  {false, false, false, false, false}, 
                  {false, true, true, true, false},
                  {false, false, false, false, false}, 
                  {false, false,false, false, false} };
    toroide t2 = { 
                  {false, false, false, false, false}, 
                  {false, false, true, false, false}, 
                  {false, false, true, false, false},
                  {false, false, true, false, false}, 
                  {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, T1VacioT2TresVivos){
    toroide t1 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false,false, false, false} };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, true, false, false},
            {false, false, true, false, false},
            {false, false, true, false, false},
            {false, false,false, false, false} };
    bool res = primosLejanos(t1, t2);
    EXPECT_FALSE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}
/**************************************************************/


TEST(primosLejanosTEST, MuereAlTickOcho){
    toroide t1 = {
            {false, false, true, false, true },
            {false, true, false, false, false},
            {false, false, true, true,  false},
            {false, false, true, false, true }
    };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false },
            {false, false, false, false, false }
    };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}
//TRUE?

TEST(primosLejanosTEST, TodoTrue){
    toroide t1 = {
            {true, true, true, true, true },
            {true, true, true, true, true },
            {true, true, true, true, true },
            {true, true, true, true, true }
    };
    toroide t2 = {
            {false, false, false, false, false},
            {false, false, false, false, false},
            {false, false, false, false, false },
            {false, false, false, false, false }
    };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_FALSE(res);
}



TEST(primosLejanosTEST, MuereAlTickCinco){
    toroide t1 = {
            {true,  false, false, false},
            {false, false, false, false},
            {false, true,  true,  false},
            {false, false, false, true},
             };
    toroide t2 = {
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, false},
             };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}

TEST(primosLejanosTEST, Oscilador){
    toroide t1 = {
            {false, false, false, false, false, false},
            {false, false, true,  true,  false, false},
            {false, true,  false, false, false, false},
            {false, false, false, false, true,  false},
            {false, false, true,  true,  false, false},
            {false, false, false, false, false, false},
    };
    toroide t2 = {
            {false, false, false, false, false, false},
            {false, false, true,  false, false, false},
            {false, false, true,  true, false, false},
            {false, false, true,  true, false, false},
            {false, false, false, true, false, false},
            {false, false, false, false, false, false}
    };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}


TEST(primosLejanosTEST, Nave){
    toroide t1 = {
            {false, false, false, false, false, false},
            {false, false, true,  false, false, false},
            {false, false, false, true,  false, false},
            {false, true,  true,  true,  false, false},
            {false, false, false, false, false, false},
            {false, false, false, false, false, false},
    };
    toroide t2 = {
            {false, false, false, false, false, false},
            {false, false, false, false, false, false},
            {false, false, false, false, false, false},
            {false, false, false, false,  true, false},
            {false, false, false, false, false, true },
            {false, false, false,  true,  true, true }
    };
    bool res = primosLejanos(t1, t2);
    EXPECT_TRUE(res);
    res = primosLejanos(t2, t1);
    EXPECT_TRUE(res);
}