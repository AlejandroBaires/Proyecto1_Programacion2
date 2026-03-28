//
// Created by aleja on 24/3/2026.
//

#include "../identidades h/ProductoDecorador.h"

ProductoDecorador::ProductoDecorador(Producto* producto){
    this->producto = producto;
}

int ProductoDecorador::getCodigo() {
    return producto->getCodigo();
}

