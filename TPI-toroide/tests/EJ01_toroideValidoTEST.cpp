#include "../ejercicios.h"
#include "gtest/gtest.h"

using namespace std;

TEST(toroideValidoTEST, toroideVacio){
    toroide t = { vector<bool> () };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, toroideVacio5Filas){
    vector<bool> vacio;
    toroide t = { vacio, vacio, vacio, vacio, vacio };
    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, diagonalTresPorTres) {
    toroide t = { {true, false, false},
                  {false, true, false},
                  {false, false, true}
    };
    EXPECT_TRUE(toroideValido(t));
}

/************************************************************/
TEST(toroideValidoTEST, FilasMenorATres){
    toroide t = {{true,false,false},
                 {false,false,false}

    };


EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, ColumnasMenorATres){
    toroide t = {{true,false},
                 {false,false},
                 {false,false}

    };


    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, TodoMenorATres){
    toroide t = {{true},
                 {false}


    };


    EXPECT_FALSE(toroideValido(t));
}

TEST(toroideValidoTEST, UnElemento){
    toroide t = {{true}


    };


    EXPECT_FALSE(toroideValido(t));
}


