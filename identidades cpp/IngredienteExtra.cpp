//
// Created by aleja on 24/3/2026.
//

#include "../identidades h/IngredienteExtra.h"

IngredienteExtra::IngredienteExtra(unique_ptr<Producto> productoDecorador, string ingrediente) {
    this->producto = move(productoDecorador);
    this->ingrediente = ingrediente;

}

string IngredienteExtra::getDescripcion() {
    return producto->getDescripcion()+ ", mas " +this->ingrediente;
}

double IngredienteExtra::getPrecio() {
    return producto->getPrecio();
}
