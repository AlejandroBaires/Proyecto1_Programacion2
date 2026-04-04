//
// Created by ahara on 4/4/2026.
//

#ifndef PROYECTO1_PEDIDOYAPAGADOEXCEPTION_H
#define PROYECTO1_PEDIDOYAPAGADOEXCEPTION_H
#include <stdexcept>
using namespace std;

//  Cuando se intenta cobrar un pedido que ya fue pagado

class PedidoYaPagadoException : public runtime_error {
    public:
    PedidoYaPagadoException(int numPedido)
        : runtime_error("El pedido #" + to_string(numPedido) + ", ya fue pagado"){}
};

#endif //PROYECTO1_PEDIDOYAPAGADOEXCEPTION_H