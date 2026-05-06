#ifndef CLSDESTINOS_H_INCLUDED
#define CLSDESTINOS_H_INCLUDED

class Destinos {

    private:
        int idDestino;
        char nombre[50];
        int distancia;
        bool estado;
    public:
        Destinos();
        void setIdDest(int id);
        void setNombre(const char* n);
        void setDistancia(int d);
        void setEstado(bool e);
        int getIdDest();
        const char *getNombre();
        int getDistancia();
        bool getEstado();
        void Cargar(int id);
        void Mostrar();
};

#endif // CLSDESTINOS_H_INCLUDED
