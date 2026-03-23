//
// Created by aleja on 23/3/2026.
//

#include "Bebida.h"

Bebida::Bebida(string nombre, double precioBase):nombre(nombre),precioBase(precioBase) {
}

string Bebida::getDescripcion() {
    return "Postre-"+this->nombre;
}

double Bebida::getPrecio() {
return precioBase;
}
