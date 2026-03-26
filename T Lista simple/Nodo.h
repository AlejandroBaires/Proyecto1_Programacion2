//
// Created by ahara on 25/3/2026.
//

#ifndef HELLO_WORLD_NODO_H
#define HELLO_WORLD_NODO_H
#include <iostream>
using namespace std;

template <class T>
class Nodo {
private:
    T* dato;
    Nodo<T>* siguiente;
public:
    //Constructor
    Nodo(T* _dato, Nodo<T>* _sig):dato(_dato), siguiente(_sig){}
    //Destructor
    ~Nodo() {
        dato = nullptr;
        siguiente = nullptr;
    }
    //get y set de datos
    T* getDato() {return dato;}
    void setDato(T* d) {dato = d;}
    //get y set del siguiente nodo
    Nodo<T>* getSiguiente() {return siguiente;}
    void setSiguiente(Nodo<T>* s) {siguiente = s;}
};

#endif //HELLO_WORLD_NODO_H