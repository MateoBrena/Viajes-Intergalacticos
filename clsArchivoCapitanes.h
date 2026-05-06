#ifndef CLSARCHIVOCAPITANES_H_INCLUDED
#define CLSARCHIVOCAPITANES_H_INCLUDED

#include "clsCapitan.h"

class ArchivoCapitanes {
    private:
        char nombre[30];
    public:
        ArchivoCapitanes(const char *n = "Capitanes.dat");
        Capitan leerRegistro(int);
        bool grabarRegistro(Capitan);
        bool modificarRegistro(Capitan, int);
        int contarRegistros();
        int buscarRegistro(int);
        void listarRegistros();
        void altaCapitan();
        void buscarPorId();
        void modificarNombre();
        void modificarApellido();
        void modificarFechaNacimiento();
        void modificarRango();
        void bajaCapitan();
};

#endif // CLSARCHIVOCAPITANES_H_INCLUDED
