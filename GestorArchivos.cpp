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

Producto* GestorArchivos::stringAProducto(const string &linea) {

    stringstream ss(linea);
    // DIFERENCIA: Se utiliza una variable extra ('nombre') que no existe en el segundo código
    string codigoStr, nombre,descripcion, precioStr;

    getline(ss, codigoStr, '|');
    getline(ss, nombre, '|');
    getline(ss, descripcion, '|');
    getline(ss, precioStr);

    if (codigoStr.empty() || nombre.empty()||descripcion.empty() || precioStr.empty()) {
        throw runtime_error("Linea inválida: " + linea);
    }
    // DIFERENCIA: Corrección donde se intentaba hacer stod(descripcion) en lugar de stod(precioStr).
    int codigo = stoi(codigoStr);
    double precio = stod(precioStr);

    //Se valida usando el 'nombre' exacto en lugar de usar descripcion.find("...").
    // Además, se concatena el nombre y la descripción al crear los objetos.
    if (nombre == "Comida") {
        return new Comida(codigo, nombre+ "|" +descripcion, precio);
    } else if (nombre == "Bebida") {
        return new Bebida(codigo, nombre+ "|" + descripcion, precio);
    } else {
        return new Postre(codigo, nombre+ "|" +descripcion, precio);
    }
}

bool GestorArchivos::guardarProducto(Producto *producto) {

    if (producto == nullptr) {
        throw runtime_error("Producto nulo, no se puede guardar");
    }

    ofstream salida(ARCHIVO_PRODUCTOS, ios::app);

    if (!salida.is_open()) {
        throw runtime_error("No se pudo abrir archivo productos");
    }

    salida << productoAString(producto) << "\n";

    salida.close();
    return true;
}

bool GestorArchivos::guardarPedido(Pedido *pedido) {

    if (pedido == nullptr) {
        throw runtime_error("Pedido nulo");
    }

    ofstream salida(ARCHIVO_PEDIDOS,ios::app);

    if (!salida.is_open()) {
        throw runtime_error("No se pudo abrir archivo pedidos");
    }

    salida << pedido->get_num_pedido() << "|"
           << pedido->get_estado() << "|";

    if (pedido->get_cliente() != nullptr) {
        salida << pedido->get_cliente()->get_id() << "|"
               << pedido->get_cliente()->get_nombre();// DIFERENCIA: Se eliminó un carácter '|' extra al final de esta línea que el código 2 escribía por error.
    } else {
        salida << "0|SinCliente";
    }

    salida << "\n";

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
        throw runtime_error("Archivo productos no encontrado");
    }

    string linea;

    while (getline(archivo, linea)) {

        if (linea.empty()) continue;
        // DIFERENCIA: Se añade un bloque try-catch para evitar que el programa se caiga
                // si un solo producto está mal formateado
        try {
            Producto* p = stringAProducto(linea);
            listaProductos.insertarFinal(p);

        } catch (exception& e) {
            cout << "Error en producto: " << e.what() << endl;
        }
    }

    archivo.close();
}

void GestorArchivos::cargarPedidos(Lista<Pedido> &listaPedidos) {

    ifstream archivo(ARCHIVO_PEDIDOS);

    if (!archivo.is_open()) {
        throw runtime_error("Archivo pedidos no encontrado");
    }

    string linea;

    while (getline(archivo, linea)) {

        // DIFERENCIA: Corrección aquí omite líneas vacías correctamente.
        // anets decía 'if (!linea.empty() ...)', saltándose todas las líneas válidas.
        if (linea.empty() || linea == "---") continue;

        stringstream ss(linea);

        string numStr, estado, idClienteStr, nombreCliente;

        getline(ss, numStr, '|');
        getline(ss, estado, '|');
        getline(ss, idClienteStr, '|');
        getline(ss, nombreCliente);


        if (numStr.empty() || estado.empty() || idClienteStr.empty()) {
            cout << "Cabecera inválida: " << linea << endl;
            continue;
        }

        Cliente* cliente = nullptr;

        try {
            cliente = new Cliente(nombreCliente, stoi(idClienteStr));
        } catch (...) {
            cliente = new Cliente("Error", 0);
        }
        // DIFERENCIA: Corrección de bug crítico. Aquí usa stoi(numStr).
        // Antes pasaba erróneamente 'stoi(nombreCliente)' al ID del pedido.
        Pedido* pedido = new Pedido(stoi(numStr), cliente);
        pedido->set_estado(estado);


        while (getline(archivo, linea)) {

            if (linea == "---") break;

            if (linea.empty()) continue;

            try {
                Producto* p = stringAProducto(linea);
                pedido->agregar_producto(p);

            } catch (exception& e) {
                cout << "Error en producto del pedido: " << e.what() << endl;
            }
        }

        listaPedidos.insertarFinal(pedido);
    }

    archivo.close();//Antes cargarArchivos ni cargarProductos tenia el .close
}
