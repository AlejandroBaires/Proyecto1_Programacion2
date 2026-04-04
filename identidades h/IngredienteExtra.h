//
// Created by aleja on 24/3/2026.
//

#ifndef PROYECTO1_INGREDIENTEEXTRA_H
#define PROYECTO1_INGREDIENTEEXTRA_H
#include "ProductoDecorador.h"

class IngredienteExtra:public ProductoDecorador {
protected:
    string ingrediente;
    double precioExtra;
public:
    IngredienteExtra(Producto* productoDecorador=nullptr,string ingrediente="", double precio=0.50);
    string getDescripcion() override;
    double getPrecio() override;
    bool igual(Producto &otro) override;
    Producto* clonar() override;
    virtual ~IngredienteExtra(){};
};


#endif //PROYECTO1_INGREDIENTEEXTRA_H