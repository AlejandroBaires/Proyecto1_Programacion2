//
// Created by aleja on 24/3/2026.
//

#include "../identidades h/ProductoDecorador.h"

ProductoDecorador::ProductoDecorador(unique_ptr<Producto> producto){
    this->producto = move(producto);
}

