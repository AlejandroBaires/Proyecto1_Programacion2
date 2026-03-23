//
// Created by aleja on 23/3/2026.
//

#include "../identidades h/Comida.h"


Comida::Comida(string nombre, double precio): nombre(nombre), precioBase(precio) {
}

string Comida::getDescripcion() {
    return "Comida- " + this->nombre;
}

double Comida::getPrecio() {
    return precioBase;
}

Comida::~Comida() {
}
