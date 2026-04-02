//
// Created by aleja on 2/4/2026.
//
#include "../identidades h/PorcentajeDescuento.h"

PorcentajeDescuento::PorcentajeDescuento(double porcentajeDescuento): porcentajeDescuento(porcentajeDescuento) {
}

double PorcentajeDescuento::calcularTotal(double subTotal) {
    return subTotal-(subTotal*(this->porcentajeDescuento/100.0));
}

string PorcentajeDescuento::obtenerDescripcion() {
    return "Descuento de "+ to_string(porcentajeDescuento)+"%";
}
