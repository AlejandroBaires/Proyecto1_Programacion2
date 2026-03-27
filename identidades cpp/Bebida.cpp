//
// Created by aleja on 23/3/2026.
//

#include "../identidades h/Bebida.h"

Bebida::Bebida(int codigo,string nombre, double precioBase,int tammano):Producto(codigo),nombre(nombre),precioBase(precioBase),tamanno(tammano) {
}

string Bebida::getDescripcion() {
    return "Bebida-"+this->nombre;
}

double Bebida::getPrecio() {
return precioBase;
}

int Bebida::getTamanno() {
    return tamanno;
}


void Bebida::setTamanno(int tamanno) {
    this->tamanno = tamanno;
}

bool Bebida::igual(Producto &otro) {
    Bebida* o = dynamic_cast< Bebida*>(&otro);
    if (!o) return false;

    return this->getCodigo() == o->getCodigo();
}

Bebida::~Bebida() {
}

