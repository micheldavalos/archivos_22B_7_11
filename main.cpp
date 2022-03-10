#include <iostream>
using namespace std;

#include "videojuego.hpp"
void capturar(Personaje& p) 
{
    string temp;
    float temp_float;

    cout << "Nombre: ";
    getline(cin, temp);
    p.setNombre(temp);
    
    cout << "Tipo: ";
    getline(cin, temp);
    p.setTipo(temp);

    cout << "Fuerza: ";
    cin >> temp_float;
    p.setFuerza(temp_float);
    
    cout << "Salud: ";
    cin >> temp_float;
    p.setSalud(temp_float);
}

int main(int argc, char* argv[]) {
    size_t tam;
    
    if (argc == 1) {
        cout << "Tamaño para los personajes: ";
        cin >> tam;
    }
    else {
        tam = stoul(argv[1]);
    }

    VideoJuego vj(tam);
    string op;

    while (true)
    {
        cout << "1) Agregar Personaje" << endl;
        cout << "2) Mostrar" << endl;
        cout << "3) Respaldar Tabla" << endl;
        cout << "4) Respaldar CSV" << endl;
        cout << "5) Recuperar CSV" << endl;
        cout << "6) Cantidad" << endl;
        cout << "7) Capacidad" << endl;
        cout << "8) Agregar Personaje al inicio" << endl;
        cout << "9) Insertar Personaje" << endl;
        cout << "10) Full" << endl;
        cout << "11) Empty" << endl;
        cout << "12) Find" << endl;
        cout << "13) Ordenar (ascendente)" << endl;
        cout << "14) Ordenar (descendente)" << endl;
        cout << "0) Salir" << endl;
        cin >> op; cin.ignore();

        if (op == "1") {
            if (!vj.lleno()) {  
                Personaje p;
                capturar(p);
                vj.agregarFinal(p);
            } else {
                cout << "El videojuego está lleno" << endl;
            }
        }
        else if (op == "2") {
            vj.mostrar();
        }
        else if (op == "3") {
            vj.respaldar_tabla();
        }
        else if (op == "4") {
            vj.respaldar_csv();
        }
        else if (op == "5") {
            vj.recuperar_csv();
        }
        else if (op == "6") {
            cout << "Cantidad: " << vj.size() << endl;
        }
        else if (op == "7") {
            cout << "Capacidad: " << vj.cap() << endl;
        }
        else if (op == "8")
        {
            if (!vj.lleno()) {  
                Personaje p;
                capturar(p);
                vj.agregarInicio(p);
            } else {
                cout << "El videojuego está lleno" << endl;
            }
        }
        else if (op == "9")
        {
            if (!vj.lleno()) {  
                Personaje p;
                capturar(p);

                size_t pos;
                cout << "Posicion: ";
                cin >> pos;
                vj.insertar(p, pos);
            } else {
                cout << "El videojuego está lleno" << endl;
            }
        }
        else if(op == "10") {
            cout << (vj.lleno() ? "Full" : "Not Full") << endl;
        }
        else if(op == "11") {
            cout << (vj.vacio() ? "Empty" : "Not Empty") << endl;
        }
        else if (op == "12") 
        {
            if (!vj.vacio())
            {
                Personaje p;
                string nombre;

                cout << "Nombre: ";
                getline(cin, nombre);

                p.setNombre(nombre);

                Personaje* r = vj.buscar(p);
                if (r)
                {
                    cout << "Personaje encontrado: " << endl;
                    cout << *r << endl;
                } else {
                    cout << "No existe el personaje con el nombre " << nombre << endl;
                }      
            } else {
                cout << "No hay personajes" << endl;
            }  
        }
        else if (op == "13")
        {
            vj.ordenar(true);
        }
        else if (op == "14")
        {
            vj.ordenar(false);
        }       
        else if (op == "0")
        {
            break;
        }        
    }

    // cout << "Cantidad de personsaje: " << vj.size() << endl;
    // cout << "Capacidad del arreglo: " << vj.cap() << endl;

    return 0;
}