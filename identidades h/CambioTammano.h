//
// Created by aleja on 24/3/2026.
//

#ifndef PROYECTO1_CAMBIOTAMMANO_H
#define PROYECTO1_CAMBIOTAMMANO_H
#include "ProductoDecorador.h"

class CambioTammano:public ProductoDecorador{
    string tammano;
    public:
    CambioTammano(unique_ptr<Producto> producto,string tammano);
    string getDescripcion() override;
    double getPrecio() override;
    virtual ~CambioTammano(){};
};


#endif //PROYECTO1_CAMBIOTAMMANO_H