//
// Created by aleja on 25/3/2026.
//

#ifndef PROYECTO1_CLIENTE_H
#define PROYECTO1_CLIENTE_H
#include <iostream>
#include<sstream>
using namespace std;
class Cliente {
private:
    string nombre;
    int id;
    public:

    Cliente(string nombre="", int id=0);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    int get_id() const;

    void set_id(int id);

    string to_String() const;

    string to_StringEspecial() const;

    bool operator==(const Cliente &cliente) const;

    friend ostream& operator<<(ostream& os, Cliente &cliente);
};



#endif //PROYECTO1_CLIENTE_H