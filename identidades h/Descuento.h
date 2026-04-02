//
// Created by aleja on 2/4/2026.
//

#ifndef PROYECTO1_DESCUENTO_H
#define PROYECTO1_DESCUENTO_H



#include <iostream>
#include <sstream>
using namespace std;

class Descuento {
public:
    virtual ~Descuento(){};
    virtual double calcularTotal(double subTotal) = 0;
    virtual string obtenerDescripcion() = 0;

};
#endif //PROYECTO1_DESCUENTO_H