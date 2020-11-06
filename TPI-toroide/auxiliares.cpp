#include "definiciones.h"
#include "auxiliares.h"

using namespace std;
// aqui se pueden ubicar todas las funciones auxiliares de soporte para la resolucion de los ejercicios
pair<int,int> mp(int a, int b) {
    return make_pair(a, b);
}
//No pueden usar esta función para resolver el TPI.
//Tampoco pueden usar iteradores, como usa esta función.
vector<posicion> ordenar(vector<posicion> &v) {
    sort(v.begin(), v.end());
    return v;
}


//EJ 1************************************************************//

int cant_columnas(vector<vector<bool>> t){
    int cant = 0;
    if(t.size() > 0){
        cant = (t[0]).size();


    }

    return cant;
}

bool misma_longitud_secuencias(vector<vector<bool>> r){
    bool res = true;
    for(int i = 1; i < r.size() && (res == true) ; i++){
        res = ((r[i].size()) == ((r[0]).size()));

    }
    return res;
}

//PREGUNTAR ITERADORES
bool esRectangulo(vector<vector<bool>> r){
    return ((r.size() > 0) && (cant_columnas(r) > 0) && (misma_longitud_secuencias(r)));

}

//EJ 2************************************************************//



bool enRangoToroide(int f, int c, vector<vector<bool>> t){
    return (t.size() > 0) && (f >= 0 && f < t.size()) && (c >= 0 && c < t[0].size());

}

//EJ 3************************************************************//
//se indefine si el toroide no tiene columnas
int cantidadDeVivas(vector<vector<bool>> t){
    int cantidad = 0;
    for(int f = 0; f < t.size() ; f++){
        for(int c = 0; c < t[f].size() ; c++){
            if(t[f][c] == true){
                cantidad++;
            }


        }


    }
    return cantidad;

}

//EJ 4************************************************************//
int superficieTotal(toroide t){
    return t.size() * (t[0]).size();


}
//EJ 5************************************************************//
/*
bool enRangoToroide2(int f, int c, toroide t){
    return (t.size() > 0) && (f >= 0 && f < t.size()) && (c >= 0 && c < t[0].size());

}
*/
bool Estaviva(int f, int c, toroide t){
    return enRangoToroide(f,c,t) && t[f][c] == true;

}
bool vivaToroide(int f, int c, toroide t){

    return Estaviva(f % t.size(), c % (t[0]).size(), t);


}

bool vecinaViva(toroide t, int f, int c, int i, int j){

    return vivaToroide(f+i, c+j, t);
}
/* f = 0, c = 0
vV(t, 0, 0, -1, -1) --> vT(0-1,0-1, t) --> Et(-1 % 4= 3, -1 % 4 = 3) = false
vV(t, 0, 0, -1,  0) --> vT(0-1,0  , t) --> Et(-1 % 4= 3, 0 % 4 = 0 ) = false
vV(t, 0, 0, -1,  1) --> vT(0-1, 1 , t) --> Et(3, 1, t) = false

vV(t, 0, 0, 0, 2) --> vT(0-1, 1 , t) --> Et(3, 1, t) = false


*/
int vecinosVivos(toroide t, int f, int c){
    int sumaVivos = 0;
for(int i = -1; i < 2; i++) {
    for (int j = -1; j < 2; j++){
        if(vecinaViva(t, f, c, i, j) && (i != 0 || j != 0)){
            sumaVivos++;
        }
    }
}

return sumaVivos;
}


//EJ 6************************************************************//

bool EstaMuerta(int f, int c, toroide t){
    return enRangoToroide(f,c,t) && t[f][c] == false;

}


bool debeVivir(toroide t, int f, int c){
    return (Estaviva(f,c,t) && (2 <= vecinosVivos(t,f,c)) && (vecinosVivos(t,f,c) <= 3)) ||
            (EstaMuerta(f,c,t) && vecinosVivos(t,f,c) == 3) ;

}
//EJ 7************************************************************//