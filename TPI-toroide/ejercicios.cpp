#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    bool resp = false;
    resp = esToroide(t);
    return resp;
}

// EJERCICIO 2
bool toroideMuerto(toroide const &t) {
    bool resp = false;
    if (toroideValido(t)) {
        resp = EstoroideMuerto(t);
    }

    return resp;

}

// EJERCICIO 3
vector<posicion> posicionesVivas(toroide const &t) {
	vector<posicion> vivos;
    if(esToroide(t)){
        for(int f = 0; f < t.size(); f++){
            for(int c = 0;c < t[0].size(); c++){
                if(t[f][c] == true){
                    vivos.push_back(mp(f,c));
                }

            }
        }
    }

    return vivos;
}

// EJERCICIO 4
float densidadPoblacion(toroide const &t) {
	float resp = -1;
	if(esToroide(t)){
	    resp = (resp + 1 + cantidadDeVivas(t)) / superficieTotal(t);
	}
	return resp ;
}

// EJERCICIO 5
int cantidadVecinosVivos(toroide const &t, int f, int c) {
    float resp = 0;
    if(esToroide(t) && enRangoToroide(f,c,t)){
         resp = vecinosVivos(t,f,c);


           }


    return resp;
}

// EJERCICIO 6
bool evolucionDePosicion(toroide const &t, posicion x) {
	bool resp = false;
	if(esToroide(t) && enRangoToroide(x.first,x.second, t)){
	    resp = debeVivir(t, x.first, x.second);

	}

    return resp;
}

// EJERCICIO 7
// CUAL SERIA LA PRE ?
//CONSULTAR RETURN?
void evolucionToroide(toroide &t){
    if(esToroide(t)){
        evolucionarToroideUnTick(t);


    }

}

// EJERCICIO 8
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out;
    if(esToroide(t) && (K >= 1)){
        out  = evolucionartoroideKVecesT(t,K);

    }
    return out;
}

// EJERCICIO 9

bool esPeriodico(toroide const &t, int &p) {
    bool resp = false;
    //CONSULTAR CUMPLEEVOLUCIONCICLICA
    if(esToroide(t) && cumpleEvolucionCiclica(t)){
        p = TickDondeSeRepiteT(t);
        resp = true;

    }


    return resp;
}

// EJERCICIO 10

bool primosLejanos(toroide const &t, toroide const  &u) {
    bool resp = false;
    if(esToroide(t) && esToroide(u) && mismaDimension(t,u)){
        resp =  sonPrimosLejanos(t,u) || sonPrimosLejanos(u,t);
    }

    return resp;
}
// EJERCICIO 11
int seleccionNatural(vector <toroide> ts) {
    int resp = -1;
	// Implementacion
    return resp;
}

// EJERCICIO 12
toroide fusionar(toroide const &t, toroide const &u) {
    toroide out;
    if(esToroide(t) && esToroide(u) && mismaDimension(t,u)){
        out = interseccionarVivas(t,u);
    }


    return out;
}

// EJERCICIO 13
bool vistaTrasladada(toroide const &t, toroide const &u){
	bool resp = false;
    // Implementacion
    return resp;
}

// EJERCICIO 14
int menorSuperficieViva(toroide const &t){
	int resp = -1;
	// Implementacion
	return resp;
}
