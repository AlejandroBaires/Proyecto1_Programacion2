//
// Created by aleja on 23/3/2026.
//

#ifndef PROYECTO1_POSTRE_H
#define PROYECTO1_POSTRE_H
#include "Producto.h"

class Postre:public Producto {
    private:
    string nombre;
    double precioBase;
    public:
    Postre(string nombre=0, double precioBase=0.f);
    string getDescripcion() override;
    double getPrecio() override;
    virtual ~Postre();
};


#endif //PROYECTO1_POSTRE_H