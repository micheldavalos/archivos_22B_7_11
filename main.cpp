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

    // cin >> p01;
    // cout << p01 << endl << p02;

    // vj.agregarFinal(p01);
    // vj.agregarFinal(p02);

    // vj << p01 << p02;

    // vj.mostrar();
    // vj.respaldar_tabla();
    vj.recuperar_csv();
    vj.mostrar();
    // p01 + 100;

    // cout << p01-- << endl;

    return 0;
}