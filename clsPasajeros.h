#ifndef CLSPASAJEROS_H_INCLUDED
#define CLSPASAJEROS_H_INCLUDED

#include "clsFecha.h"

class Pasajero {
    private:
        int idInt;
        char nombre[50];
        char apellido[50];
        Fecha fechaNacimiento;
        int nivelCiudadania;
        bool estado;
    public:
        Pasajero(int d=0, const char *n="Nn", const char *a="Aa", Fecha fN=Fecha(), int nC=1);
        void setIdInt(int d);
        void setNombre(const char *n);
        void setApellido(const char *a);
        void setFechaNacimiento(Fecha fechaNac);
        void setNivCiudadania(int n);
        void setEstado(bool e);
        int getIdInt();
        const char *getNombre();
        const char *getApellido();
        Fecha getFechaNacimiento();
        int getNivelCiudadania();
        bool getEstado();
        void Cargar(int id);
        void Mostrar();

};

#endif // CLSPASAJEROS_H_INCLUDED
