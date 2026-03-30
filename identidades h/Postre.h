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
    Postre(int codigo=0,string nombre="", double precioBase=0.f);
    string getDescripcion() override;
    double getPrecio() override;
    bool igual(Producto &otro) override;
     ~Postre();
};


#endif //PROYECTO1_POSTRE_H