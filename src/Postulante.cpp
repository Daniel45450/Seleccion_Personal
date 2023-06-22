#include "Postulante.h"

Postulante::Postulante()
{
    //ctor
}

Postulante::~Postulante()
{
    //dtor
}

Postulante::Postulante(string nombre, string email, int edad, vector<string>& tecnologias)
{
        this->nombre = nombre;
        this->edad = edad;
        this->email = email;
        this->tecnologias = tecnologias;
}

string Postulante::obtener_nombre() const
{
    return this->nombre;
}

int Postulante::obtener_edad() const
{
    return this->edad;
}

void Postulante::obtener_tecnologias(vector<string>& tecnologias) const
{
    tecnologias = this->tecnologias;
}

void Postulante::modificar_nombre(string nombre)
{
    this->nombre = nombre;
}

void Postulante::modificar_edad(int edad)
{
    this->edad = edad;
}

void Postulante::modificar_tecnologias(vector<string>& tecnologias)
{
    this->tecnologias = tecnologias;
}
string Postulante::obtener_email() const
{
    return this->email;
}

void Postulante::modificar_email(string email)
{
    this->email = email;
}

bool Postulante::operator<(const Postulante& p) const
{
    return (this->tecnologias.size() < p.obtener_cant_tecnologias());
}

bool Postulante::operator>(const Postulante& p) const
{
    return (this->tecnologias.size() > p.obtener_cant_tecnologias());
}

int Postulante::obtener_cant_tecnologias() const
{
    return this->tecnologias.size();
}


Postulante & Postulante::operator=(const Postulante& p)
{
    this->edad = p.obtener_edad();
    this->email = p.obtener_email();
    this->nombre = p.obtener_nombre();
    p.obtener_tecnologias(this->tecnologias);

    return *this;
}

bool Postulante::conoce_tecnologia(string lenguaje)
{
    vector<string>::const_iterator it = this->tecnologias.begin();
    while(it != tecnologias.end()) {
        if(*it == lenguaje){
            return true;
        }
        it++;
    }
    return false;
}




