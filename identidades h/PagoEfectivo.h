//
// Created by aleja on 23/3/2026.
//

#ifndef PROYECTO1_PAGOEFECTIVO_H
#define PROYECTO1_PAGOEFECTIVO_H
#include "MetodoPago.h"

class PagoEfectivo:public MetodoPago{
private:
    double monto;
    public:
    PagoEfectivo(double monto=0);
    bool procesarPago(double montoPagar)override;
     ~PagoEfectivo();

};


#endif //PROYECTO1_PAGOEFECTIVO_H