//
// Created by aleja on 25/3/2026.
//

#include "../identidades h/Cliente.h"

Cliente::Cliente(string nombre, int id): nombre(nombre), id(id) {

}

string Cliente::get_nombre() const {
    return nombre;
}

void Cliente::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

int Cliente::get_id() const {
    return id;
}

void Cliente::set_id(int id) {
    this->id = id;
}

string Cliente::to_String() const {
    stringstream ss;
    ss<<"ID: "<<get_id()<<endl;
    ss <<"Nombre: "<<get_nombre()<<endl;
    return ss.str();
}

string Cliente::to_StringEspecial() const {
 stringstream ss;
    ss<<get_id()<<";"<<get_nombre();
    return ss.str();
}

bool Cliente::operator==(const Cliente &cliente) const {
    return (this->get_id() == cliente.get_id());
}

ostream & operator<<(ostream &os, Cliente &cliente) {
    return os<<cliente.to_String();
}
