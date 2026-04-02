//
// Created by aleja on 2/4/2026.
//

#ifndef PROYECTO1_SINDESCUENTO_H
#define PROYECTO1_SINDESCUENTO_H



#include "Descuento.h"

class SinDescuento : public Descuento {
public:
    double calcularTotal(double subTotal) override;
    string obtenerDescripcion()override;
    virtual ~SinDescuento(){};

};

#endif //PROYECTO1_SINDESCUENTO_H