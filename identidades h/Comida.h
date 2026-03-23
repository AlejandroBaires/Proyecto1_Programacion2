//
// Created by aleja on 23/3/2026.
//

#ifndef PROYECTO1_COMIDA_H
#define PROYECTO1_COMIDA_H
#include "Producto.h"

class Comida:public Producto {
    private:
    string nombre;
    double precioBase;
    public:
    Comida(string nombre="",double precioBase=0.f);
    string getDescripcion() override;
    double getPrecio() override;
    ~Comida();
};


#endif //PROYECTO1_COMIDA_H