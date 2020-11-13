//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);

//Ej 1
bool esToroide(vector<vector<bool>> t);
int cant_columnas(vector<vector<bool>> t);
bool misma_longitud_secuencias(vector<vector<bool>> r);
bool esRectangulo(vector<vector<bool>> r);
//

//Ej 2
bool enRangoToroide(int f, int c, vector<vector<bool>> t);
bool EstoroideMuerto(toroide const &t);
//

//Ej 3
int cantidadDeVivas(vector<vector<bool>> t);
//

//Ej 4
int superficieTotal(toroide t);
//


//Ej 5
bool Estaviva(int f, int c, toroide t);
bool vivaToroide(int f, int c, toroide t);
bool vecinaViva(toroide t, int f, int c, int i, int j);
int vecinosVivos(toroide t, int f, int c);

//Ej 6
bool debeVivir(toroide t, int f, int c);
bool EstaMuerta(int f, int c, toroide t);
//

//Ej 7
void evolucionarToroideUnTick(toroide &t);
//

//Ej 8
toroide evolucionartoroideKVecesT(toroide t, int k);
//

//Ej 9
bool cumpleEvolucionCiclica(toroide t);
int TickDondeSeRepiteT(toroide t);
//

//Ej 10
int TickDondeSeRepiteTdeLaEvolucion(toroide t);
bool estaTenTT(vector<toroide> tt, toroide t);
int TickDondeMuere(toroide t);
vector<toroide> EvolucionesDeTCiclicos(toroide t);
vector<toroide> EvolucionesDeTNoCiclico(toroide t);
bool sonPrimosLejanos(toroide t, toroide u);
bool EncontrarElSegundo_en_EvosDelPrimero(toroide t, toroide g);
bool cumpleEvoCiclicaCorrida(toroide t);

//
//Ej 11
int ElIndiceDelQueDuraMas(vector<toroide> ts);
//
//Ej 12
toroide interseccionarVivas(toroide t, toroide u);
//
//Ej13
bool esTrasladada(toroide t, toroide u);
//
//Ej14
vector<pair<int, int>> ColectorDePosicionesVivas(toroide t);
int FilaMinima(vector<pair<int,int>> Posvivas);
int FilaMaxima(vector<pair<int,int>> Posvivas);
int ColumnaMinima(vector<pair<int,int>> Posvivas);
int ColumnaMaxima(vector<pair<int,int>> Posvivas);
int AreaMinimaVivas(toroide t);
int BuscarElAreaMasMinimaViva(toroide t);
//
#endif //REUNIONESREMOTAS_AUXILIARES_H
