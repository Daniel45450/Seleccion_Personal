#include <iostream>
#include <list>
#include "Funciones_archivo.h"
#include "Operadores.h"
#include "Postulante.h"
#include "Seleccionador.h"

#include <bits/stdc++.h>

using namespace std;

int main()
{
        const string ruta = "entrada.txt";
        set<string> tec_cubrir;
        vector<Postulante> postulantes;
        int N,M;
        leer_archivo(ruta, N, M, tec_cubrir, postulantes);
        cout << "Se necesitan cubrir " << M << " lenguajes de programacion:\n" << endl;
        cout << tec_cubrir;
        cout << "Hay "<< N << " postulantes disponibles: " << endl;

        //sort(postulantes.begin(), postulantes.end(), greater<Postulante>()); // ordena de mayor a menor postulantes en funcion de la cantidad de tecnologias
        cout << postulantes;
        //list<string> seleccion;
        /*seleccion_aproximada(postulantes, tec_cubrir, seleccion);
        cout << seleccion;

        set<string>::iterator it_t = tec_cubrir.begin();
        vector<string> s_actual;
        vector<string> mejor_s;
        //backtracking_busqueda(tec_cubrir, postulantes, it_t, s_actual, mejor_s);
        */

        set<string>::iterator it_t = tec_cubrir.begin();
        vector<string> s_actual;
        vector<string> mejor_s(postulantes.size(), " ");
        backtracking_busqueda(tec_cubrir, postulantes, it_t, s_actual, mejor_s);
        cout << mejor_s;
        return 0;
}
