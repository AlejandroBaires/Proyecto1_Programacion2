//
// Created by aleja on 23/3/2026.
//

#include "Postre.h"

Postre::Postre(string nombre, double precioBase):nombre(nombre),precioBase(precioBase) {
}

string Postre::getDescripcion() {
    return "Postre-"+this->nombre;
}

double Postre::getPrecio() {
    return precioBase;
}

Postre::~Postre() {
}
