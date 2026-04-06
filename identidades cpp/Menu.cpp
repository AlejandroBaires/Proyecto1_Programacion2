//
// Created by aleja on 4/4/2026.
//

#include "../identidades h/Menu.h"


// ================= LIMPIEZA =================

void Menu::limpiarBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int Menu::leerInt() {
    int x;
    while (!(cin >> x)) {
        cout << "Entrada invalida. Intente de nuevo: ";
        limpiarBuffer();
    }
    limpiarBuffer();
    return x;
}

double Menu::leerDouble() {
    double x;
    while (!(cin >> x)) {
        cout << "Entrada invalida. Intente de nuevo: ";
        limpiarBuffer();
    }
    limpiarBuffer();
    return x;
}

string Menu::leerString() {
    string s;
    getline(cin, s);
    return s;
}

void Menu::limpiarPantalla() {
#ifdef _WIN32
#define LIMPIAR "cls"
#else
#define LIMPIAR "clear"
#endif

}

void Menu::pausar() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// ================= DATOS QUEMADOS =================

void Menu::cargarDatosQuemados(Lista<Producto> &catalogo) {

    // ===== COMIDAS =====
    catalogo.insertarFinal(new Comida(1, "Hamburguesa", 5500));
    catalogo.insertarFinal(new Comida(2, "Pizza", 8000));
    catalogo.insertarFinal(new Comida(3, "HotDog", 3500));
    catalogo.insertarFinal(new Comida(4, "Tacos", 4500));
    catalogo.insertarFinal(new Comida(5, "Sandwich", 3000));

    // ===== BEBIDAS =====
    catalogo.insertarFinal(new Bebida(6, "CocaCola", 1200));
    catalogo.insertarFinal(new Bebida(7, "Pepsi", 1100));
    catalogo.insertarFinal(new Bebida(8, "JugoNaranja", 1500));
    catalogo.insertarFinal(new Bebida(9, "Cafe", 1000));
    catalogo.insertarFinal(new Bebida(10, "TeFrio", 1300));

    // ===== POSTRES =====
    catalogo.insertarFinal(new Postre(11, "Helado", 2000));
    catalogo.insertarFinal(new Postre(12, "Pastel", 2500));
    catalogo.insertarFinal(new Postre(13, "Brownie", 1800));
    catalogo.insertarFinal(new Postre(14, "Flan", 1700));
    catalogo.insertarFinal(new Postre(15, "Galleta", 1200));
}

// ================= BUSQUEDAS =================

Producto* Menu::buscarProducto(Lista<Producto>& catalogo, int codigo) {
    Nodo<Producto>* aux = catalogo.getPrimerNodo();
    while (aux != nullptr) {
        if (aux->getDato()->getCodigo() == codigo)
            return aux->getDato();
        aux = aux->getSiguiente();
    }
    return nullptr;
}

Cliente* Menu::buscarCliente(Lista<Cliente>& clientes, int id) {
    Nodo<Cliente>* aux = clientes.getPrimerNodo();
    while (aux != nullptr) {
        if (aux->getDato()->get_id() == id)
            return aux->getDato();
        aux = aux->getSiguiente();
    }
    return nullptr;
}

Pedido * Menu::buscarPedido(Lista<Pedido> &pedidos, int codigo) {
    Nodo<Pedido>* aux = pedidos.getPrimerNodo();
    while (aux != nullptr) {
        if (aux->getDato()->get_num_pedido()==codigo)
            return aux->getDato();
        aux = aux->getSiguiente();
    }
    return nullptr;
}


// ================= DECORATOR =================

Producto* Menu::personalizarProducto(Producto* base) {

    Producto* personalizado = base->clonar();
    int opc;

    do {
        cout << "\n--- PERSONALIZACION ---\n";
        cout << "1. Agregar ingrediente\n";
        cout << "2. Quitar ingrediente\n";
        cout << "3. Cambiar tamano\n";
        cout << "0. Terminar\n";

        opc = leerInt();

        if (opc == 1) {
            cout << "Ingrediente: ";
            string ing = leerString();

            cout << "Costo extra: ";
            double costo = leerDouble();

            personalizado = new IngredienteExtra(personalizado, ing, costo);
        }

        else if (opc == 2) {
            cout << "Ingrediente a quitar: ";
            string ing = leerString();

            personalizado = new SinIngrediente(personalizado, ing);
        }

        else if (opc == 3) {
            cout << "1=Grande 2=Pequeno 3=Mediano: ";
            int t = leerInt();

            personalizado = new CambioTammano(personalizado, t);
        }

    } while (opc != 0);

    return personalizado;
}

// ================= MENUS =================
void Menu::menuPrincipal() {

    Lista<Producto> catalogo;
    Lista<Cliente> clientes;
    Lista<Pedido> pedidos;

    int op;

    cargarDatosQuemados(catalogo);
    do {

        cout << "\n===== MENU PRINCIPAL =====\n";
        cout << "1. Menu\n2. Clientes\n3. Pedidos\n4. Archivos\n0. Salir\n";
        cout << "Opcion: ";
        op = leerInt();

        switch(op) {
            case 1: menuProductos(catalogo); break;
            case 2: menuClientes(clientes); break;
            case 3: menuPedidos(catalogo, clientes, pedidos); break;
            case 4: menuArchivos(pedidos, catalogo); break;
        }

    } while(op != 0);
}
// ================= PRODUCTOS =================

void Menu::menuProductos(Lista<Producto>& catalogo) {
    int op;

    do {
        limpiarPantalla();
        cout << "\n--- MENU PRODUCTOS ---\n";
        cout << "1. Agregar\n2. Modificar\n3. Ver\n0. Volver\n";
        cout << "Opcion: ";
        op = leerInt();

        switch (op) {
            case 1: {
                cout << "1.Comida 2.Bebida 3.Postre: ";
                int tipo = leerInt();

                cout << "Codigo: ";
                int cod = leerInt();

                // Verificación: Si buscarProducto devuelve algo diferente a nullptr, el código ya existe
                if (buscarProducto(catalogo, cod) != nullptr) {
                    cout << "\n[X] Error: Ya existe un producto registrado con el codigo " << cod << ".\n";
                    pausar();
                    break; // Salimos del case para volver al menú
                }

                cout << "Nombre: ";
                string nombre = leerString();

                cout << "Precio: ";
                double precio = leerDouble();

                if (tipo == 1) catalogo.insertarFinal(new Comida(cod, nombre, precio));
                else if (tipo == 2) catalogo.insertarFinal(new Bebida(cod, nombre, precio));
                else catalogo.insertarFinal(new Postre(cod, nombre, precio));

                cout << "\n[!] Producto agregado con exito.\n";
                pausar();
                break;
            }
            case 2: {
                cout << "Codigo: ";
                int cod = leerInt();

                Producto* p = buscarProducto(catalogo, cod);

                if (p) {
                    cout << "Nuevo nombre: ";
                    string nombre = leerString();

                    cout << "Nuevo precio: ";
                    double precio = leerDouble();

                    if (Comida* c = dynamic_cast<Comida*>(p)) {
                        *c = Comida(cod, nombre, precio);
                        cout << "\n[!] Comida modificada con exito.\n";
                    } else {
                        cout << "\n[!] Advertencia: Por ahora solo se pueden modificar comidas enteras.\n";
                    }
                } else {
                    cout << "\n[X] Error: Producto no encontrado.\n";
                }
                pausar();
                break;
            }
            case 3: {
                cout << "\n--- LISTA DE PRODUCTOS ---\n";
                catalogo.mostrarDatos();
                pausar();
                break;
            }
            case 0:
                break;
            default:
                cout << "\n[X] Opcion invalida. Intente de nuevo.\n";
                pausar();
                break;
        }

    } while(op != 0);
}

// ================= CLIENTES =================

void Menu::menuClientes(Lista<Cliente>& clientes) {
    int op;

    do {
        limpiarPantalla();
        cout << "\n--- CLIENTES ---\n";
        cout << "1. Registrar\n2. Buscar\n3. Ver\n0. Volver\n";
        cout << "Opcion: ";
        op = leerInt();

        switch (op) {
            case 1: {
                cout << "Nombre: ";
                string nombre = leerString();

                cout << "ID: ";
                int id = leerInt();

                clientes.insertarFinal(new Cliente(nombre, id));
                cout << "\n[!] Cliente registrado con exito.\n";
                pausar();
                break;
            }
            case 2: {
                cout << "ID a buscar: ";
                int id = leerInt();

                Cliente* c = buscarCliente(clientes, id);

                if (c) {
                    cout << "\n--- CLIENTE ENCONTRADO ---\n";
                    cout << c->to_String() << endl;
                } else {
                    cout << "\n[X] Error: Cliente no encontrado.\n";
                }
                pausar();
                break;
            }
            case 3: {
                cout << "\n--- LISTA DE CLIENTES ---\n";
                clientes.mostrarDatos();
                pausar();
                break;
            }
            case 0:
                break;
            default:
                cout << "\n[X] Opcion invalida. Intente de nuevo.\n";
                pausar();
                break;
        }

    } while(op != 0);
}

// ================= PEDIDOS =================

void Menu::menuPedidos(Lista<Producto>& catalogo, Lista<Cliente>& clientes, Lista<Pedido>& pedidos) {

    Pedido* actual = nullptr;
    int op;

    do {
        limpiarPantalla();
        cout << "\n--- PEDIDOS ---\n";


        cout << "1. Nuevo\n2. Agregar producto\n3. Ver\n4. Pagar\n0. Volver\n";
        cout << "Opcion: ";
        op = leerInt();

        switch (op) {
            case 1: {
                cout << "ID Pedido: ";
                int id = leerInt();

                if (buscarPedido(pedidos, id) != nullptr) {
                    cout << "\n[X] Error: Ya existe un pedido con ese ID.\n";
                    pausar();
                    break;
                }

                cout << "ID Cliente: ";
                int idC = leerInt();

                Cliente* c = buscarCliente(clientes, idC);

                if (!c) {
                    cout << "\n[X] Error: El cliente no existe.\n";
                } else {
                    actual = new Pedido(id, c);
                    pedidos.insertarFinal(actual);
                    cout << "\n[!] Pedido creado exitosamente.\n";
                }
                pausar();
                break;
            }
            case 2: {
                cout << "\nIngrese el ID del pedido al que desea agregar productos: ";
                int idBuscado = leerInt();

                actual = buscarPedido(pedidos, idBuscado);

                if (actual) cout << "[INFO: Trabajando en el Pedido ID " << actual->get_num_pedido() << "]\n\n";

                if (!actual) {
                    cout << "\n[X] Error: Pedido no encontrado.\n";
                    pausar();
                    break;
                }

                if (actual->get_estado() == "Pagado") {
                    cout << "\n[X] Error: No se pueden agregar productos a un pedido que ya fue pagado.\n";
                    pausar();
                    break;
                }

                cout << "\n--- CATALOGO DISPONIBLE ---\n";
                catalogo.mostrarDatos();

                cout << "\nCodigo del producto a agregar: ";
                int cod = leerInt();

                Producto* base = buscarProducto(catalogo, cod);

                if (!base) {
                    cout << "\n[X] Error: Producto no encontrado.\n";
                } else {
                    Producto* personalizado = personalizarProducto(base);
                    actual->agregar_producto(personalizado);
                    cout << "\n[!] Producto agregado al pedido " << actual->get_num_pedido() << ".\n";
                }
                pausar();
                break;
            }
            case 3: {
                pedidos.mostrarDatos();


                cout << "\nIngrese el ID del pedido que desea ver: ";
                int idBuscado = leerInt();

                actual = buscarPedido(pedidos, idBuscado);

                if (actual) cout << "[INFO: Trabajando en el Pedido ID " << actual->get_num_pedido() << "]\n\n";

                if (!actual) {
                    cout << "\n[X] Error: Pedido no encontrado.\n";
                } else {
                    cout << "\n--- DETALLE DEL PEDIDO " << actual->get_num_pedido() << " ---\n";
                    cout << actual->toString() << endl;
                }
                pausar();
                break;
            }
            case 4: {
                cout << "\nIngrese el ID del pedido que desea pagar: ";
                int idBuscado = leerInt();

                actual = buscarPedido(pedidos, idBuscado);

                if (actual) cout << "[INFO: Trabajando en el Pedido ID " << actual->get_num_pedido() << "]\n\n";

                if (!actual) {
                    cout << "\n[X] Error: Pedido no encontrado.\n";
                    pausar();
                    break;
                }

                if (actual->get_estado() == "Pagado") {
                    cout << "\n[X] Error: Este pedido ya se encuentra cancelado.\n";
                    pausar();
                    break;
                }

                cout << "\n--- APLICAR DESCUENTO ---\n";
                cout << "1. Sin Descuento\n";
                cout << "2. Porcentaje (Ej. 15 para 15%)\n";
                cout << "3. Cupon Fijo (Ej. 2000)\n";
                cout << "Seleccione opcion: ";
                int opcDesc = leerInt();

                switch (opcDesc) {
                    case 1: {
                        actual->aplicarDescuento(new SinDescuento());
                        cout << "\n[!] Sin descuento aplicado.\n";
                        break;
                    }
                    case 2: {
                        cout << "Ingrese el porcentaje de descuento: ";
                        double porc = leerDouble();
                        actual->aplicarDescuento(new PorcentajeDescuento(porc));
                        cout << "\n[!] Descuento por porcentaje (" << porc << "%) aplicado.\n";
                        break;
                    }
                    case 3: {
                        cout << "Ingrese el monto del cupon: ";
                        double monto = leerDouble();
                        actual->aplicarDescuento(new CuponDescuento(monto));
                        cout << "\n[!] Cupon de descuento (c" << monto << ") aplicado.\n";
                        break;
                    }
                    default: {
                        cout << "\n[X] Opcion de descuento invalida. Operacion cancelada.\n";
                        pausar();
                        continue;
                    }
                }

                MetodoPago* pago = nullptr;

                try {
                    double total = actual->calcularTotal();
                    cout << "\nTotal a pagar (con descuentos aplicados): " << total << endl;

                    cout << "\n--- METODO DE PAGO ---\n";
                    cout << "1. Efectivo  2. Tarjeta  3. Digital\nSeleccione metodo: ";
                    int tipo = leerInt();

                    switch (tipo) {
                        case 1: {
                            cout << "Monto entregado: ";
                            pago = new PagoEfectivo(leerDouble());
                            break;
                        }
                        case 2: {
                            pago = new PagoTarjeta("123", "Cliente");
                            break;
                        }
                        case 3: {
                            pago = new PagoEspecial("SINPE");
                            break;
                        }
                        default: {
                            throw runtime_error("Opcion de pago invalida. Operacion cancelada.");
                        }
                    }

                    actual->cobrarPedido(pago);
                    cout << "\n[!] Pago procesado con exito. Estado actualizado a 'Pagado'.\n";

                    actual = nullptr;
                }
                catch (const runtime_error& e) {
                    cout << "\n[ERROR] " << e.what() << endl;
                }

                if (pago != nullptr) {
                    delete pago;
                }

                pausar();
                break;
            }
            case 0:
                break;
            default:
                cout << "\n[X] Opcion invalida. Intente de nuevo.\n";
                pausar();
                break;
        }

    } while(op != 0);
}

// ================= ARCHIVOS =================

void Menu::menuArchivos(Lista<Pedido>& pedidos, Lista<Producto>& catalogo) {
    int op;

    do {
        limpiarPantalla();
        cout << "\n--- ARCHIVOS ---\n";
        cout << "1. Guardar productos\n";
        cout << "2. Cargar productos\n";
        cout << "3. Guardar pedidos\n";
        cout << "4. Cargar pedidos\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        op = leerInt();

        switch (op) {
            case 1: {
                try {
                    Nodo<Producto>* aux = catalogo.getPrimerNodo();

                    if (aux == nullptr) {
                        cout << "[!] No hay productos en el catalogo ára guardar" << endl;
                        pausar();
                        break;
                    }

                    while (aux) {
                        GestorArchivos::guardarProducto(aux->getDato());
                        aux = aux->getSiguiente();
                    }

                    cout << "\n[!] Productos guardados exitosamente.\n";
                } catch (ArchivoNoEncontradoException& e) {
                    cout << "\n[X] Error de archivo: " << e.what() << endl;
                } catch (const runtime_error& e) {
                    cout << "\n[ERROR INESPERADO]: " << e.what() << endl;
                }
                pausar();
                break;
            }
            case 2: {
                try {
                    GestorArchivos::cargarProductos(catalogo);
                    cout << "\n[!] Productos cargados:\n\n";
                    catalogo.mostrarDatos();
                } catch (ArchivoNoEncontradoException& e) {
                    cout << "\n[X] Error de archivo: " << e.what() << endl;
                    cout << "Verifique que el archivo 'productos.txt' existe.\n";
                } catch (const runtime_error& e) {
                    cout << "\n[ERROR INESPERADO]: " << e.what() << endl;
                }
                pausar();
                break;
            }
            case 3: {
                try {
                    Nodo<Pedido>* aux = pedidos.getPrimerNodo();

                    if (aux == nullptr) {
                        cout << "\n No hay pedidos para guardar...\n";
                        pausar();
                        break;
                    }

                    while (aux) {
                        GestorArchivos::guardarPedido(aux->getDato());
                        aux = aux->getSiguiente();
                    }

                    cout << "\n[!] Productos guardados exitosamente.\n";
                } catch (ArchivoNoEncontradoException& e) {
                    cout << "\n[X] Error de archivo: " << e.what() << endl;
                } catch (const runtime_error& e) {
                    cout << "\n[ERROR INESPERADO]: " << e.what() << endl;
                }
                pausar();
                break;
            }
            case 4: {
                try {
                    GestorArchivos::cargarPedidos(pedidos);
                    cout << "\n[!] Pedidos cargados:\n\n";
                    pedidos.mostrarDatos();
                } catch (ArchivoNoEncontradoException& e) {
                    cout << "\n[X] Error de archivo: " << e.what() << endl;
                    cout << "[!] Verifique que el archivo 'pedidos.txt' existe.\n";
                } catch (const runtime_error& e) {
                    cout << "\n[ERROR INESPERADO]: " << e.what() << endl;
                }
                pausar();
                break;
            }
            case 0:
                break;
            default:
                cout << "\n[X] Opcion invalida. Intente de nuevo.\n";
                pausar();
                break;
        }

    } while(op != 0);
}