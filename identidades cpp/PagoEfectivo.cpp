//
// Created by aleja on 23/3/2026.
//

#include "../identidades h/PagoEfectivo.h"

PagoEfectivo::PagoEfectivo(int monto):monto(monto) {
}

bool PagoEfectivo::procesarPago(int montoPagar) {
    if (monto < montoPagar) {
        cout<<"Monto insuficiente"<<endl;
        return false;
    }else if (monto == montoPagar) {
        cout<<"Procesado correctamente"<<endl;
        return true;
    }else if (monto > montoPagar) {
        cout<<"Vuelto: "<<monto-montoPagar<<endl;
        cout<<"Procesado correctamente"<<endl;
        return true;
    }

}

PagoEfectivo::~PagoEfectivo() {
}
