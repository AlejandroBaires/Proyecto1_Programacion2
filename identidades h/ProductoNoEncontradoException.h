//
// Created by ahara on 4/4/2026.
//

#ifndef PROYECTO1_PRODUCTONOENCONTRADOEXCEPTION_H
#define PROYECTO1_PRODUCTONOENCONTRADOEXCEPTION_H
#include <stdexcept>
using namespace std;

// Cuando se busca un producto que no existe

class ProductoNoEncontradoException : public runtime_error {
    public:
    ProductoNoEncontradoException(int codigo)
        : runtime_error("Producto con codigo: " + to_string(codigo) +
            ", No fue encontrado") {}
};

#endif //PROYECTO1_PRODUCTONOENCONTRADOEXCEPTION_H