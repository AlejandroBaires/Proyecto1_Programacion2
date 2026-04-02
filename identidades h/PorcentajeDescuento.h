//
// Created by aleja on 2/4/2026.
//

#ifndef PROYECTO1_PORCENTAJEDESCUENTO_H
#define PROYECTO1_PORCENTAJEDESCUENTO_H



#include "Descuento.h"

class PorcentajeDescuento : public Descuento {
private:
    double porcentajeDescuento;
    public:
    PorcentajeDescuento(double porcentajeDescuento=0);
    double calcularTotal(double subTotal) override;
    string obtenerDescripcion() override;

};
#endif //PROYECTO1_PORCENTAJEDESCUENTO_H