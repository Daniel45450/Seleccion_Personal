#ifndef SELECCIONADOR_H_INCLUDED
#define SELECCIONADOR_H_INCLUDED

void seleccion_aproximada(const vector<Postulante> & postulantes, const set<string> & tec_cubrir, list<string> & seleccion);
void backtracking_busqueda(set<string> & tec_cubrir, vector<Postulante> & postulantes, set<string>::iterator & it_t, vector<string> & s_actual, vector<string> & mejor_s);
bool asignado(const vector<string> & postulantes, const string & buscar);

bool asignado(const vector<string> & postulantes, const string & buscar)
{
    vector<string>::const_iterator it_p = postulantes.begin();
    while(it_p != postulantes.end()) {
        if(*it_p == buscar) return true;
        it_p++;
    }
    return false;
}

void backtracking_busqueda(set<string> & tec_cubrir, vector<Postulante> & postulantes, set<string>::iterator & it_t, vector<string> & s_actual, vector<string> & mejor_s)
{
    if(it_t == tec_cubrir.end()) {
        if(s_actual.size() < mejor_s.size()) {
            mejor_s = s_actual;
            return;
        }
    } else {
        vector<Postulante>::iterator it_p = postulantes.begin();
        while(it_p != postulantes.end()){
            bool agregado = false;
            if(it_p->conoce_tecnologia(*it_t)) {
                if(!asignado(s_actual, it_p->obtener_nombre())) { //si no agrege a la persona la agrego
                    s_actual.push_back(it_p->obtener_nombre());
                    agregado = true; // marco para saber que lo agrege y luego sacarlo
                }
                it_t++; // avanzo para asignar otro lenguaje
                backtracking_busqueda(tec_cubrir, postulantes, it_t, s_actual, mejor_s);
                it_t--; //vuelvo para asignar el mismo el lenguaje a otra persona
                if(agregado) {
                    s_actual.pop_back(); // si agrege elimino la ultima persona
                }
            }
            it_p++;
        }
    }
}

void seleccion_aproximada(const vector<Postulante> & postulantes, const set<string> & tec_cubrir, list<string> & seleccion)
{
    vector<Postulante> aux_postulantes = postulantes;
    set<string> aux_tec = tec_cubrir;

    vector<Postulante>::iterator it_p;

    while(aux_postulantes.size() > 0 && tec_cubrir.size() > 0)
    {
        bool agregar = false;
        it_p = aux_postulantes.begin();
        vector<string> tecnologias;
        it_p->obtener_tecnologias(tecnologias);
        vector<string>::iterator it_t = tecnologias.begin();
        while(agregar == false && it_t != tecnologias.end())
        {
            if(aux_tec.find(*it_t) != aux_tec.end()) { // si la tecnologia no esta cubierta
                while(it_t != tecnologias.end()) { // marco como asignadas las tecnologias
                    aux_tec.erase(*it_t);
                    it_t++;
                }
                agregar = true;
            }
            it_t++;
        }
        if(agregar) {
         seleccion.push_back(it_p->obtener_nombre());
        }
        aux_postulantes.erase(it_p);
    }
}

#endif // SELECCIONADOR_H_INCLUDED
