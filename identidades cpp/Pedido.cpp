//
// Created by aleja on 28/3/2026.
//

#include "../identidades h/Pedido.h"
#include "PedidoVacioException.h"
#include "PagoInsuficienteException.h"
#include "PedidoYaPagadoException.h"

Pedido::Pedido(int numPedido, Cliente *cliente) {
    this->numPedido = numPedido;
    this->cliente = cliente;
    this->estado= "Pendiente";
    this->descuento = new SinDescuento();
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

string Pedido::get_estado() const {
    return estado;
}

void Pedido::set_estado(const string &estado) {
    this->estado = estado;
}

bool Pedido::operator==(const Pedido &pedido) const {
    return (this->get_num_pedido() == pedido.get_num_pedido());
}

Nodo<Producto> * Pedido::getPrimer_producto() {
    return listaProductos.getPrimerNodo();
}

void Pedido::agregar_producto(Producto *p) {
    listaProductos.insertarFinal(p);
}

void Pedido::aplicarDescuento(Descuento *d) {
    if (this->descuento != nullptr) {
        delete this->descuento;
    }
    this->descuento = d;
}

double Pedido::calcularTotal() {
    if (listaProductos.estaVacio()) {
        throw PedidoVacioException();
    }

    double total = 0;
    Nodo<Producto> *aux=listaProductos.getPrimerNodo();
    while(aux!=nullptr) {
        total+=aux->getDato()->getPrecio();
        aux=aux->getSiguiente();
    }

    return this->descuento->calcularTotal(total);
}

void Pedido::cobrarPedido(MetodoPago* metodo) {
    if (this->estado == "Pagado") {
        throw PedidoVacioException();
    }
    double total = calcularTotal();
    if (!metodo->procesarPago(total)) {
        throw PagoInsuficienteException(0, total);
    }
    set_estado("Pagado");
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
    if (this->descuento != nullptr) {
        delete this->descuento;
    }
}

ostream & operator<<(ostream &os, const Pedido &pedido) {
    os << "Pedido# " << pedido.get_num_pedido() << endl;

    if (pedido.get_cliente() != nullptr) {
        os << "Cliente: " << pedido.get_cliente()->get_nombre() << endl;
    }

    os << "Estado: " << pedido.get_estado() << endl;


    return os;
}