#include <iostream>
#include "Funciones_archivo.h"
#include "Operadores.h"
#include "Postulante.h"

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
        cout << postulantes;
        return 0;
}
