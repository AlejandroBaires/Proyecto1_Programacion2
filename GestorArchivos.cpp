//
// Created by ahara on 31/3/2026.
//

#include "GestorArchivos.h"

//Serialización. Objeto -> Json::Value

Json::Value GestorArchivos::clienteAJson(Cliente *cliente) {
    Json::Value obj;
    obj["id"] = cliente->get_id();
    obj["nombre"] = cliente->get_nombre();
    return obj;
}

Json::Value GestorArchivos::productoAJson(Producto *producto) {
    Json::Value obj;
    obj["codigo"] = producto->getCodigo();
    obj["descripcion"] = producto->getDescripcion();
    obj["precio"] = producto->getPrecio();
    return obj;
}

Json::Value GestorArchivos::pedidoAJson(Pedido *pedido) {
    Json::Value obj;
    obj["numPedido"] = pedido->get_num_pedido();
    obj["estado"] = pedido->get_estado();

    if (pedido->get_estado() != nullptr) {

    }
}

//Deserialización. Json::Value -> Objeto

Cliente* GestorArchivos::jsonACliente(const Json::Value &obj) {

}

Producto* GestorArchivos::jsonAProducto(const Json::Value &obj) {
}

Pedido* GestorArchivos::jsonAPedido(const Json::Value &obj) {
}



bool GestorArchivos::guardarCliente(Cliente *cliente, const string &nombreArchivo) {
}

Cliente * GestorArchivos::cargarCliente(const string &nombreArchivo) {
}

bool GestorArchivos::guardarProducto(Producto *producto, const string &nombreArchivo) {
}

Producto * GestorArchivos::cargarProducto(const string &nombreArchivo) {
}

bool GestorArchivos::guardarPedido(Pedido *pedido, const string &nombreArchivo) {
}

Pedido * GestorArchivos::cargarPedido(const string &nombreArchivo) {
}

bool GestorArchivos::guardarListaClientes(Lista<Cliente> &lista, const string &nombreArchivo) {
}

bool GestorArchivos::guardarListaProductos(Lista<Producto> &lista, const string &nombreArchivo) {
}

bool GestorArchivos::guardarListaPedidos(Lista<Pedido> &lista, const string &nombreArchivo) {
}

void GestorArchivos::cargarListaClientes(const string &nombreArchivo, Lista<Cliente> &lista) {
}

void GestorArchivos::cargarListaProdcutos(const string &nombreArchivo, Lista<Producto> &lista) {
}

void GestorArchivos::cargarListaPedidos(const string &nombreArchivo, Lista<Pedido> &lista) {
}
