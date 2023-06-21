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


