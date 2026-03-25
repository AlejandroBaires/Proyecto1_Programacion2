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
    unique_ptr<Producto> producto;
    public:
    ProductoDecorador(unique_ptr<Producto> producto=nullptr);
    virtual ~ProductoDecorador(){};

};


#endif //PROYECTO1_PRODUCTODECORADOR_H