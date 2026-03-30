//
// Created by aleja on 24/3/2026.
//

#include "../identidades h/IngredienteExtra.h"

IngredienteExtra::IngredienteExtra(Producto* productoDecorador, string ingrediente, double precio){
    this->producto = productoDecorador;
    this->ingrediente = ingrediente;
    this->precioExtra = precio;
}

string IngredienteExtra::getDescripcion() {
    return producto->getDescripcion()+ ", mas " +this->ingrediente;
}

double IngredienteExtra::getPrecio() {
    return producto->getPrecio();
}

bool IngredienteExtra::igual(Producto &otro) {
    return this->getCodigo()==otro.getCodigo();
}
