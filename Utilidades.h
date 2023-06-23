#ifndef UTILIDADES_H_INCLUDED
#define UTILIDADES_H_INCLUDED

#include "Postulante.h"

void vector_p_to_list_p(const vector<Postulante> & postulantes, list<Postulante> & postulantes_l); // vector<Postulante> a list<Postulante>
void vector_p_to_list_s(const vector<Postulante> & postulantes, list<string> & postulantes_l); // vector<Postulante> a list<string>
void vector_p_to_vector_s(const vector<Postulante> & postulantes, vector<string> & v_s); // vector<Postulante> a vector<string>

void vector_p_to_list_p(const vector<Postulante> & postulantes, list<Postulante> & postulantes_l)
{
    vector<Postulante>::const_iterator it_p = postulantes.begin();
    while(it_p != postulantes.end()) {
        postulantes_l.push_back(*it_p);
        it_p++;
    }
}

void vector_p_to_list_s(const vector<Postulante> & postulantes, list<string> & postulantes_l)
{
    vector<Postulante>::const_iterator it_p = postulantes.begin();
    while(it_p != postulantes.end()) {
        postulantes_l.push_back(it_p->obtener_nombre());
        it_p++;
    }
}

void vector_p_to_vector_s(const vector<Postulante> & postulantes, vector<string> & v_s)
{
    vector<Postulante>::const_iterator it_p = postulantes.begin();
    while(it_p != postulantes.end()) {
        v_s.push_back(it_p->obtener_nombre());
        it_p++;
    }
}

#endif // UTILIDADES_H_INCLUDED
