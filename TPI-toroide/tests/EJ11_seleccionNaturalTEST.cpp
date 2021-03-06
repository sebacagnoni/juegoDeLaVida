#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <algorithm>

using namespace std;

//Eliminar un test periodico que no cumple la precondición
TEST(seleccionNaturalTEST, toroideDiagonalVsUnoVivo){
    toroide t1 = { 
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}};

    toroide t2 = {
                  {false, false, false}, 
                  {false, false, false}, 
                  {false, true, false },
                  {false, false, false}, 
                  {false, false, false}};


    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}

//NO TESTEAR
TEST(seleccionNaturalTEST, DiagonalVsHorizontal){
    toroide t1 = {
                  {false, false, false, false, false},
                  {false, false, false, false, false},
                  {false, true, true, true, false},
                  {false, false, false, false, false},
                  {false, false,false, false, false} };
    toroide t2 = {
                  {true, false, false},
                  {false, true, false},
                  {false, false, true}};
    vector<toroide> ts;
    ts.push_back(t2);
    ts.push_back(t1);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 1);
}

/****************************************************************************/

TEST(seleccionNaturalTEST, UnToroideMuerto){
    toroide t1 = {
            {false, false, false},
            {false, false, false},
            {false, false, false}};

    toroide t2 = {
            {false, false, false},
            {false, false, false},
            {false, true, false },
            {false, false, false},
            {false, false, false}};


    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t2);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, -1);
}

TEST(seleccionNaturalTEST, UnSoloToroide){
    toroide t1 = {
            {true, false, false},
            {false, false, true},
            {false, true, false },
            {false, false, false},
            {false, false, false}};


    vector<toroide> ts;
    ts.push_back(t1);
    int res = seleccionNatural(ts);
    EXPECT_EQ(res, 0);
}



TEST(seleccionNaturalTEST, CuatroToroides){
    toroide t1 = {
            {true,  false, true },
            {false, false, true },
            {false, false, false}
           };

    toroide t2 = {
            {true, false,  true, false},
            {false, false, true, false},
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, true}};

    toroide t3 = {
            {true, false, false},
            {false, false, true},
            {false, true, false },
            {false, false, false},
            {false, false, false}};

    toroide t4 = {
            {true, false,  true,  false},
            {false, false, true,  false},
            {false, false, false, false},
            {false, false, false, false},
            {false, false, false, true }};


    vector<toroide> ts;
    ts.push_back(t1);
    ts.push_back(t2);
    ts.push_back(t3);
    ts.push_back(t4);
//Si dos toroides son iguales toma al ultimo
    int res = seleccionNatural(ts);
    EXPECT_EQ(res,3 );
}


