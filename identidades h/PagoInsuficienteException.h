//
// Created by ahara on 4/4/2026.
//

#ifndef PROYECTO1_PAGOINSUFICIENTEEXCEPTION_H
#define PROYECTO1_PAGOINSUFICIENTEEXCEPTION_H
#include <stdexcept>
using namespace std;

//  Cuando el monto pagado no alcanza

class PagoInsuficienteException : public runtime_error {
public:
    PagoInsuficienteException(double montoPago, double montoTotal)
        : runtime_error("Pago insuficiente. Se pago: " + to_string(montoPago)
            + " | Total requerido: " + to_string(montoTotal)) {}
};

#endif //PROYECTO1_PAGOINSUFICIENTEEXCEPTION_H