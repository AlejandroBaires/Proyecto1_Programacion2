//
// Created by aleja on 4/4/2026.
//




#ifndef PROYECTO1_MENÚ_H
#define PROYECTO1_MENÚ_H
#include <limits>
#include "Descuento.h"
#include "SinDescuento.h"
#include "PorcentajeDescuento.h"
#include "CuponDescuento.h"
#include "Producto.h"
#include "Comida.h"
#include "Bebida.h"
#include "Postre.h"
#include "IngredienteExtra.h"
#include "SinIngrediente.h"
#include "CambioTammano.h"
#include "Cliente.h"
#include "Pedido.h"
#include "MetodoPago.h"
#include "PagoEfectivo.h"
#include "PagoTarjeta.h"
#include "PagoEspecial.h"
#include "GestorArchivos.h"
#include "../T Lista simple/Lista.h"
#include <exception>
#include "ArchivoNoEncontradoException.h"

class Menu {
public:
    static void menuPrincipal();
    static void menuProductos(Lista<Producto>& catalogo);
    static void menuClientes(Lista<Cliente>& clientes);
    static void menuPedidos(Lista<Producto>& catalogo,Lista<Cliente>& clientes,Lista<Pedido>& pedidos);
    static void menuArchivos(Lista<Pedido>& pedidos,Lista<Producto>& catalogo);

    //Búsqueda
    static Producto* buscarProducto(Lista<Producto>& catalogo, int codigo);
    static Cliente* buscarCliente(Lista<Cliente>& clientes, int id);

    //Decorator
    static Producto* personalizarProducto(Producto* base);

    //LIMPIEZA DE ENTRADAS
    static void limpiarBuffer();
    static int leerInt();
    static double leerDouble();
    static string leerString();
    static void limpiarPantalla();
    static void pausar();

    //Datos quemados
    static void cargarDatosQuemados(Lista<Producto>& catalogo);
};


#endif //PROYECTO1_MENÚ_H