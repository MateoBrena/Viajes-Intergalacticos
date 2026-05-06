#ifndef CLSVIAJES_H_INCLUDED
#define CLSVIAJES_H_INCLUDED

class Viajes {
    private:
        int idViaje;
        int idCapitan;
        int idDestino;
        int tiempoViaje;
        bool estado;
    public:
        Viajes(int id=-1, int idC=-1, int idD=-1, int tV=0);
        void setIdViaje(int id);
        void setIdCapitan(int idC);
        void setIdDestino(int idD);
        void setTiempoViaje(int tV);
        void setEstado(bool e);
        int getIdViaje();
        int getIdCapitan();
        int getIdDestino();
        int getTiempoViaje();
        bool getEstado();
        void Cargar(int id, int idC, int idD);
        void Mostrar();

};

#endif // CLSVIAJES_H_INCLUDED
