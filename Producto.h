//
// Created by aleja on 23/3/2026.
//

#ifndef PROYECTO1_PRODUCTO_H
#define PROYECTO1_PRODUCTO_H

#include <iostream>
#include <string>
using namespace std;

class Producto {
public:
    virtual ~Producto();
    virtual string getDescripcion() = 0;
    virtual double getPrecio() = 0;

};


#endif //PROYECTO1_PRODUCTO_H