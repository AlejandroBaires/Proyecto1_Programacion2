//
// Created by aleja on 23/3/2026.
//

#include "../identidades h/Comida.h"


Comida::Comida(int codigo,string nombre, double precio): Producto(codigo),nombre(nombre), precioBase(precio) {
}

string Comida::getDescripcion() {
    return "Comida| " + this->nombre;
}

double Comida::getPrecio() {
    return precioBase;
}

bool Comida::igual(Producto &producto) {
    Comida* o = dynamic_cast< Comida *>(&producto);
    if (!o) return false;

    return this->getCodigo() == o->getCodigo();
}

Comida::~Comida() {
}
