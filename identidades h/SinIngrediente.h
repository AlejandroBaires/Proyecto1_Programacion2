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
    SinIngrediente(unique_ptr<Producto> productoDecorador,string ingrediente);
    string getDescripcion() override;
    double getPrecio() override;
    virtual ~SinIngrediente(){};
};


#endif //PROYECTO1_SININGREDIENTE_H