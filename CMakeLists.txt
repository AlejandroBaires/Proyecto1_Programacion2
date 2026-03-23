cmake_minimum_required(VERSION 4.1)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto1 main.cpp
        Producto.h
        Comida.cpp
        Comida.h
        Postre.cpp
        Postre.h
        Bebida.cpp
        Bebida.h
        MetodoPago.cpp
        MetodoPago.h
        PagoTarjeta.cpp
        PagoTarjeta.h
        PagoEfectivo.cpp
        PagoEfectivo.h
        PagoEspecial.cpp
        PagoEspecial.h
)
