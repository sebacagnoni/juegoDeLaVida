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
//EJ 3************************************************************//


//EJ 4************************************************************//
int superficieTotal(toroide t){
    return t.size() * (t[0]).size();


}
//EJ 5************************************************************//

