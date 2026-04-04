//
// Created by ahara on 4/4/2026.
//

#ifndef PROYECTO1_PEDIDOVACIOEXCEPTION_H
#define PROYECTO1_PEDIDOVACIOEXCEPTION_H

#include <stdexcept>
using namespace std;

/*
 *  Cuando se intenta operar un pedido sin productos
 */
class PedidoVacioException : public runtime_error{
public:
    PedidoVacioException() : runtime_error("No se puede procesar un pedido vacio..."){};
};


#endif //PROYECTO1_PEDIDOVACIOEXCEPTION_H