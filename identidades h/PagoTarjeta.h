//
// Created by aleja on 23/3/2026.
//

#ifndef PROYECTO1_PAGOTARJETA_H
#define PROYECTO1_PAGOTARJETA_H
#include "MetodoPago.h"

class PagoTarjeta:public MetodoPago {
    string numeroTarjeta;
    string nombreTarjeta;
    public:
    PagoTarjeta(string numeroTarjeta="", string nombreTarjeta="");
    bool procesarPago(int monto) override;
     ~PagoTarjeta();
};


#endif //PROYECTO1_PAGOTARJETA_H