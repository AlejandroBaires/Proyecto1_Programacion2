//
// Created by aleja on 28/3/2026.
//

#include "../identidades h/Pedido.h"

Pedido::Pedido(int numPedido, Cliente *cliente) {
    this->numPedido = numPedido;
    this->cliente = cliente;
    this->estado= "Pendiente";
}

int Pedido::get_num_pedido() const {
    return numPedido;
}

void Pedido::set_num_pedido(int num_pedido) {
    numPedido = num_pedido;
}

Cliente * Pedido::get_cliente() const {
    return cliente;
}

void Pedido::set_cliente(Cliente *cliente) {
    this->cliente = cliente;
}

Lista<Producto> Pedido::get_listaProductos() const {
    return listaProductos;
}

void Pedido::set_listaProductos(const Lista<Producto> &lista) {
    this->listaProductos = lista;
}

string Pedido::get_estado() const {
    return estado;
}

void Pedido::set_estado(const string &estado) {
    this->estado = estado;
}

bool Pedido::operator==(const Pedido &pedido) const {
    return (this->get_num_pedido() == pedido.get_num_pedido());
}

void Pedido::agregar_producto(Producto *p) {
    listaProductos.insertarFinal(p);
}

double Pedido::calcularTotal() {
    if (listaProductos.estaVacio()) {
        throw runtime_error("El pedido esta vacio");
    }

    double total = 0;
    Nodo<Producto> *aux=listaProductos.getPrimerNodo();
    while(aux!=nullptr) {
        total+=aux->getDato()->getPrecio();
        aux=aux->getSiguiente();
    }
    return total;
}

void Pedido::cobrarPedido(MetodoPago* metodo) {
    double total = calcularTotal();
    if (metodo->procesarPago(total)) {
        set_estado("Pagado");
    }
    else {
        throw runtime_error("Pago Fallido: monto insuficiente");
    }
}

string Pedido::toString() {
    stringstream ss;
    ss << "Pedido# " << this->get_num_pedido() << endl;

    if (cliente != nullptr) {
        ss << "Cliente: " << this->cliente->get_nombre() << endl;
    }

    ss << "Productos:\n";

    Nodo<Producto>* aux = listaProductos.getPrimerNodo();

    while (aux != nullptr) {
        ss << "- " << *(aux->getDato()) << endl;
        aux = aux->getSiguiente();
    }

    ss << "Estado: " << this->estado << endl;

    try {
        ss << "TOTAL: " << this->calcularTotal() << endl;
    } catch (...) {
        ss << "TOTAL: No disponible\n";
    }

    return ss.str();

}

Pedido::~Pedido() {
}
