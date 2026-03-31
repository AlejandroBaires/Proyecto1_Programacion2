//
// Created by aleja on 28/3/2026.
//

#ifndef PROYECTO1_PEDIDO_H
#define PROYECTO1_PEDIDO_H

#include "Cliente.h"
#include "Producto.h"
#include "MetodoPago.h"
#include "../T Lista simple/Lista.h"

class Pedido {
private:
    int numPedido;
    Cliente* cliente;
    Lista<Producto> listaProductos;
    string estado;
public:
    Pedido(int numPedido=0, Cliente* cliente=nullptr);

    int get_num_pedido() const;

    void set_num_pedido(int num_pedido);

    Cliente * get_cliente() const;

    void set_cliente(Cliente *cliente);

    string get_estado() const;

    void set_estado(const string &estado);

    bool operator==(const Pedido &pedido) const;

    //METODOS PARTICULARES

    void agregar_producto(Producto* p);

    double calcularTotal();//FALTA METODO EN LISTA

    void  cobrarPedido(MetodoPago* metodo);//SE NECESITA CALCULAR TOTAL

    string toString();

    ~Pedido();
};

#endif