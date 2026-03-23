//
// Created by aleja on 23/3/2026.
//

#ifndef PROYECTO1_PAGOEFECTIVO_H
#define PROYECTO1_PAGOEFECTIVO_H
#include "MetodoPago.h"

class PagoEfectivo:public MetodoPago{
private:
    int monto;
    public:
    PagoEfectivo(int monto=0);
    bool procesarPago(int montoPagar)override;
    virtual ~PagoEfectivo();

};


#endif //PROYECTO1_PAGOEFECTIVO_H