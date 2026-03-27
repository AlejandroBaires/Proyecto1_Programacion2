//
// Created by aleja on 23/3/2026.
//

#ifndef PROYECTO1_PRODUCTO_H
#define PROYECTO1_PRODUCTO_H

#include <iostream>
#include <string>
using namespace std;

class Producto {
protected:
    int codigo;
public:
    Producto(int codigo=0);
    virtual int getCodigo();
    virtual ~Producto() = default;
    virtual string getDescripcion() = 0;
    virtual double getPrecio() = 0;
    virtual bool igual(Producto& otro)=0;
    friend ostream& operator<<(ostream& os, Producto& otro);
};

inline bool operator==( Producto& a,  Producto& b) {
    return a.igual(b);
}


#endif //PROYECTO1_PRODUCTO_H