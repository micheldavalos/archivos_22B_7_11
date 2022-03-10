#ifndef VIDEOJUEGO_HPP
#define VIDEOJUEGO_HPP

#include <iostream>
using namespace std;

#include "personaje.hpp"

class VideoJuego
{
private:
    Personaje* personajes;
    size_t cont; // unsigned long long
    size_t tam;
public:
    VideoJuego(size_t tam); 
    VideoJuego(const VideoJuego& v);
    ~VideoJuego();
    VideoJuego& operator=(const VideoJuego& v);

    size_t size() {return cont;}
    size_t cap() {return tam;}

    void agregarFinal(const Personaje&);
    void mostrar();
    void respaldar_tabla();
    void respaldar_csv();
    void recuperar_csv();

    // Sobrecargas
    friend VideoJuego& operator<<(VideoJuego& vj, const Personaje& p)
    {
        vj.agregarFinal(p);

        return vj;
    }
};


#endif