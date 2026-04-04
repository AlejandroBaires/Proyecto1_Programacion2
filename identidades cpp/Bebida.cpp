//
// Created by aleja on 23/3/2026.
//

#include "../identidades h/Bebida.h"

Bebida::Bebida(int codigo,string nombre, double precioBase):Producto(codigo),nombre(nombre),precioBase(precioBase){
}

string Bebida::getDescripcion() {
    return "Bebida|"+this->nombre;
}

double Bebida::getPrecio() {
return precioBase;
}



bool Bebida::igual(Producto &otro) {
    Bebida* o = dynamic_cast< Bebida*>(&otro);
    if (!o) return false;

    return this->getCodigo() == o->getCodigo();
}

Producto * Bebida::clonar() {
    return new Bebida(this->codigo,this->nombre,this->precioBase);
}

Bebida::~Bebida() {
}

