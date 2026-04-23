#ifndef CLSVIAJES_H_INCLUDED
#define CLSVIAJES_H_INCLUDED

class Viajes {
    private:
        int idViaje;
        int idCapitan;
        int idDestino;
        int tiempoViaje;
    public:
        Viajes(int id=0, int idC=0, int idD=0, int tV=0);
        void setIdViaje(int id);
        void setIdCapitan(int idC);
        void setIdDestino(int idD);
        void setTiempoViaje(int tV);
        int getIdViaje();
        int getIdCapitan();
        int getIdDestino();
        int getTiempoViaje();
        void Cargar(int id, int idC, int idD);
        void Mostrar();

};

#endif // CLSVIAJES_H_INCLUDED
