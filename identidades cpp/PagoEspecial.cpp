//
// Created by aleja on 23/3/2026.
//

#include "../identidades h/PagoEspecial.h"

PagoEspecial::PagoEspecial(string tipoPago):tipoPago(tipoPago) {
}

bool PagoEspecial::procesarPago(double monto) {
    cout<<"Pago por medio de "<<tipoPago<<endl;
    cout<<"Pago procesado correctamente"<<endl;
    return true;
}

PagoEspecial::~PagoEspecial() {
}
