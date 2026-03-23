//
// Created by aleja on 23/3/2026.
//

#include "../identidades h/PagoTarjeta.h"

PagoTarjeta::PagoTarjeta(string numeroTarjeta, string nombreTarjeta):numeroTarjeta(numeroTarjeta),nombreTarjeta(nombreTarjeta) {
}

bool PagoTarjeta::procesarPago(int monto) {
    cout <<"Cobrando: "<<monto<<" a la tarjeta "<<nombreTarjeta<<endl;
    cout <<"Cobro procesado";
    return true;
}

PagoTarjeta::~PagoTarjeta() {
}
