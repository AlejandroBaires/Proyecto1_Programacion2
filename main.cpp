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
//PEDIDO
#include "identidades h/Pedido.h"
int main() {

    cout << "========== PRUEBA PRODUCTOS ==========\n";

    // Crear lista (IMPORTANTE: Lista<Producto>)
    Lista<Producto> lista;

    // Productos base
    Producto* p1 = new Comida(1, "Hamburguesa", 5.0);
    Producto* p2 = new Bebida(2, "Coca Cola", 2.0, 1);
    Producto* p3 = new Postre(3, "Helado", 3.0);

    lista.insertarFinal(p1);
    lista.insertarFinal(p2);
    lista.insertarFinal(p3);

    cout << "\n--- Lista inicial ---\n";
    lista.mostrarDatos();


    cout << "\n========== PRUEBA DECORADORES ==========\n";

    // Crear producto decorado
    Producto* prod=new Comida(4, "Hamburguesa Especial", 6.0);

    prod = new IngredienteExtra(prod,"Queso");
    prod = new CambioTammano(prod,"Grande");
    prod = new SinIngrediente(prod, "Cebolla");

    cout << "Producto decorado:\n";
    cout << prod->getDescripcion() << endl;
    cout << "Precio: $" << prod->getPrecio() << endl;

    // Insertar en lista (IMPORTANTE)
    lista.insertarFinal(prod);


    cout << "\n--- Lista con decorador ---\n";
    lista.mostrarDatos();


    cout << "\n========== PRUEBA BUSQUEDA ==========\n";

    Producto* buscar = new Comida(1, "Hamburguesa", 5.0);

    Producto* encontrado = lista.BuscarDato(buscar);

    if (encontrado != nullptr) {
        cout << "Encontrado: " << *encontrado << endl;
    } else {
        cout << "No encontrado\n";
    }

    delete buscar; // ⚠️ importante


    cout << "\n========== PRUEBA ELIMINAR ==========\n";

    Producto* eliminar = new Bebida(2, "Coca Cola", 2.0, 1);

    if (lista.eliminarDato(eliminar)) {
        cout << "Producto eliminado correctamente\n";
    } else {
        cout << "No se pudo eliminar\n";
    }

    delete eliminar; // ⚠️ importante

    cout << "\n--- Lista final ---\n";
    lista.mostrarDatos();


    cout << "\n========== FIN ==========\n"<<endl;


    cout<<"============ PRUEBA PEDIDO ============"<<endl;

    Cliente* c = new Cliente("Juan", 1);

    Pedido pedido(1001, c);

    // Productos
    pedido.agregar_producto(new Comida(1, "Hamburguesa", 5));

    // Decorador
    Producto* p = new Comida(2, "Pizza", 8);
    p = new IngredienteExtra(p, " + Queso");

    pedido.agregar_producto(p);

    // Mostrar
    cout<<pedido.toString();

    // Pago
    MetodoPago* pago = new PagoEfectivo(20.0);
    pedido.cobrarPedido(pago);


    return 0;
}