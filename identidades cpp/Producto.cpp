//
// Created by aleja on 26/3/2026.
//

#include "../identidades h/Producto.h"

Producto::Producto(int codigo):codigo(codigo) {
}

int Producto::getCodigo() {
    return this->codigo;
}


ostream & operator<<(ostream &os, Producto &otro) {
    return os<<otro.getCodigo()<<": "<<otro.getDescripcion()<<"("<<otro.getPrecio()<<")";
}
