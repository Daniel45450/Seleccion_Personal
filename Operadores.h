#ifndef OPERADORES_H_INCLUDED
#define OPERADORES_H_INCLUDED


ostream & operator << (ostream & salida, const set<string> & conjunto_s);
ostream & operator << (ostream & salida, const Postulante & p);
ostream & operator << (ostream & salida, const vector<string> & vector_s);
ostream & operator << (ostream & salida, const vector<Postulante> & postulantes);
ostream & operator << (ostream & salida, const list<string> & list_s);


ostream & operator << (ostream & salida, const list<string> & list_s)
{
    typename list<string>::const_iterator it = list_s.begin();
    while(it != list_s.end()) {
        salida << *it << " ";
        it++;
    }
    salida << "\n";
    return salida;
}

ostream & operator << (ostream & salida, const set<string> & conjunto_s)
{
    typename set<string>::const_iterator it = conjunto_s.begin();
    while(it != conjunto_s.end()) {
        salida << *it << " ";
        it++;
    }
    salida << "\n";
    return salida;
}


ostream & operator << (ostream & salida, const Postulante & p)
{
    vector<string> tecnologias;
    p.obtener_tecnologias(tecnologias);
    salida << "Nombre: " << p.obtener_nombre() << "\n";
    salida << "Edad: " << p.obtener_edad() << "\n";
    salida << "Email: " << p.obtener_email() << "\n";
    salida << "Tecnologias: " << endl;
    salida << tecnologias << "\n";

    return salida;
}


ostream & operator << (ostream & salida, const vector<string> & vector_s)
{
    typename vector<string>::const_iterator it = vector_s.begin();
    while(it != vector_s.end()) {
        salida << "    " << *it << "\n";
        it++;
    }
    return salida;
}

ostream & operator << (ostream & salida, const vector<Postulante> & postulantes)
{
    typename vector<Postulante>::const_iterator it = postulantes.begin();
    while(it != postulantes.end()) {
        salida << *it;
        it++;
    }
    return salida;
}

#endif // OPERADORES_H_INCLUDED
