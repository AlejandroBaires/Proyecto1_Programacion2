//
// Created by aleja on 23/3/2026.
//

#include "PagoEspecial.h"

PagoEspecial::PagoEspecial(string tipoPago):tipoPago(tipoPago) {
}

bool PagoEspecial::procesarPago(int monto) {
    cout<<"Pago por medio de "<<tipoPago<<endl;
    cout<<"Pago procesado correctamente"<<endl;
    return true;
}

PagoEspecial::~PagoEspecial() {
}
