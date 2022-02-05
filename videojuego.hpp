#ifndef VIDEOJUEGO_HPP
#define VIDEOJUEGO_HPP

#include <iostream>
using namespace std;

#include "personaje.hpp"

class VideoJuego
{
private:
    Personaje personajes[5];
    size_t cont; // unsigned long long
public:
    VideoJuego();   
    void agregarFinal(const Personaje&);
    void mostrar();
};


#endif