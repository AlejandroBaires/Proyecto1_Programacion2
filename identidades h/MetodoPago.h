//
// Created by aleja on 23/3/2026.
//

#ifndef PROYECTO1_METODOPAGO_H
#define PROYECTO1_METODOPAGO_H
#include "iostream"
#include <sstream>
using namespace std;
class MetodoPago {
public:
    virtual ~MetodoPago() {}
    virtual bool procesarPago(double monto)=0;

};


#endif //PROYECTO1_METODOPAGO_H