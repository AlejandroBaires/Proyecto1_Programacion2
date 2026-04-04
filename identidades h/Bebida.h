//
// Created by aleja on 23/3/2026.
//

#ifndef PROYECTO1_BEBIDA_H
#define PROYECTO1_BEBIDA_H
#include "Producto.h"

class Bebida:public Producto{
private:
    string nombre;
    double precioBase;

    public:
    Bebida(int codigo=0,string nombre="", double precioBase=0.f);
    string getDescripcion() override;
    double getPrecio() override;
    bool igual(Producto &otro) override;
    Producto* clonar() override;
     ~Bebida();
};


#endif //PROYECTO1_BEBIDA_H