cmake_minimum_required(VERSION 4.1)
project(Proyecto1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto1
        main.cpp

        "identidades h/Producto.h"


        "identidades cpp/Comida.cpp" "identidades h/Comida.h"
        "identidades cpp/Postre.cpp" "identidades h/Postre.h"
        "identidades cpp/Bebida.cpp" "identidades h/Bebida.h"

        "identidades cpp/MetodoPago.cpp" "identidades h/MetodoPago.h"
        "identidades cpp/PagoTarjeta.cpp" "identidades h/PagoTarjeta.h"
        "identidades cpp/PagoEfectivo.cpp" "identidades h/PagoEfectivo.h"
        "identidades cpp/PagoEspecial.cpp" "identidades h/PagoEspecial.h"

        "identidades cpp/ProductoDecorador.cpp" "identidades h/ProductoDecorador.h"
        "identidades cpp/SinIngrediente.cpp" "identidades h/SinIngrediente.h"
        "identidades cpp/CambioTammano.cpp" "identidades h/CambioTammano.h"
        "identidades h/ProductoDecorador.h"
        "identidades cpp/IngredienteExtra.cpp" "identidades h/IngredienteExtra.h"
        "identidades cpp/Cliente.cpp"
        "identidades h/Cliente.h"
        "T Lista simple/Lista.h"
        "identidades cpp/Producto.cpp"

)
