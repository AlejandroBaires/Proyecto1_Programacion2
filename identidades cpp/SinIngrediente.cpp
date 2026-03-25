//
// Created by aleja on 24/3/2026.
//

#include "../identidades h/SinIngrediente.h"

SinIngrediente::SinIngrediente(unique_ptr<Producto> productoDecorador, string ingrediente) {
    this->producto = move(productoDecorador);
    this->ingrediente = ingrediente;
}

string SinIngrediente::getDescripcion() {
    return producto->getDescripcion()+", sin "+ingrediente;
}

double SinIngrediente::getPrecio() {
    return producto->getPrecio();
}
