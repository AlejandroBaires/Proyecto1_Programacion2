
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
//PEDIDO
#include "identidades h/Pedido.h"
#include "GestorArchivos.h"
int main() {

    Cliente* c1 = new Cliente("Scott", 604970469);
    Cliente* c2 = new Cliente("Andre", 454561848);
    Cliente* c3 = new Cliente("Pipe", 145665148);

    Producto* prod1 = new Comida(1, "Hamburguesa", 5000.0);
    Producto* prod2 = new Bebida(2, "Coca-Cola", 1200.0, 700.0);
    Producto* prod3 = new Postre(3, "Tiramizu", 3000.0);
    Producto* prod4 = new Comida(4, "Pizza", 9000.0);
    Producto* prod5 = new Bebida(5, "Fanta Uva", 1000.0, 700.0);


    GestorArchivos gestor;
    string nombreArchivoC = "Clientes.txt";
    string nombreArchivoProd = "Productos.txt";

    gestor.guardarCliente(c1, nombreArchivoC);
    gestor.guardarCliente(c2, nombreArchivoC);
    gestor.guardarCliente(c3, nombreArchivoC);

    gestor.guardarProducto(prod1, nombreArchivoProd);
    gestor.guardarProducto(prod2, nombreArchivoProd);
    gestor.guardarProducto(prod3, nombreArchivoProd);
    gestor.guardarProducto(prod4, nombreArchivoProd);
    gestor.guardarProducto(prod5, nombreArchivoProd);

    delete c1;
    delete c2;
    delete c3;

    delete prod1;
    delete prod2;
    delete prod3;
    delete prod4;
    delete prod5;

    return 0;
}