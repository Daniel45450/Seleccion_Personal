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
        sort(postulantes.begin(), postulantes.end(), greater<Postulante>()); // ordena de mayor a menor postulantes en funcion de la cantidad de tecnologias
        cout << postulantes;
        list<string> seleccion;
        seleccion_aproximada(postulantes, tec_cubrir, seleccion);
        cout << seleccion;
        return 0;
}
