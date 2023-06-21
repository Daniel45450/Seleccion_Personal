#ifndef SELECCIONADOR_H_INCLUDED
#define SELECCIONADOR_H_INCLUDED

void seleccion_aproximada(const vector<Postulante> & postulantes, const set<string> & tec_cubrir, list<string> & seleccion);

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
