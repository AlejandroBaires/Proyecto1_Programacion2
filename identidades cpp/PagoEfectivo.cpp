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
        int vuelto= monto-montoPagar;
        cout<<"Procesado correctamente"<<endl;
        cout<<"Vuelto total:"<<vuelto<<endl;

        int billetasMonedas[]={20000,10000,5000,2000,1000,500,100,50,25,10,5};

        int cantidad=sizeof(billetasMonedas)/sizeof(billetasMonedas[0]);

        cout<<"Desglose vuelto: "<<endl;
        for(int i=0;i<cantidad;i++) {
            int valor= billetasMonedas[i];
            if (vuelto>=valor) {
                int cantidad=vuelto/valor;
                cout<<"- "<<cantidad<<" billete(s) o moneda(s) de "<<valor<<endl;
                vuelto=vuelto%valor;
            }
        }

        return true;
    }

}

PagoEfectivo::~PagoEfectivo() {
}
