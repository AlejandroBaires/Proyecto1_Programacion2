//
// Created by aleja on 2/4/2026.
//

#ifndef PROYECTO1_CUPONDESCUENTO_H
#define PROYECTO1_CUPONDESCUENTO_H



#include "Descuento.h"
class CuponDescuento : public Descuento {
private:
    double montoCupon;
    public:
    CuponDescuento(double montoCupon=0);
    double calcularTotal(double subTotal) override;
    string obtenerDescripcion() override;

};

#endif //PROYECTO1_CUPONDESCUENTO_H