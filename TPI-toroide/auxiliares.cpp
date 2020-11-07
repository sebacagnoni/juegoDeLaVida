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


bool esRectangulo(vector<vector<bool>> r){
    return ((r.size() > 0) && (cant_columnas(r) > 0) && (misma_longitud_secuencias(r)));

}

bool esToroide(vector<vector<bool>> t){
    return ((t.size() >= 3) && (esRectangulo(t)) && (cant_columnas(t) >= 3));
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
    return (enRangoToroide(f,c,t) && (t[f][c] == true));

}

//CONSULTAR SI HAY OTRA FORMA DE QUE -1 % 2 = 1 Y NO -1
bool vivaToroide(int f, int c, toroide t){
    bool verif = false;
        f = f + t.size();
        c = c + ((t[0]).size());
        verif = (Estaviva(f % t.size(), c % ((t[0]).size()), t));


        return verif;
}

bool vecinaViva(toroide t, int f, int c, int i, int j){
    return vivaToroide((f+i), (c+j), t);
}
/* f = 0, c = 0
 * si (0 == 0 || 0 == 0) = false
vV(t, 0, 0, -1, -1) && (-1 != 0 || -1 != 0)--> vT(0-1,0-1, t) --> Et(-1 % 4= 3, -1 % 4 = 3)  = false
vV(t, 0, 0, -1,  0) && (-1 != 0 ||  0 != 0)--> vT(0-1,0  , t) --> Et(-1 % 4= 3, 0 % 4 = 0 ) = false
vV(t, 0, 0, -1,  1) && (-1 != 0 ||  1 != 0)--> vT(0-1, 1 , t) --> Et(3, 1, t) = false

vV(t, 0, 0, 0, 2) --> vT(0-1, 1 , t) --> Et(3, 1, t) = false


*/
int vecinosVivos(toroide t, int f, int c){
    int sumaVivos = 0;
    for(int i = -1; i < 2; i++) {
       for (int j = -1; j < 2; j++){
           if((vecinaViva(t, f, c, i, j) && ((i != 0) || (j != 0))) ){
            sumaVivos++;
            }
           else{
           }

       }
    }

    return sumaVivos;
}


//EJ 6************************************************************//

bool EstaMuerta(int f, int c, toroide t){
    return enRangoToroide(f,c,t) && t[f][c] == false;

}


bool debeVivir(toroide t, int f,  int c){
    return (Estaviva(f, c, t) && (2 <= vecinosVivos(t, f, c)) && (vecinosVivos(t, f, c) <= 3)) ||
           (EstaMuerta(f, c, t) && (vecinosVivos(t, f, c) == 3)) ;

}
//EJ 7************************************************************//
//PREGUNTAR POR CON +2 Y NO CON SOLO .SIZE()
vector<bool>vaciarSecuencia(vector<bool> sec){
    int i = 0;
    while(i < sec.size()+2){
        sec.pop_back();
        i++;
    }
    return sec;
}

//CAMBIA A T?
void evolucionarToroideUnTick(toroide &t){
vector<vector<bool>>evoldt;
vector<bool> secEv;
for(int f = 0; f < t.size(); f++){
    for(int c = 0; c < (t[f]).size(); c++){
        if(debeVivir(t,f,c)){
            secEv.push_back(true);

        }
        else{
            secEv.push_back(false);
        }
    }
    evoldt.push_back(secEv);
    secEv = vaciarSecuencia(secEv);

}

t = evoldt;


}