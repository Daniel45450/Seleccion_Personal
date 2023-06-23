#include <iostream>
#include <list>
#include "Funciones_archivo.h"
#include "Operadores.h"
#include "Postulante.h"
#include "Seleccionador.h"
#include "Utilidades.h"

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
        cout << postulantes << endl;

        //Seleccion con backtracking(optima)

        set<string>::iterator it_t = tec_cubrir.begin();
        vector<string> s_actual;
        vector<string> mejor_s;
        vector_p_to_vector_s(postulantes, mejor_s);
        backtracking_busqueda(tec_cubrir, postulantes, it_t, s_actual, mejor_s);

        cout << "Seleccion optima:" << endl;
        cout << "Se reclutaron: " << mejor_s.size() << endl;
        cout << mejor_s << endl;

        //Seleccion con algoritmo de aproximacion
        list<string> seleccion;
        seleccion_aproximada(postulantes, tec_cubrir, seleccion);

        cout << "Seleccion aproximada(sin ordenar entrada):" << endl;
        cout << "Se reclutaron: " <<seleccion.size() << endl;
        cout << seleccion << endl;

        sort(postulantes.begin(), postulantes.end(), greater<Postulante>()); // ordena de mayor a menor postulantes en funcion de la cantidad de tecnologias
        list<string> seleccion2;
        seleccion_aproximada(postulantes, tec_cubrir, seleccion2);

        cout << "Seleccion aproximada(ordenada):" << endl;
        cout << "Se reclutaron: " <<seleccion2.size() << endl;
        cout << seleccion2 << endl;

        return 0;
}
