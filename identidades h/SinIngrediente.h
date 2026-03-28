//
// Created by aleja on 24/3/2026.
//

#ifndef PROYECTO1_SININGREDIENTE_H
#define PROYECTO1_SININGREDIENTE_H
#include "ProductoDecorador.h"

class SinIngrediente:public ProductoDecorador {
protected:
    string ingrediente;
    public:
    SinIngrediente(Producto* productoDecorador,string ingrediente);
    string getDescripcion() override;
    double getPrecio() override;
    bool igual(Producto &otro) override;
    virtual ~SinIngrediente(){};
};


#endif //PROYECTO1_SININGREDIENTE_H