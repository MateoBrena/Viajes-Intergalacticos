#ifndef CLSARCHIVOVIAJES_H_INCLUDED
#define CLSARCHIVOVIAJES_H_INCLUDED

#include "clsViajes.h"

class ArchivoViajes {
    private:
        char nombre[30];
    public:
        ArchivoViajes(const char *n = "Viajes.dat");
        Viajes leerRegistro(int);
        bool grabarRegistro(Viajes);
        bool modificarRegistro(Viajes, int);
        int contarRegistros();
        int buscarRegistro(int);
        void listarRegistros();
        void altaViaje();
        void buscarPorId();
};

#endif // CLSARCHIVOVIAJES_H_INCLUDED
