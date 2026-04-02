//PRODUCTO
#include "identidades h/Postre.h"
#include "identidades h/Comida.h"
#include "identidades h/Bebida.h"
//PAGO
#include "identidades h/PagoTarjeta.h"
#include "identidades h/PagoEfectivo.h"
//LISTA
#include "T Lista simple/Lista.h"
//DECORADORES
#include "identidades h/IngredienteExtra.h"
#include "identidades h/CambioTammano.h"
#include "identidades h/SinIngrediente.h"
//CLIENTE
#include "identidades h/Cliente.h"
//DESCUENTO
#include "identidades h/SinDescuento.h"
#include "identidades h/PorcentajeDescuento.h"
#include "identidades h/CuponDescuento.h"
//PEDIDO
#include "identidades h/Pedido.h"


int main() {
cout << "=========================================" << endl;
    cout << "   BIENVENIDO AL SISTEMA RESTAURANTE C++  " << endl;
    cout << "=========================================\n" << endl;

    // 1. CREAR EL CLIENTE
    cout << "[1] Registrando cliente..." << endl;
    // Asumiendo que Cliente recibe Nombre e ID/Cédula
    Cliente* clienteActual = new Cliente("Alejandro",123);

    // 2. INICIAR EL PEDIDO
    cout << "[2] Abriendo nueva orden..." << endl;
    Pedido miOrden(1001, clienteActual);

    // 3. CREAR PRODUCTOS (Usando polimorfismo)
    cout << "[3] Preparando productos..." << endl;
    // Asumiendo que tienes una clase Comida y Bebida que heredan de Producto
    Producto* hamburguesa = new Comida(01,"Hamburguesa Doble", 4500.0);
    Producto* papas = new Comida(02,"Papas Fritas", 1500.0);
    Producto* refresco = new Bebida(03,"Gaseosa de Cola", 1200.0);
    papas=new CambioTammano(papas,1);


    // 4. AGREGAR PRODUCTOS AL PEDIDO
    cout << "[4] Agregando productos al pedido..." << endl;
    miOrden.agregar_producto(hamburguesa);
    miOrden.agregar_producto(papas);
    miOrden.agregar_producto(refresco);

    // 5. MOSTRAR TOTAL SIN DESCUENTO
    cout << "\n--- RESUMEN DE LA ORDEN ---" << endl;
    // El pedido nace con "SinDescuento" por defecto, así que calcula el total normal
    cout << "Subtotal a pagar: c" << miOrden.calcularTotal() << endl;

    // 6. APLICAR DESCUENTO (Patrón Strategy en acción)
    cout << "\n[!] El cliente presentó carnet de estudiante." << endl;
    cout << "Aplicando descuento del 15%..." << endl;

    Descuento* promoEstudiante = new PorcentajeDescuento(15.0);
    miOrden.aplicarDescuento(promoEstudiante); // Cambiamos la estrategia dinámicamente

    // El sistema recalcula usando la nueva fórmula automáticamente
    double totalDefinitivo = miOrden.calcularTotal();
    cout << "Nuevo Total con Descuento: c" << totalDefinitivo << endl;

    // 7. REALIZAR EL PAGO (Patrón Strategy en acción)
    cout << "\n[5] Procesando el pago..." << endl;
    MetodoPago* tarjeta = new PagoTarjeta("4500-XXXX-XXXX-9876");

    // Al cobrar, el pedido le dice a la tarjeta: "Cobra el total definitivo"
    miOrden.cobrarPedido(tarjeta);

    // 8. LIMPIEZA DE MEMORIA (¡Vital para Progra 2!)
    cout << "\n[6] Cerrando sistema y liberando memoria..." << endl;

    cout<<miOrden.toString();

    delete tarjeta;


    return 0;
}