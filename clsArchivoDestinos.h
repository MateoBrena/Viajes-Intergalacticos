#ifndef CLSARCHIVODESTINOS_H_INCLUDED
#define CLSARCHIVODESTINOS_H_INCLUDED

#include "clsDestinos.h"

class ArchivoDestinos {
    private:
        char nombre[30];
    public:
        ArchivoDestinos(const char *n = "Destinos.dat");
        Destinos leerRegistro(int);
        bool grabarRegistro(Destinos);
        bool modificarRegistro(Destinos, int);
        int contarRegistros();
        int buscarRegistro(int);
        void listarRegistros();
        void altaDestino();
        void buscarPorId();
};

#endif // CLSARCHIVODESTINOS_H_INCLUDED
