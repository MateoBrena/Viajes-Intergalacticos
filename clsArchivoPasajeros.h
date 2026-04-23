#ifndef CLSARCHIVOPASAJEROS_H_INCLUDED
#define CLSARCHIVOPASAJEROS_H_INCLUDED

#include "clsPasajeros.h"

class ArchivoPasajeros {
    private:
        char nombre[30];
    public:
        ArchivoPasajeros(const char *n = "Pasajeros.dat");
        Pasajero leerRegistro(int);
        bool grabarRegistro(Pasajero);
        bool modificarRegistro(Pasajero, int);
        int contarRegistros();
        int buscarRegistro(int);
        void listarRegistros();
        void altaPasajero();
        void buscarPorId();
        void modificarNombre();
};

#endif // CLSARCHIVOPASAJEROS_H_INCLUDED
