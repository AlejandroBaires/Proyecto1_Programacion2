//
// Created by ahara on 4/4/2026.
//

#ifndef PROYECTO1_ARCHIVONOENCONTRADOEXCEPTION_H
#define PROYECTO1_ARCHIVONOENCONTRADOEXCEPTION_H
#include <stdexcept>
using namespace std;

// Cuando el archivo no existe o fue renombrado

class ArchivoNoEncontradoException : public runtime_error {
    public:
    ArchivoNoEncontradoException(const string& nombreArchivo)
        : runtime_error("Archivo no encontrado: " + nombreArchivo){};
};

#endif //PROYECTO1_ARCHIVONOENCONTRADOEXCEPTION_H