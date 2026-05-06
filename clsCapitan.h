#ifndef CLSCAPITAN_H_INCLUDED
#define CLSCAPITAN_H_INCLUDED

#include "clsFecha.h"

class Capitan {
    private:
        int idInt;
        char nombre[50];
        char apellido[50];
        Fecha fechaNacimiento;
        int rango;
        bool estado;
    public:
        Capitan(int d=0, const char *n="Nn", const char *a="Aa", Fecha fN=Fecha(), int r=1);
        void setIdInt(int id);
        void setNombre(const char *n);
        void setApellido(const char *a);
        void setFechaNacimiento(Fecha fechaNac);
        void setRango(int r);
        void setEstado(bool e);
        int getIdInt();
        const char *getNombre();
        const char *getApellido();
        Fecha getFechaNacimiento();
        int getRango();
        bool getEstado();
        void Cargar(int id);
        void Mostrar();

};

#endif // CLSCAPITAN_H_INCLUDED
