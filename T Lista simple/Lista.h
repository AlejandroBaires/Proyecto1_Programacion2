//
// Created by ahara on 25/3/2026.
//

#ifndef HELLO_WORLD_LISTA_H
#define HELLO_WORLD_LISTA_H
#include "Nodo.h"

/*  Para utilizar esta libreria, hay que sobrecargar si o si el operador " == ",
 *  ya que los métodos de busqueda y eliminación son completamente genericos.
 *  Entonces utilizan este operador para hacer las cosas más sencillas y genericas
 *  posibles, como recomendación, utilizar caracteristicas unicas para la distinción
 *  de los objetos a guardar, por ejemplo para la comparación entre Clientes se puede
 *  sobrecargar de forma que se les compare por el id, o poniendo otro ejemplo para
 *  los Productos, se puede sobrecargar de forma que compare un codigo de serie o
 *  el mismo numero del producto.
 */

template <class T>
class Lista {
private:
    Nodo<T> *primero;
    int cantidad;

    //MÉTODOS PRIVADOS
    void eliminar() {
        Nodo<T>* aux = primero;

        while (aux != nullptr) {
            Nodo<T>* eliminar = aux;
            aux = aux->getSiguiente();
            delete eliminar->getDato();
            delete eliminar;
        }

        primero = nullptr;
        cantidad = 0;
    }

public:
    Lista(): primero(nullptr), cantidad(0){}
    ~Lista(){eliminar();}

    //Copy Constructor
    Lista(const Lista<T>& otra) : primero(nullptr), cantidad(0) {
        Nodo<T>* aux = otra.primero;
        while (aux != nullptr) {
            //copia profunda, crea nuevos nodos con nuevos datos
            T* copia = new T(aux->getDato());
            insertarInicio(copia);
            aux = aux->getSiguiente();
        }
    }

    //MÉTODOS BASICOS DE UNA LISTA
    bool insertarInicio(T * dato) {
        //Comprobación de que el dato no sea nulo
        if (dato == nullptr) return false;

        //si el dato no es nulo entonces;
        primero = new Nodo<T>(dato, primero);
        cantidad++;
        return true;
    }

    bool insertarFinal(T * dato) {
        //Comprobación de que el dato no sea nulo
        if (dato == nullptr) return false;

        //verificar que la lista este vacia, y si lo esta entonces;
        if (estaVacio()) {
            return insertarInicio(dato);
        }

        Nodo<T>* aux = primero;
        while (aux->getSiguiente() != nullptr) {
            aux = aux->getSiguiente();
        }

        Nodo<T>* nuevo = new Nodo<T>(dato);
        aux->setSiguiente(nuevo);
        cantidad++;
        aux = nullptr;
        return true;
    }

    T* BuscarDato(T * dato) {
        Nodo<T>* aux = primero;

        while (aux != nullptr) {
            if (*aux->getDato() == *dato) {
                return aux->getDato();
            }
            aux = aux->getSiguiente();
        }
        return nullptr;
    }

    bool eliminarDato(T * dato) {
        if (estaVacio()) return false;                          //1

        if (*primero->getDato() == *dato) {                     //2
            Nodo<T>* eliminar = primero;
            primero = primero->getSiguiente();

            delete eliminar->getDato();
            delete eliminar;
            cantidad--;
            return true;
        }

        Nodo<T>* temp = primero;                                //3
        while (temp->getSiguiente() != nullptr) {
            if (*temp->getSiguiente()->getDato() == *dato) {
                Nodo<T>* eliminar = temp->getSiguiente();
                temp->setSiguiente(eliminar->getSiguiente());
                delete eliminar->getDato();
                delete eliminar;
                cantidad--;
                return true;
            }
            temp = temp->getSiguiente();
        }
        return false;
    }

    void mostrarDatos() {
        if (estaVacio()) {
            return;
        }
        Nodo<T>* aux = primero;
        while (aux != nullptr) {
            cout << *aux->getDato() << endl;
            aux = aux->getSiguiente();
        }
        cout << endl;
    }

    Nodo<T> * getPrimerNodo() {
        if (primero == nullptr) {
            return nullptr;
        }
        return primero;
    }


    //MÉTODOS UTILES DE LA LISTA
    bool estaVacio() {
        return cantidad == 0;
    }

    int getCantidad() {
        return cantidad;
    }

    //Sobrecarga de operadores
    Lista<T>& operator=(const Lista<T>& otra) {
        if (this == &otra) return *this;        //evitar auto-asignacion
        eliminar();                             //limpia lo que habia antes

        Nodo<T>* aux = otra.primero;
        while (aux != nullptr) {
            T* copia = new T(*aux->getDato());
            insertarInicio(copia);
            aux = aux->getSiguiente();
        }
        return *this;
    }
};
#endif //HELLO_WORLD_LISTA_H