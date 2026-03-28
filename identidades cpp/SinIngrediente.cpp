//
// Created by aleja on 24/3/2026.
//

#include "../identidades h/SinIngrediente.h"

SinIngrediente::SinIngrediente(Producto* productoDecorador, string ingrediente) {
    this->producto = productoDecorador;
    this->ingrediente = ingrediente;
}

string SinIngrediente::getDescripcion() {
    return producto->getDescripcion()+", sin "+ingrediente;
}

double SinIngrediente::getPrecio() {
    return producto->getPrecio();
}

bool SinIngrediente::igual(Producto &otro) {
    return this->getCodigo()==otro.getCodigo();
}
