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

bool esToroide(toroide t){
    return ((t.size() >= 3) && (esRectangulo(t)) && (cant_columnas(t) >= 3));
}

//EJ 2************************************************************//

bool EstoroideMuerto(toroide const &t) {
    bool resp = false;
    int cheq = 0;
    for(int f = 0;f < t.size(); f++){
        for(int c = 0; c < t[f].size(); c++){
            if(t[f][c] == false){
                cheq = cheq + 1;

            }

        }
    }
    return (cheq == (t.size())*((t[0]).size()));

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
          secEv.push_back(debeVivir(t,f,c));
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
    while( !(EstoroideMuerto(t)) && (t != tInicial)){
        evolucionarToroideUnTick(t);


    }
    return (t == tInicial) && !(EstoroideMuerto(t));

}



//Si sabemos que t NO muere tiene sentido
int TickDondeSeRepiteT(toroide t){
    int tick = 1;
    toroide g;
    g = t;
    toroide tInicial;
    tInicial = t;
    evolucionarToroideUnTick(g);

    while((g  != tInicial)){
        evolucionarToroideUnTick(g);
        tick++;

    }

    return tick;
}



//EJ 10************************************************************//

bool estaTenTT(vector<toroide> tt,toroide t){
    int cheq = 0;
    for(int p = 0; (p < tt.size()) && (tt[p] != t); p++){
        cheq++;

    }
    return cheq < tt.size();

}
//si el toroide muere tiene sentido
int TickDondeMuere(toroide t){
    toroide g;
    g = t;
    int tick = 0;
    for(tick; !(EstoroideMuerto(g)); tick++){
        evolucionarToroideUnTick(g);


    }
    return tick;

}



/************************************************************************************/



vector<toroide> EvolucionesDeTNoCiclico(toroide t){
    vector<toroide> Evoluciones;
    Evoluciones.push_back(t);
    int tickFinal;
    tickFinal = TickDondeMuere(t);
    for(int p = 1; p <= tickFinal; p++){
        evolucionarToroideUnTick(t);
        Evoluciones.push_back(t);
    }
    return Evoluciones;

}


vector<toroide> EvolucionesDeTCiclicos(toroide t){
    vector<toroide> Evoluciones;
    Evoluciones.push_back(t);
    int tickFinal = TickDondeSeRepiteT(t);
    for(int p = 1;p < tickFinal;p++){
        evolucionarToroideUnTick(t);
        Evoluciones.push_back(t);
    }
    return Evoluciones;
}






bool EncontrarElSegundo_en_EvosDelPrimero(toroide t, toroide u){
    vector<toroide> ts;
    if(cumpleEvolucionCiclica(t)) {
        ts = EvolucionesDeTCiclicos(t);
    }
    else{
        ts = EvolucionesDeTNoCiclico(t);

    }
    int cheq = 0;
//Hay alguna evolucion de t tal que sea igual a g?
    for (int p = 0; (p < ts.size()) && (ts[p] != u); p++) {
        cheq++;
    }


    return (cheq < ts.size());
}

bool sonPrimosLejanos(toroide t, toroide u){
return EncontrarElSegundo_en_EvosDelPrimero(t, u) || EncontrarElSegundo_en_EvosDelPrimero(u, t);
}

//EJ 11************************************************************//


bool esEvolucionNivelK(toroide tf, toroide ti, int k){
    bool resp = false;
    if((k >= 0) && ((evolucionartoroideKVecesT(ti, k)) == tf) ){
        resp = true;
    }
    return resp;

}

//tiene sentido si considero la Pre del Ej 11
// Todos Vivos, Todos Validos y se Extinguen en algun momento
int ElIndiceDelQueDuraMas(vector<toroide> ts){
    int DuraMas = 0;
    for(int i = 1 ; i < ts.size(); i++){
     if(TickDondeMuere(ts[DuraMas]) <= TickDondeMuere(ts[i])){
         DuraMas = i;

     }
     else{

     }
    }

return DuraMas;


}






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

void UnMovArriba(toroide &t){
    toroide MovidoArriba;
    for(int f = 1; f < t.size() ;f++){
        MovidoArriba.push_back(t[f]);

    }
    MovidoArriba.push_back(t[0]);
    t = MovidoArriba;

}

// tiene sentido si tiene la misma longitud cada secuencia
void UnMovAlaDerecha(toroide &t){
    toroide MovidoAlaDerecha;
    vector<bool> secTrasl;
    for(int f = 0; f < t.size() ;f++){
        secTrasl.push_back(t[f][(t[0]).size()-1]);
        for(int c = 0; c <((t[0]).size()-1); c++){
            secTrasl.push_back(t[f][c]);

        }
        MovidoAlaDerecha.push_back(secTrasl);
        secTrasl.clear();

    }
    t = MovidoAlaDerecha;

}

int mod(int x, int y){
    int resp = 0;
    if(x >= 0){
        resp = x % y;
    }
    else{
        resp = (x-x*y) % y;
    }
    return resp;
}

//tiene sentido si es un toroide
toroide ElTrasladadodeT(toroide t, int movf, int movc){
    toroide Trasladado;
    if((movf == 0) && (movc == 0)){
        Trasladado = t;
    }
    else{


            while(mod(movc, t[0].size()) > 0){
                UnMovAlaDerecha(t);
                movc--;
            }
            while(mod(movf, t.size()) > 0){
                UnMovArriba(t);
                movf--;
            }
            Trasladado = t;
        }





    return Trasladado;

}
//Tiene sentido si t y u son toroides y ademas tienen la misma dimension
bool esTrasladada(toroide t, toroide u){
    int contador = 0;
    for(int movf = 0 ; movf < t.size(); movf++){
        for(int movc = 0; movc < (t[0]).size() && ElTrasladadodeT(t, movf, movc) != u; movc++){
            contador++;
        }
    }

    return (contador < t.size()*(t[0]).size());


}

//EJ 14************************************************************//


bool FilaMuerta(toroide t, int filaT){
    int contador = 0;
    for(int c = 0; c < (t[filaT]).size() && t[filaT][c] != true ;c++){
        contador++;


    }

    return contador == (t[filaT]).size();
}

// filaT en Rango de t. Tiene sentido si hay una posicion viva en la fila almenos
pair <int, int> PosPrimeroDeLaFila(toroide t, int filaT){
    int h = 0;
    for(int c = 0; (c < (t[filaT]).size()) && t[filaT][c] != true ; c++){
        h = c;

    }
    return mp(filaT, h);

}

pair <int, int> PosDelUltimoVivo(toroide t) {
    int i = 0;
    int j = 0;
    for (int f = t.size() - 1; f >= 0; f--) {
        for (int c = ((t[t.size() - 1]).size() - 1); (c >= 0) && (t[f][c] != true); c--) {
         i = c;
        }

        if(t[f][i] == true){
            j = f;
            f = -1;
        }


    }

    return mp(j,i);
}



//Tiene sentido si hay almenos un vivo
pair<int,int> PosDelPrimerVivo(toroide t){
    int i = 0;
    int j = 0;
    for(int f = 0; f < t.size();f++){
        for(int c = 0; c < (t[0]).size() && t[f][c] != true; c++){
         i = c;

        }
        if(t[f][i] == true){
            j = f;
            f = t.size();

        }

    }

    return mp(j,i);

}

vector<pair<int, int>> ColectorDePosicionesVivas(toroide t){
    vector<pair<int,int>> PosVivas;
    for(int f = 0; f < t.size(); f++){
        for(int c = 0; c < (t[0]).size(); c++){
            if(t[f][c] == true){
                PosVivas.push_back(mp(f,c));
            }

        }
    }

    return PosVivas;

}

//funciona con el colector de posicionesVivas
// (fila,columna)
//Tiene Sentido si almenos existe un elemento
int FilaMinima(vector<pair<int,int>> Posvivas){
    int FMin = (Posvivas[0]).first;
    for(int i = 1; i < Posvivas.size();i++){
        if(Posvivas[i].first <= FMin){
            FMin = (Posvivas[i]).first;
        }

    }
    return FMin;

}

int FilaMaxima(vector<pair<int,int>> Posvivas){
    int FMax = (Posvivas[0]).first;
    for(int i = 1; i < Posvivas.size();i++){
        if(Posvivas[i].first >= FMax){
            FMax =(Posvivas[i]).first;
        }

    }
    return FMax;

}

int ColumnaMinima(vector<pair<int,int>> Posvivas){
    int CMin = (Posvivas[0]).second;
    for(int i = 1; i < Posvivas.size();i++){
        if(Posvivas[i].second <= CMin){
            CMin = (Posvivas[i]).second;
        }

    }
    return CMin;

}

int ColumnaMaxima(vector<pair<int,int>> Posvivas){
    int CMax = (Posvivas[0]).second;
    for(int i = 1; i < Posvivas.size();i++){
        if(Posvivas[i].second >= CMax){
            CMax = (Posvivas[i]).second;
        }

    }
    return CMax;

}


int AreaMinimaVivas(toroide t){
    vector<pair<int,int>> PosVivas;
    PosVivas = ColectorDePosicionesVivas(t);
    int sumaArea = 0;
    for(int f = FilaMinima(PosVivas) ; f <= FilaMaxima(PosVivas);f++){
        for(int c = ColumnaMinima(PosVivas); c <= ColumnaMaxima(PosVivas); c++){
            sumaArea++;

        }
    }

    return sumaArea;
}

vector <int> AreasMinimasDeCadaTrasladado(toroide t){
    vector<int> ColectorDeAreasMin;
    for(int movf = 0; movf < t.size();movf++){
        for(int movc = 0; movc < (t[0]).size(); movc++){
            ColectorDeAreasMin.push_back(AreaMinimaVivas(ElTrasladadodeT(t,movf,movc)));

        }
    }

    return ColectorDeAreasMin;


}

int BuscarElAreaMasMinimaViva(toroide t){
    int IndAreaMin = 0;
    vector<int> ColeccionDeAreas;
    ColeccionDeAreas = AreasMinimasDeCadaTrasladado(t);
    for(int i = 1; i < (ColeccionDeAreas).size();i++ ){
        if( ColeccionDeAreas[i] <= ColeccionDeAreas[IndAreaMin]){
            IndAreaMin = i;
        }


    }

    return ColeccionDeAreas[IndAreaMin];
    

}

