//
// Created by ahara on 2/4/2026.
//

#ifndef PROYECTO1_GESTORARCHIVOS_H
#define PROYECTO1_GESTORARCHIVOS_H

#include <fstream>
#include <sstream>
#include <string>
#include "Producto.h"
#include "Comida.h"
#include "Bebida.h"
#include "Pedido.h"
#include "Postre.h"
#include "../T Lista simple/Lista.h"

class GestorArchivos {
private:
    static const string ARCHIVO_PRODUCTOS;
    static const string ARCHIVO_PEDIDOS;

    static string productoAString(Producto* producto);
    static Producto* stringAProducto(const string& linea);

public:
    static bool guardarProducto(Producto* producto);
    static bool guardarPedido(Pedido* pedido);

    static void cargarProductos(Lista<Producto>& listaProductos);
    static void cargarPedidos(Lista<Pedido>& listaPedidos);
};


#endif //PROYECTO1_GESTORARCHIVOS_H