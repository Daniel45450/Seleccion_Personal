#ifndef POSTULANTE_H
#define POSTULANTE_H

#include <string>
#include <vector>

using namespace std;

class Postulante
{
    public:
        Postulante();
        Postulante(string nombre, string email, int edad, vector<string> & tecnologias);

        string obtener_nombre() const;
        string obtener_email() const;
        int obtener_edad() const;
        void obtener_tecnologias(vector<string> & tecnologias) const;
        int obtener_cant_tecnologias() const;
        bool conoce_tecnologia(string lenguaje);

        void modificar_nombre(string nombre);
        void modificar_edad(int edad);
        void modificar_email(string email);
        void modificar_tecnologias(vector<string> & tecnologias);

        bool operator<(const Postulante & p) const;
        bool operator>(const Postulante & p) const;

        Postulante & operator = (const Postulante & p);

        virtual ~Postulante();

    protected:

    private:
        string nombre;
        string email;
        int edad;
        vector<string> tecnologias;
};

#endif // POSTULANTE_H
