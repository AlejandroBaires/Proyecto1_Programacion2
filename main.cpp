#include <iostream>
#include "IngredienteExtra.h"
#include "identidades h/GestorArchivos.h"

int main() {

    cout << "===========================" << endl;
    cout << "   PRUEBA GESTOR ARCHIVOS  " << endl;
    cout << "===========================" << endl;

    //Productos de prueba
    cout << "----- Guardando Productos -----" << endl;

    Producto* p1 = new Comida(1, "Hamburguesa", 5500);
    Producto* extp1 = new IngredienteExtra(p1, "Queso", 1000);

    Producto* p2 = new Bebida(2, "Coca-Cola", 1000);
    Producto* p3 = new Postre(3, "Helado", 700);

    try {
        GestorArchivos::guardarProducto(p1);
        cout << "Producto 1 guardado: " << p1->getDescripcion() << endl;

        GestorArchivos::guardarProducto(p2);
        cout << "Producto 2 guardado: " << p2->getDescripcion() << endl;

        GestorArchivos::guardarProducto(p3);
        cout << "Producto 3 guardado: " << p3->getDescripcion() << endl;

    } catch (runtime_error& e) {
        cout << "Error guardando productos: " << e.what() << endl;
    }

    cout << endl;

    cout << "----- Guardando Pedidos -----" << endl;

    Cliente* cliente1 = new Cliente("Scott", 1012);
    Pedido* pedido1 = new Pedido(1027, cliente1);
    pedido1->agregar_producto(extp1);
    pedido1->agregar_producto(p2);

    try {
        GestorArchivos::guardarPedido(pedido1);
        cout << "Pedido guardado: #" << pedido1->get_num_pedido() << endl;

    } catch (runtime_error& e) {
        cout << "Error guardando pedido: " << e.what() << endl;
    }

    cout << endl;

    cout << "----- Cargando Productos -----" << endl;

    Lista<Producto> listaProductos;
    try {
        GestorArchivos::cargarProductos(listaProductos);
        cout << "Productos Cargados..." << endl;
        listaProductos.mostrarDatos();

    } catch (runtime_error& e) {
        cout << "Error cargando productos: " << e.what() << endl;
    }

    cout <<  endl;

    cout << "----- Cargando Pedidos -----" << endl;

    Lista<Pedido> listaPedidos;
    try {
        GestorArchivos::cargarPedidos(listaPedidos);
        cout << "Pedidos cargados:" << endl;
        listaPedidos.mostrarDatos();

        cout<<"Pedido en especifico: "<<endl;
       Pedido* primerNodo=listaPedidos.BuscarDato(pedido1);
        cout<<primerNodo->toString();

    } catch (runtime_error& e) {
        cout << "Error cargando pedidos: " << e.what() << endl;
    }

    return 0;
}