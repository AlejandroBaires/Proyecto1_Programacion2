//
// Created by aleja on 24/3/2026.
//

#ifndef PROYECTO1_PRODUCTODECORADOR_H
#define PROYECTO1_PRODUCTODECORADOR_H
#include "Producto.h"
#include <memory>
using namespace std;

class ProductoDecorador:public Producto {
protected:
    Producto* producto;
    public:
    ProductoDecorador(Producto* producto=nullptr);
    int getCodigo() override;
    virtual ~ProductoDecorador(){};

};


#endif //PROYECTO1_PRODUCTODECORADOR_H