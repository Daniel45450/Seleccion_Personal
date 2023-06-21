#ifndef FUNCIONES_ARCHIVO_H_INCLUDED
#define FUNCIONES_ARCHIVO_H_INCLUDED

#include <fstream>
#include <string>
#include <set>
#include <Postulante.h>
#include <vector>

using namespace std;

void leer_archivo(const string ruta, int & N , int & M, set<string> & tec_cubrir, vector<Postulante> & postulantes);

void leer_archivo(const string ruta, int & N, int & M, set<string> & tec_cubrir, vector<Postulante> & postulantes)
{
    ifstream archivo(ruta);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << ruta << endl;
    else {
        string linea;
        getline(archivo, linea);
        M = atoi(linea.c_str()); // cantidad de tecnologias a cubrir
        getline(archivo, linea);

        int inicio = 0;
        int fin = 0;
        string agregar;

       do{ //carga tareas a cubrir
            fin = linea.find(';', inicio);
            agregar = linea.substr(inicio, fin - inicio);
            tec_cubrir.insert(agregar);
            inicio = fin +1;
       } while(fin != string::npos); // cuando fin sea una posicion invalida

       getline(archivo, linea);

       N = atoi(linea.c_str()); //cantidad de postulantes

       while(getline(archivo, linea)) { // carga postulantes
            inicio =0;
            fin =0;

            //Nombre
            fin = linea.find(';', inicio);
            string nombre = linea.substr(inicio, fin-inicio);

            //Edad
            inicio = fin+1;
            fin = linea.find(';', inicio);
            int edad = atoi(linea.substr(inicio, fin - inicio).c_str());

            //email
            inicio = fin+1;
            fin = linea.find(';', inicio);
            string email = linea.substr(inicio, fin-inicio);

            //Tecnologias que trabaja
            vector<string> tecnologias;
            inicio = fin+1;
            do{ //obtengo los datos
                fin = linea.find(';', inicio);
                agregar = linea.substr(inicio, fin - inicio);
                tecnologias.push_back(agregar);
                inicio = fin +1;
            } while(fin != string::npos); // cuando fin sea una posicion invalida

            Postulante p(nombre, email, edad, tecnologias);

            postulantes.push_back(p);
       }

        archivo.close();
    }
}

#endif // FUNCIONES_ARCHIVO_H_INCLUDED
