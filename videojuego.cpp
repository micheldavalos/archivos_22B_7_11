#include "videojuego.hpp"

VideoJuego::VideoJuego()
{
    cont = 0;
}

void VideoJuego::agregarFinal(const Personaje& p)
{
    if (cont == 5) {
        cout << "El arreglo esta lleno" << endl;
        return;
    }

    personajes[cont] = p;
    cont++;
}

void VideoJuego::mostrar()
{
    for (size_t i = 0; i < cont; i++) {
        Personaje& p = personajes[i];
        cout << "Personaje " << i << endl;
        cout << "Nombre: " << p.getNombre() << endl;
        cout << "Tipo: " << p.getTipo() << endl;
        cout << "Fuerza: " << p.getFuerza() << endl;
        cout << "Salud: " << p.getSalud() << endl;
        cout << endl;
    }
}