#ifndef PERSONAJE_HPP
#define PERSONAJE_HPP

#include <iostream>
using namespace std;

class Personaje
{
    string nombre;
    string tipo;
    float fuerza;
    float salud;
public:
    Personaje();
    Personaje(string nombre, 
            string tipo, 
            float fuerza, 
            float salud);

    // Setters
    void setNombre(const string& v);
    void setTipo(const string& v);
    void setFuerza(const float v);
    void setSalud(const float v);
    // Getters
    string getNombre();
    string getTipo();
    float getFuerza();
    float getSalud();

    // Sobrecargas
    friend ostream& operator<<(ostream& out, const Personaje& p)
    {
        out << "Nombre: " << p.nombre << endl;
        out << "Tipo: " << p.tipo << endl;
        out << "Fuerza: " << p.fuerza << endl;
        out << "Salud: " << p.salud << endl;

        return out;
    }

    friend istream& operator>>(istream& in, Personaje& p)
    {
        cout << "Nombre: ";
        in >> p.nombre;
        cout << "Tipo: ";
        in >> p.tipo;
        cout << "Fuerza: ";
        in >> p.fuerza;
        cout << "Salud: ";
        in >> p.salud;

        return in;
    }

    Personaje& operator+(size_t salud)
    {
        Personaje::salud += salud;

        return *this; 
    }
    Personaje& operator-(size_t salud)
    {
        this->salud -= salud;

        return *this;
    }
    Personaje& operator++()
    {
        this->fuerza++;

        return *this;
    }
    Personaje& operator++( int )
    {
        this->fuerza += 5;

        return *this;
    }

    Personaje& operator--()
    {
        this->fuerza--;

        return *this;
    }
    Personaje& operator--( int )
    {
        this->fuerza -= 5;

        return *this;
    }

    bool operator==(const Personaje& p)
    {
        return nombre == p.nombre;
    }

    bool operator<(const Personaje& p)
    {
        return nombre < p.nombre;
    }
    bool operator>(const Personaje& p)
    {
        return nombre > p.nombre;
    }

};


#endif