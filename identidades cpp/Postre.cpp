//
// Created by aleja on 23/3/2026.
//

#include "../identidades h/Postre.h"

Postre::Postre(int codigo,string nombre, double precioBase):Producto(codigo),nombre(nombre),precioBase(precioBase) {
}

string Postre::getDescripcion() {
    return "Postre|"+this->nombre;
}

double Postre::getPrecio() {
    return precioBase;
}

bool Postre::igual(Producto &otro) {
    Postre* o = dynamic_cast< Postre*>(&otro);
    if (!o) return false;

    return this->getCodigo() == o->getCodigo();
}

Producto * Postre::clonar() {
    return new Postre(this->codigo,this->nombre,this->precioBase);
}

Postre::~Postre() {
}
