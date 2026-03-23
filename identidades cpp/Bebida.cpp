//
// Created by aleja on 23/3/2026.
//

#include "../identidades h/Bebida.h"

Bebida::Bebida(string nombre, double precioBase,int tammano):nombre(nombre),precioBase(precioBase),tamanno(tammano) {
}

string Bebida::getDescripcion() {
    return "Postre-"+this->nombre;
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

Bebida::~Bebida() {
}

