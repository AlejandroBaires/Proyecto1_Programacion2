//
// Created by aleja on 23/3/2026.
//

#ifndef PROYECTO1_PAGOESPECIAL_H
#define PROYECTO1_PAGOESPECIAL_H
#include "MetodoPago.h"

class PagoEspecial:public MetodoPago{
    private:
    string tipoPago;
    public:
    PagoEspecial(string tipoPago);
    bool procesarPago(int monto);
     ~PagoEspecial();

};


#endif //PROYECTO1_PAGOESPECIAL_H