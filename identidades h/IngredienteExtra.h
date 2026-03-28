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
    IngredienteExtra(Producto* productoDecorador=nullptr,string ingrediente="");
    string getDescripcion() override;
    double getPrecio() override;
    bool igual(Producto &otro) override;
    virtual ~IngredienteExtra(){};
};


#endif //PROYECTO1_INGREDIENTEEXTRA_H