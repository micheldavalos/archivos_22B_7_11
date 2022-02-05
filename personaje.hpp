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
};


#endif