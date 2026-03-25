//
// Created by aleja on 24/3/2026.
//

#ifndef PROYECTO1_INGREDIENTEEXTRA_H
#define PROYECTO1_INGREDIENTEEXTRA_H
#include "ProductoDecorador.h"

class IngredienteExtra:public ProductoDecorador {
protected:
    string ingrediente;
public:
    IngredienteExtra(unique_ptr<Producto> productoDecorador=nullptr,string ingrediente="");
    string getDescripcion() override;
    double getPrecio() override;
    virtual ~IngredienteExtra(){};
};


#endif //PROYECTO1_INGREDIENTEEXTRA_H