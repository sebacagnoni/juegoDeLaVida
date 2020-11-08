#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

TEST(evolucionToroideTEST, toroideDiagonalTresPorTresUnPaso){
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true} };
    //1*0 0 1*0
    //0 1 0 0 1
    //0 0 1 0 0
    //1 0 0 1 0
    //0*1 0 0*1
    toroide evo_t = { {true, true, true},
                      {true, true, true},
                      {true, true, true} };
    //  1 1 1
    //  1 1 1
    //  1 1 1
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}
/*************************************************************/

TEST(evolucionToroideTEST, todoFalse){
    toroide t = { {false, false, false},
                  {false, false, false},
                  {false, false, false}};
    //1*0 0 1*0
    //0 1 0 0 1
    //0 0 1 0 0
    //1 0 0 1 0
    //0*1 0 0*1
    toroide evo_t = { {false, false, false},
                      {false, false, false},
                      {false, false, false} };
    //  0 0 0
    //  0 0 0
    //  0 0 0
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, todoTrue){
    toroide t = { {true, true, true},
                  {true, true, true},
                  {true, true, true}};

    toroide evo_t = { {false, false, false},
                      {false, false, false},
                      {false, false, false} };
    //  0 0 0
    //  0 0 0
    //  0 0 0
    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}

TEST(evolucionToroideTEST, CuatroFilasSieteColumnas){
    toroide t = { {false, true, false, false, true, false, true},
                  {false, true, false, false, true, true, false},
                  {true, true, true, false, true, false, true},
                  {true, true, false, true, true, false, false}};

    toroide evo_t = { {false, true, false, false, false, false, true},
                      {false, false, false, false, true, false, false},
                      {false, false, false, false, false, false, true},
                      {false, false, false, false, true, false, false}};

    evolucionToroide(t);
    EXPECT_EQ(t, evo_t);
}