#ifndef CLSARCHIVOPASAJES_H_INCLUDED
#define CLSARCHIVOPASAJES_H_INCLUDED

#include "clsPasajes.h"

class ArchivoPasajes {
    private:
        char nombre[30];
    public:
        ArchivoPasajes(const char *n = "Pasajes.dat");
        Pasajes leerRegistro(int);
        bool grabarRegistro(Pasajes);
        bool modificarRegistro(Pasajes, int);
        int contarRegistros();
        int buscarRegistro(int);
        void listarRegistros();
        void altaPasaje();
        void buscarPorId();
        //void modificarIdPasajero();
        //void modificarIdViaje();
        //void modificarFechaCompra();
        void bajaPasaje();
};

#endif // CLSARCHIVOPASAJES_H_INCLUDED
