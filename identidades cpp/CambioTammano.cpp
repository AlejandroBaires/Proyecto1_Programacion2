//
// Created by aleja on 24/3/2026.
//

#include "../identidades h/CambioTammano.h"

CambioTammano::CambioTammano(Producto* producto, int tammano) {
    this->producto = producto;
    this->tammano = tammano;
}

string CambioTammano::getDescripcion() {
    switch (this->tammano) {
        case 1: return producto->getDescripcion()+" tamano: Grande";
        case 2: return producto->getDescripcion()+" tamano: Pequeño";
        case 3: return producto->getDescripcion()+" tamano: Mediano";
    }

}

double CambioTammano::getPrecio() {
    if (tammano== 1 ) {
        return producto->getPrecio()+(producto->getPrecio()*0.25);
    }else if (tammano== 2) {
        return producto->getPrecio()-(producto->getPrecio()*0.25);
    }
    else if (tammano== 3){
        return producto->getPrecio();
    }

}

bool CambioTammano::igual(Producto &otro) {
    return this->getCodigo()==otro.getCodigo();
}
