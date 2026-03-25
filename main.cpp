#include "identidades h/Comida.h"
#include "identidades h/Bebida.h"
#include <vector>
// El Decorator
#include "identidades h/PagoTarjeta.h"
#include "identidades h/PagoEfectivo.h"
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {
    cout << "=== PRUEBA DE METODOS (PRODUCTOS Y PAGOS) ===\n\n";

    // 1. CREACIÓN DE PRODUCTOS (Probando polimorfismo)
    // Usamos punteros de la clase base apuntando a objetos derivados
    Producto* hamburguesa = new Comida("Hamburguesa Clasica", 3500);
    Producto* papas = new Comida("Papas Fritas", 1700);

    // Agrupamos los productos en un vector (simulando lo que hara la clase Pedido despues)
    vector<Producto*> listaProductos;
    listaProductos.push_back(hamburguesa);
    listaProductos.push_back(papas);

    // 2. MOSTRAR PRODUCTOS Y CALCULAR TOTAL
    cout << "--- Detalles de los Productos ---\n";
    double total = 0.0;

    // Recorremos la lista usando los metodos virtuales
    for (Producto* p : listaProductos) {
        cout << "- " << p->getDescripcion() << " : $" << p->getPrecio() << "\n";
        total += p->getPrecio();
    }

    cout << "---------------------------------\n";
    cout << "Total calculado: $" << total << "\n\n";

    // 3. PRUEBA DE MÉTODOS DE PAGO (Patrón Strategy)
    cout << "--- Prueba Pago con Tarjeta ---\n";
    MetodoPago* pago1 = new PagoTarjeta("1234567890123456", "Juan Perez");
    pago1->procesarPago(total); // Deberia cobrar $7.50 exitosamente

    cout << "\n--- Prueba Pago con Efectivo ---\n";
    MetodoPago* pago2 = new PagoEfectivo(6000); // El cliente paga con $10.00
    pago2->procesarPago(total); // Deberia cobrar y dar $2.50 de vuelto

    cout << "\n--- Prueba Pago con Efectivo (Fondos Insuficientes) ---\n";
    MetodoPago* pago3 = new PagoEfectivo(3600); // El cliente paga con solo $5.00
    pago3->procesarPago(total); // Deberia mostrar error de fondos

    // 4. LIMPIEZA DE MEMORIA (Evitar fugas de memoria)
    // Al usar 'new', nosotros somos responsables de hacer 'delete'
    delete hamburguesa;
    delete papas;
    delete pago1;
    delete pago2;
    delete pago3;

    cout << "\n=== PRUEBA FINALIZADA ===\n";
    return 0;
    // TIP See CLion help at <a href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>. Also, you can try interactive lessons for CLion by selecting 'Help | Learn IDE Features' from the main menu.
}