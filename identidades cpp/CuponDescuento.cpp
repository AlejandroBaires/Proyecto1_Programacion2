//
// Created by aleja on 2/4/2026.
//
#include"../identidades h/CuponDescuento.h"

CuponDescuento::CuponDescuento(double montoCupon):montoCupon(montoCupon) {
}

double CuponDescuento::calcularTotal(double subTotal) {
    double total = subTotal-this->montoCupon;
    return (total<0) ? 0 : total;
}

string CuponDescuento::obtenerDescripcion() {
    return "Cupón de descuento de " + to_string(montoCupon);
}
