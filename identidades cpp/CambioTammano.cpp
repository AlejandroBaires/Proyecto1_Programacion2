//
// Created by aleja on 24/3/2026.
//

#include "../identidades h/CambioTammano.h"

CambioTammano::CambioTammano(Producto* producto, string tammano) {
    this->producto = producto;
    this->tammano = tammano;
}

string CambioTammano::getDescripcion() {
    return producto->getDescripcion()+" tamano: "+tammano;
}

double CambioTammano::getPrecio() {
    if (tammano=="grande"||tammano=="Grande") {
        return producto->getPrecio()/0.50;
    }else if (tammano=="pequeno"||tammano=="Pequeno") {
        return producto->getPrecio()*0.50;
    }

}

bool CambioTammano::igual(Producto &otro) {
    return otro.getCodigo()==otro.getCodigo();
}
