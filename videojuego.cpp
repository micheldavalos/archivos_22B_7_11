#include "videojuego.hpp"
#include <iomanip>
#include <fstream>

VideoJuego::VideoJuego(size_t tam):tam(tam)
{
    cont = 0;
    personajes = new Personaje[tam];
}

VideoJuego::VideoJuego(const VideoJuego& v)
{
    personajes = new Personaje[v.tam];
    for (size_t i = 0; i < v.cont; i++)
    {
        personajes[i] = v.personajes[i];
    }
    cont = v.cont;
    tam = v.tam;    
}

VideoJuego::~VideoJuego()
{
    delete[] personajes;
}

VideoJuego& VideoJuego::operator=(const VideoJuego& v)
{
    delete[] personajes;

    personajes = new Personaje[v.tam];
    for (size_t i = 0; i < v.cont; i++)
    {
        personajes[i] = v.personajes[i];
    }
    cont = v.cont;
    tam = v.tam; 

    return *this;
}

void VideoJuego::agregarFinal(const Personaje& p)
{
    if (cont == tam) {
        cout << "El arreglo esta lleno" << endl;
        return;
    }

    personajes[cont] = p;
    cont++;
}

void VideoJuego::mostrar()
{   
    cout << left;
    cout << setw(10) << "Nombre" 
         << setw(9) << "Tipo" 
         << setw(7) << "Fuerza"
         << setw(4) << "Salud"
         << endl;
    for (size_t i = 0; i < cont; i++) {
        Personaje& p = personajes[i];
        cout << setw(10) << p.getNombre() 
             << setw(9) << p.getTipo() 
             << setw(7) << p.getFuerza()
             << setw(4) << p.getSalud();
             
        // cout << "Personaje " << i << endl;
        // cout << p;
        // cout << "Nombre: " << p.getNombre() << endl;
        // cout << "Tipo: " << p.getTipo() << endl;
        // cout << "Fuerza: " << p.getFuerza() << endl;
        // cout << "Salud: " << p.getSalud() << endl;
        cout << endl;
    }
}

void VideoJuego::respaldar_tabla()
{   
    ofstream archivo("personajes.txt");

    if (archivo.fail()) {
        return;
    }

    archivo << left;
    archivo << setw(10) << "Nombre" 
         << setw(9) << "Tipo" 
         << setw(7) << "Fuerza"
         << setw(4) << "Salud"
         << endl;
    for (size_t i = 0; i < cont; i++) {
        Personaje& p = personajes[i];
        archivo << setw(10) << p.getNombre() 
             << setw(9) << p.getTipo() 
             << setw(7) << p.getFuerza()
             << setw(4) << p.getSalud();
             
        archivo << endl;
    }
    archivo.close();
}

void VideoJuego::respaldar_csv()
{
    ofstream archivo("personajes.csv");

    if (archivo.fail()) {
        return;
    }

    for (size_t i = 0; i < cont; i++) {
        Personaje& p = personajes[i];

        archivo << p.getNombre() << ",";
        archivo << p.getTipo() << ",";
        archivo << p.getFuerza() << ",";
        archivo << p.getSalud() << endl;
        // nombre,tipo,fuerza,salud\n
    }

    archivo.close();
}

void VideoJuego::recuperar_csv()
{
    ifstream archivo("personajes.csv");

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }

    string nombre, tipo, fuerza, salud;
    float f, s;

    while (true) {
        getline(archivo, nombre, ',');
        if (archivo.fail()) break;
        getline(archivo, tipo, ',');
        getline(archivo, fuerza, ',');
        getline(archivo, salud);

        f = stof(fuerza);
        s = stof(salud);

        Personaje p(nombre, tipo, f, s);
        agregarFinal(p);    
    }

}