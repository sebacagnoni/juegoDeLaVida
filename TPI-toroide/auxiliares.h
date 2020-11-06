//


#ifndef REUNIONESREMOTAS_AUXILIARES_H
#define REUNIONESREMOTAS_AUXILIARES_H

#include "definiciones.h"

using namespace std;
// definir aqui las funciones
pair<int,int> mp(int a, int b);
vector<posicion> ordenar(vector<posicion> &v);

//Ej 1
int cant_columnas(vector<vector<bool>> t);
bool misma_longitud_secuencias(vector<vector<bool>> r);
bool esRectangulo(vector<vector<bool>> r);
//

//Ej 2
bool enRangoToroide(int f, int c, vector<vector<bool>> t);
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

#endif //REUNIONESREMOTAS_AUXILIARES_H
