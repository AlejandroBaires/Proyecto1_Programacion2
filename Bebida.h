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
    int tamanno;
    public:
    Bebida(string nombre="", double precioBase=0.f, int tamanno=0);
    string getDescripcion() override;
    double getPrecio() override;
    int getTamanno();
    void setTamanno(int tamanno);
     ~Bebida();
};


#endif //PROYECTO1_BEBIDA_H