//
// Created by ahara on 31/3/2026.
//

#ifndef PROYECTO1_GESTORARCHIVOS_H
#define PROYECTO1_GESTORARCHIVOS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "dist/json/json.h"
#include "Cliente.h"
#include "Producto.h"
#include "Comida.h"
#include "Bebida.h"
#include "Postre.h"
#include "MetodoPago.h"
#include "Pedido.h"
#include "T Lista simple/Lista.h"
using namespace std;

class GestorArchivos {
private:
    static Json::Value clienteAJson(Cliente* cliente);
    static Json::Value productoAJson(Producto* producto);
    static Json::Value pedidoAJson(Pedido* pedido);

    static Cliente* jsonACliente(const Json::Value& obj);
    static Producto* jsonAProducto(const Json::Value& obj);
    static Pedido* jsonAPedido(const Json::Value& obj);

public:
    //CLIENTES
    static bool guardarCliente(Cliente* cliente, const string& nombreArchivo);
    static Cliente* cargarCliente(const string& nombreArchivo);

    //PRODUCTOS
    static bool guardarProducto(Producto* producto, const string& nombreArchivo);
    static Producto* cargarProducto(const string& nombreArchivo);

    //PEDIDOS
    static bool guardarPedido(Pedido* pedido, const string& nombreArchivo);
    static Pedido* cargarPedido(const string& nombreArchivo);

    //Listas Completas
    static bool guardarListaClientes(Lista<Cliente>& lista, const string& nombreArchivo);
    static bool guardarListaProductos(Lista<Producto>& lista, const string& nombreArchivo);
    static bool guardarListaPedidos(Lista<Pedido>& lista, const string& nombreArchivo);

    static void cargarListaClientes(const string& nombreArchivo, Lista<Cliente>& lista);
    static void cargarListaProdcutos(const string& nombreArchivo, Lista<Producto>& lista);
    static void cargarListaPedidos(const string& nombreArchivo, Lista<Pedido>& lista);
};


#endif //PROYECTO1_GESTORARCHIVOS_H