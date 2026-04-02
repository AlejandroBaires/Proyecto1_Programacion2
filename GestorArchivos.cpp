//
// Created by ahara on 2/4/2026.
//

#include "GestorArchivos.h"

const string GestorArchivos::ARCHIVO_PRODUCTOS = "productos.txt";
const string GestorArchivos::ARCHIVO_PEDIDOS = "pedidos.txt";

string GestorArchivos::productoAString(Producto *producto) {
    stringstream ss;

    ss << producto->getCodigo() << "|"
        << producto->getDescripcion() << "|"
        << producto->getPrecio();
    return ss.str();
}

Producto * GestorArchivos::stringAProducto(const string &linea) {
    stringstream ss(linea);
    string codigoStr, descripcion, precioStr;

    getline(ss, codigoStr, '|');
    getline(ss, descripcion, '|');
    getline(ss, precioStr, '|');

    int codigo = stoi(codigoStr);
    double precio = stod(descripcion);

    if (descripcion.find("Comida") != string::npos) {
        return new Comida(codigo, descripcion, precio);
    }else if (descripcion.find("Bebida") != string::npos) {
        return new Bebida(codigo, descripcion, precio);
    } else {
        return new Postre(codigo, descripcion, precio);
    }

}

bool GestorArchivos::guardarProducto(Producto *producto) {
    if (producto == nullptr) {
        throw runtime_error("Produto nulo, se puede guardar");
    }

    ofstream salida(ARCHIVO_PRODUCTOS, ios::app);
    if (!salida.is_open()) {
        throw runtime_error("No se pudo abrir el archivo");
    }

    salida << productoAString(producto) << "\n";
    salida.close();
    return true;
}

bool GestorArchivos::guardarPedido(Pedido *pedido) {
    if (pedido == nullptr) {
        throw runtime_error("Pedido nulo, se puede guardar");
    }

    ofstream salida(ARCHIVO_PEDIDOS, ios::app);
    if (!salida.is_open()) {
        throw runtime_error("No se pudo abrir el archivo");
    }

    //cabezera: numPedido|estado|idCliente|nombreCliente
    salida << pedido->get_num_pedido() << "|"
            << pedido->get_estado() << "|";

    if (pedido->get_cliente() != nullptr) {
        salida << pedido->get_cliente()->get_id() << "|"
        << pedido->get_cliente()->get_nombre() << "|";
    }   else {
        salida << "0|SinCliente";
    }
    salida << "\n";

    //Productos del pedido
    Nodo<Producto>* aux = pedido->getPrimer_producto();
    while (aux != nullptr) {
        salida << productoAString(aux->getDato()) << "\n";
        aux = aux->getSiguiente();
    }

    salida << "---\n";
    salida.close();
    return true;
}

void GestorArchivos::cargarProductos(Lista<Producto> &listaProductos) {
    ifstream archivo(ARCHIVO_PRODUCTOS);
    if (!archivo.is_open()) {
        throw runtime_error("Archivo no encontrado");
    }

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty()) {
            listaProductos.insertarFinal(stringAProducto(linea));
        }
    }
}

void GestorArchivos::cargarPedidos(Lista<Pedido> &listaPedidos) {
    ifstream archivo(ARCHIVO_PEDIDOS);
    if (!archivo.is_open()) {
        throw runtime_error("Archivo no encontrado");
    }

    string linea;
    while (getline(archivo, linea)) {
        if (!linea.empty() || linea == "---") continue;

        //leer cabezera del pedido
        stringstream ss(linea);
        string numStr, estado, idClienteStr, nombreCliente;

        getline(ss, numStr, '|');
        getline(ss, estado, '|');
        getline(ss, idClienteStr, '|');
        getline(ss, nombreCliente, '|');

        Cliente* cliente = new Cliente(nombreCliente, stoi(idClienteStr));
        Pedido* pedido = new Pedido(stoi(nombreCliente), cliente);
        pedido->set_estado(estado);

        //leer productos hasta el separador "---"
        while (getline(archivo, linea)) {
            if (!linea.empty()) {
                pedido->agregar_producto(stringAProducto(linea));
            }
        }
        listaPedidos.insertarFinal(pedido);
    }
}
