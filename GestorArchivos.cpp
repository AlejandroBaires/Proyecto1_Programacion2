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

    if (pedido->get_cliente() != nullptr) {
        obj["cliente"] = clienteAJson(pedido->get_cliente());
    }

    Json::Value productos(Json::arrayValue);
    Nodo<Producto>* aux = pedido->getPrimer_producto();
    while (aux != nullptr) {
        productos.append(productoAJson(aux->getDato()));
        aux = aux->getSiguiente();
    }
    obj["productos"] = productos;

    return obj;
}

//Deserialización. Json::Value -> Objeto

Cliente* GestorArchivos::jsonACliente(const Json::Value &obj) {
    int id = obj["id"].asInt();
    string nombre = obj["nombre"].asString();
    return new Cliente(nombre, id);
}

Producto* GestorArchivos::jsonAProducto(const Json::Value &obj) {
    int codigo = obj["codigo"].asInt();
    string descripcion = obj["descripcion"].asString();
    double precio = obj["precio"].asDouble();

    if (descripcion.find("Comida") != string::npos) {
        return new Comida(codigo, descripcion, precio);
    }
    else if (descripcion.find("Bebida") != string::npos) {
        return new Bebida(codigo, descripcion, precio);
    }
    else {
        return new Postre(codigo, descripcion, precio);
    }
}

Pedido* GestorArchivos::jsonAPedido(const Json::Value &obj) {
    int numPedido = obj["numPedido"].asInt();
    string estado = obj["estado"].asString();

    Cliente* cliente = nullptr;
    if (obj.isMember("cliente")) {
        cliente = jsonACliente(obj["cliente"]);
    }

    Pedido* pedido = new Pedido(numPedido, cliente);
    pedido->set_estado(estado);

    const Json::Value& productos = obj["productos"];
    for (int i=0; i < (int)productos.size(); i++) {
        pedido->agregar_producto(jsonAProducto(productos[i]));
    }
    return pedido;
}



bool GestorArchivos::guardarCliente(Cliente *cliente, const string &nombreArchivo) {
    if (cliente == nullptr) {
        throw runtime_error("Cliente nulo, no se puede guardar");
    }

    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo " + nombreArchivo);
    }

    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "  ";
    unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    writer->write(clienteAJson(cliente), &archivo);
    archivo.close();
    return true;
}

Cliente * GestorArchivos::cargarCliente(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("Archivo de cliente no encontrado");
    }

    Json::Value obj;
    Json::Reader reader;

    if (!reader.parse(archivo, obj)) {
        throw runtime_error("Error al parsear el archivo: " + nombreArchivo);
    }

    return jsonACliente(obj);
}


bool GestorArchivos::guardarProducto(Producto *producto, const string &nombreArchivo) {
    if (producto == nullptr) {
        throw runtime_error("Producto nulo, no se puede guardar");
    }

    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + nombreArchivo);
    }

    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "  ";
    unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    writer->write(productoAJson(producto), &archivo);
    archivo.close();
    return true;
}

Producto * GestorArchivos::cargarProducto(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("Archivo de Productos no encontrado");
    }

    Json::Value obj;
    Json::Reader reader;

    if (!reader.parse(archivo, obj)) {
        throw runtime_error("Error al parsear el archivo: " + nombreArchivo);
    }

    return jsonAProducto(obj);
}


bool GestorArchivos::guardarPedido(Pedido *pedido, const string &nombreArchivo) {
    if (pedido==nullptr) {
        throw runtime_error("Pedido nulo, no se puede guardar");
    }

    ofstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("No se pudo abrir el archivo: " + nombreArchivo);
    }

    Json::StreamWriterBuilder builder;
    builder["commentStyle"] = "None";
    builder["indentation"] = "  ";
    unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    writer->write(pedidoAJson(pedido), &archivo);
    archivo.close();
    return true;
}

Pedido * GestorArchivos::cargarPedido(const string &nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        throw runtime_error("Archivo de Pedidos no encontrado");
    }

    Json::Value obj;
    Json::Reader reader;

    if (!reader.parse(archivo, obj)) {
        throw runtime_error("Error al parsear el archivo: " + nombreArchivo);
    }

    return jsonAPedido(obj);
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
