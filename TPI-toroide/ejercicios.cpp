#include <algorithm>
#include "ejercicios.h"
#include "auxiliares.h"

// EJERCICIO 1
bool toroideValido(vector<vector<bool>> const &t) {
    bool resp = false;
    resp = ((t.size() >= 3) && (esRectangulo(t)) && (cant_columnas(t) >= 3));
    return resp;
}

// EJERCICIO 2
bool toroideMuerto(toroide const &t) {

    bool resp = false;
    int f = 0;
    int c = 0;
    int chequeado = 0;
    if (toroideValido(t)) {
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
    }


    resp = (t.size() > 0) && (chequeado == (t[0].size()) * (t.size()));
    return resp;

}

// EJERCICIO 3
vector<posicion> posicionesVivas(toroide const &t) {
	vector<posicion> vivos;
    if(toroideValido(t)){
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
	if(toroideValido(t)){
	    resp = (resp + 1 + cantidadDeVivas(t)) / superficieTotal(t);
	}
	return resp ;
}

// EJERCICIO 5
int cantidadVecinosVivos(toroide const &t, int f, int c) {
    float resp = 0;
    if(toroideValido(t) && enRangoToroide(f,c,t)){
         resp = vecinosVivos(t,f,c);


           }


    return resp;
}

// EJERCICIO 6
bool evolucionDePosicion(toroide const &t, posicion x) {
	bool resp = false;
	if(toroideValido(t) && enRangoToroide(x.first,x.second, t)){
	    resp = debeVivir(t, x.first, x.second);

	}

    return resp;
}

// EJERCICIO 7
void evolucionToroide(toroide &t){
    // Implementacions
    return;
}

// EJERCICIO 8
toroide evolucionMultiple(toroide const &t, int K) {
    toroide out;
    // Implementacion
    return out;
}

// EJERCICIO 9
bool esPeriodico(toroide const &t, int &p) {
    bool resp = false;
    // Implementacion
    return resp;
}

// EJERCICIO 10
bool primosLejanos(toroide const &t, toroide const &u) {
	bool resp = false; 
    // Implementacion
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
    // Implementacion
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
