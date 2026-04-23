#ifndef CLSPASAJES_H_INCLUDED
#define CLSPASAJES_H_INCLUDED

class Pasajes{
    private:
        int idPasaje;
        int idPasajero;
        int idViaje;
    public:
        Pasajes(int idP=0, int idPj=0, int idV=0);
        void setIdPasaje(int dPj);
        void setIdPasajero(int idP);
        void setIdViaje(int idV);
        int getIdPasaje();
        int getIdPasajero();
        int getIdViaje();
        void Cargar(int dPj, int idP, int idV);
        void Mostrar();
};

#endif // CLSPASAJES_H_INCLUDED
