#include <iostream>
using namespace std;

#include "videojuego.hpp"

int main() {
    VideoJuego vj;
    
    Personaje p01; 
    Personaje p02("Michel", "Zombie", 100, 50);

    p01.setNombre("Davalos");
    p01.setTipo("Guerrero");
    p01.setFuerza(100);
    p01.setSalud(99);

    vj.agregarFinal(p01);
    vj.agregarFinal(p02);

    vj.mostrar();

    return 0;
}