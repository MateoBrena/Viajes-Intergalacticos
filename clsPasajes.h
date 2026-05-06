#ifndef CLSPASAJES_H_INCLUDED
#define CLSPASAJES_H_INCLUDED

#include "clsFecha.h"

class Pasajes{
    private:
        int idPasaje;
        int idPasajero;
        int idViaje;
        Fecha fechaCompra;
        bool estado;
    public:
        Pasajes(int idP=-1, int idPj=-1, int idV=-1, Fecha fc=Fecha());
        void setIdPasaje(int dPj);
        void setIdPasajero(int idP);
        void setIdViaje(int idV);
        void setFechaCompra(Fecha fC);
        void setEstado(bool e);
        int getIdPasaje();
        int getIdPasajero();
        int getIdViaje();
        Fecha getFechaCompra();
        bool getEstado();
        void Cargar(int dPj, int idP, int idV);
        void Mostrar();
};

#endif // CLSPASAJES_H_INCLUDED
