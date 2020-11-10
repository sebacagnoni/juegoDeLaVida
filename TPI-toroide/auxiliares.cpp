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

bool EstoroideMuerto(toroide const &t) {

    bool resp = false;
    int f = 0;
    int c = 0;
    int chequeado = 0;
        while (f < t.size()) {
            while (c < (t[f]).size()) {
                if (!t[f][c]) {
                    chequeado++;
                }
                else {
                }
                c++;
            }
            c = 0;
            f++;
        }



    resp = (t.size() > 0) && (chequeado == (t[0].size()) * (t.size()));
    return resp;

}

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
    while(i < sec.size()){
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
    secEv.clear();

}

t = evoldt;


}

//EJ 8************************************************************//

toroide evolucionartoroideKVecesT(toroide t, int k){

    for(int i = 1; i <= k; i++){
        evolucionarToroideUnTick(t);
    }

    return t;
}

//EJ 9************************************************************//


//Solo sirve para t ciclicos que van de t,.....,t
bool cumpleEvolucionCiclica(toroide t){
    toroide tInicial;
    tInicial =  t;
    evolucionarToroideUnTick(t);
    while(not (EstoroideMuerto(t)) && (t != tInicial)){
        evolucionarToroideUnTick(t);


    }
    return (t == tInicial) && not(EstoroideMuerto(t));

}


//Solo para toroides que sabemos que son ciclicos
//Si sabemos que t NO muere tiene sentido
int TickDondeSeRepiteTdeLaEvolucion(toroide t){
   int tick = 1;
   vector<toroide> tt;
   tt.push_back(t);
   evolucionarToroideUnTick(t);

   while(not estaTenTT(tt,t)){
       evolucionarToroideUnTick(t);
       tt.push_back(t);
       tick++;

   }
   return tick;

}

int TickDondeSeRepiteT(toroide t){
    int tick = 1;
    toroide tInicial;
    tInicial = t;
    evolucionarToroideUnTick(t);

    while((t  != tInicial)){
        evolucionarToroideUnTick(t);
        tick++;

    }

    return tick;
}



//EJ 10************************************************************//
bool mismaDimension(toroide t, toroide u){
    return (t.size() == u.size()) && (cant_columnas(t) == cant_columnas(u));
}

bool estaTenTT(vector<toroide> tt,toroide t){
    int cheq = 0;
    for(int p = 0; (p < tt.size()) && (tt[0] != t); p++){
        cheq++;

    }
    return cheq < tt.size();

}
//si el toroide muere tiene sentido
int TickDondeMuere(toroide t){
    int tick = 1;
    evolucionarToroideUnTick(t);
    while(not EstoroideMuerto(t)){
        evolucionarToroideUnTick(t);
        tick++;

    }
    return tick;

}



/************************************************************************************/



vector<toroide> EvolucionesDeTNoCiclico(toroide t){
    vector<toroide> Evoluciones;
    Evoluciones.push_back(t);
    for(int p = 1; p <= TickDondeMuere(t); p++){
        evolucionarToroideUnTick(t);
        Evoluciones.push_back(t);
    }
    return Evoluciones;

}


vector<toroide> EvolucionesDeTCiclicos(toroide t){
    vector<toroide> Evoluciones;
    Evoluciones.push_back(t);
    for(int p = 1;p < TickDondeSeRepiteTdeLaEvolucion(t);p++){
        evolucionarToroideUnTick(t);
        Evoluciones.push_back(t);
    }
    return Evoluciones;
}




// el ciclico original esta contemplado
/*
bool cumpleEvolucionCiclicaCorrida(toroide t){
    vector<toroide> tt;
    tt.push_back(t);
    evolucionarToroideUnTick(t);
    while(not(EstoroideMuerto(t)) && not(estaTenTT(tt,t))){
        tt.push_back(t);
        evolucionarToroideUnTick(t);


    }

    return (not(EstoroideMuerto(t))) && estaTenTT(tt,t);
}
*/
bool cumpleEvoCiclicaCorrida(toroide t){
    vector<toroide> tt;
    toroide g;
    g = t;
    tt.push_back(g);
    evolucionarToroideUnTick(g);
    while(not(EstoroideMuerto(g)) && not(estaTenTT(tt,g))){
        tt.push_back(g);
        evolucionarToroideUnTick(g);


    }

    return (not(EstoroideMuerto(g))) && estaTenTT(tt,g);
}




bool EncontrarElSegundo_en_EvosDelPrimero(toroide t, toroide g){
    vector<toroide> tt;
    int cheq = 0;
    if(cumpleEvoCiclicaCorrida(t)) {
        tt = EvolucionesDeTCiclicos(t);

        for (int p = 0; (p < tt.size()) && (tt[p] != g); p++) {
            cheq++;
        }
    }
    else{
        tt = EvolucionesDeTNoCiclico(t);
        for (int p = 0; (p < tt.size()) && (tt[p] != g); p++) {
            cheq++;
        }

    }
    return (cheq < tt.size());
}

bool sonPrimosLejanos(toroide t, toroide u){
return EncontrarElSegundo_en_EvosDelPrimero(t, u);
}

//EJ 11************************************************************//







//EJ 12************************************************************//

//si t y u tienen las mismas dimensiones entonces Tiene Sentido


toroide interseccionarVivas(toroide t, toroide u) {
    toroide Interseccionado;
    vector<bool> secTemp;
    for(int ft = 0; ft < t.size(); ft++){
        for(int ct = 0; ct < (t[0]).size(); ct++){
            if(Estaviva(ft,ct,t) && Estaviva(ft,ct,u)){
                 secTemp.push_back(true);
            }
            else{
                secTemp.push_back(false);
            }
        }
        Interseccionado.push_back(secTemp);
        secTemp.clear();

    }

    return Interseccionado;

}


//EJ 13************************************************************//

//EJ 14************************************************************//


