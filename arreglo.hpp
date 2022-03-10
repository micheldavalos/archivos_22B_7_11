#ifndef ARREGLO_H
#define ARREGLO_H

using namespace std;

template <class T>
class Arreglo
{
private:
    T* arreglo;
    size_t cont{0};
    size_t tam;

public:
    Arreglo(size_t s);
    ~Arreglo();
    Arreglo(const Arreglo& a);
    Arreglo(initializer_list<T> e);

    void push_back(const T& v) {
        if (full()) throw out_of_range("Arreglo is full");

        arreglo[cont] = v;
        cont++;
    }
    void push_front(const T& v) {
        if (full()) throw out_of_range("Arreglo is full");

        for (size_t i = cont; i > 0; i--)
        {
            arreglo[i] = arreglo[i-1];
        }
        
        arreglo[0] = v;
        cont++;
    }
    void insert(const T& v, size_t p);

    size_t size() { return cont; }
    size_t size() const { return cont; }
    
    size_t max_size() { return tam; }
    size_t max_size() const { return tam; }

    T& at(size_t p);
    bool empty() { return cont == 0; }
    bool full() { return cont == tam; }
    T& front();
    T& back();
    T* data();
    T* find(const T& v);
    void sort(bool ascending = true) {
        for (size_t i = 0; i < size()-1; i++)
        {
            for (size_t j = i+1; j < size(); j++)
            {
                if (ascending) {
                    if (arreglo[i] > arreglo[j]) {
                    swap(arreglo[i], arreglo[j]);
                    }                
                }else {
                    if (arreglo[i] < arreglo[j]) {
                    swap(arreglo[i], arreglo[j]);
                    } 
                }
            }
        }
    }
    void swap(T& v1, T& v2);

    void fill(const T& v);

    Arreglo& operator=(const Arreglo& a) {
        delete[] arreglo;
        arreglo = new T[a.tam];
        for (size_t i = 0; i < a.cont; i++)
        {
            arreglo[i] = a.arreglo[i];
        }
        cont = a.cont;
        tam = a.tam;   

        return *this;
    }

    T& operator[](size_t p) { return *(arreglo+p);}
};

template <class T>
Arreglo<T>::Arreglo(size_t s)
{
    arreglo = new T[s];
    tam = s;
}

template <class T>
Arreglo<T>::~Arreglo()
{
    delete[] arreglo;
}

template <class T>
Arreglo<T>::Arreglo(const Arreglo& a)
{
    arreglo = new T[a.tam];
    cont = a.cont;
    for (size_t i = 0; i < cont; i++)
    {
        arreglo[i] = a.arreglo[i];
    }
    tam = a.tam;    
}

template <class T>
Arreglo<T>::Arreglo(initializer_list<T> e)
{
    tam = e.size();
    arreglo = new T[tam];

    // size_t n = e.size() > s ? tam : e.size();
    
    auto it = e.begin();
    for (size_t i = 0; i < tam; i++)
    {
        arreglo[i] = *it;
        it++;
        cont++;
    } 

}

template <class T>
T& Arreglo<T>::at(size_t p)
{
    return p < cont ? *(arreglo+p) : throw out_of_range("Posicion fuera de rango");
}

template <class T>
T& Arreglo<T>::front()
{
    return *(arreglo);
}

template <class T>
T& Arreglo<T>::back()
{
    return *(arreglo+cont-1);
}

template <class T>
T* Arreglo<T>::data()
{
    return arreglo;
}

template <class T>
void Arreglo<T>::fill(const T& v)
{
    for (size_t i = 0; i < tam; i++)
    {
        arreglo[i] = v;
        cont++;
    }    
}

template<typename T>
T* Arreglo<T>::find(const T& v)
{
    for (size_t i = 0; i < size(); i++)
    {
        if (arreglo[i] == v) {
            return &arreglo[i];
        }
    }

    return nullptr;    
}


template<typename T>
void Arreglo<T>::swap(T& v1, T& v2)
{
    T temp = v1;
    v1 = v2;
    v2 = temp;
}

// template<typename T>
// void Arreglo<T>::push_back(const T& v)
// {
//     if (full()) throw out_of_range("Arreglo is full");

//     arreglo[cont] = v;
//     cont++;
// }

// template<typename T>
// void Arreglo<T>::push_back(const T& v)
// {
//     if (full()) throw out_of_range("Arreglo is full");

//     for (size_t i = cont; i > 0; i--)
//     {
//         arreglo[i] = arreglo[i-1];
//     }
    
//     arreglo[0] = v;
//     cont++;
// }

template<typename T>
void Arreglo<T>::insert(const T& v, size_t p)
{
    if (full()) throw out_of_range("Arreglo is full");
    else if (p >= cont) throw out_of_range("Invalid position");

    for (size_t i = cont; i > p; i--)
    {
        arreglo[i] = arreglo[i-1];
    }
    
    arreglo[p] = v;
    cont++;
    
}
#endif